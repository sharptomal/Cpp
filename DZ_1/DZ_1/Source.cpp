#include <iostream>
#include <cstring>

using namespace std;

class String{
	unsigned size = 0;
	char* str = nullptr;
public:
	String(const char* s){
		if (s&&*s){
			size = strlen(s) + 1;
			str = new char[size];
			strcpy_s(str, size, s);
		}
	};
	~String(){
		if (str)
			delete[]str;
		str = nullptr;
	}
	const char* assign(const char* newstr){ //Замена строки
		if (newstr&&*newstr){
			delete[]str;
			size = strlen(newstr) + 1;
			str = new char[size];
			strcpy_s(str, size, newstr);
		}
		return str;
	}
	const char* take_string(){ //Получение строки
		return str;
	}
	int take_size(){ // Получение размера строки
		return size;
	}
	const char* concat(const char* str_str){ //Склеивание строк
		if (str_str&&*str_str){
			size = strlen(str) + strlen(str_str) + 1;
			char* dopstr = new char[size];
			strcpy_s(dopstr, size, str);
			strcat_s(dopstr, size, str_str);
			delete[]str;
			str = new char[size];
			strcpy_s(str, size, dopstr);
			delete[]dopstr;
		}
		return str;
	}
	const char* add_in_pos(unsigned num, char* c){ //Вставка символа в num позицию строки
		if (num < 1 || num > strlen(str) + 1)
			return str;
		else
		{
			char * anystr = new char[size + 2];
			strncpy_s(anystr, strlen(str) + 2, str, num - 1);
			strcpy_s(anystr + strlen(anystr), size - strlen(anystr) + 2, c);
			strcpy_s(anystr + strlen(anystr), size - strlen(anystr) + 2, str + num - 1);
			delete[] str;
			str = anystr;
			--size;
			return str;
		}
	}
	const char* delete_by_pos(unsigned num){ //Удаление символа из num позиции строки
		num -= 1;
		if (num < 0 || num > strlen(str) - 1)
			return str;
		else{
			char * shorter_str = new char[strlen(str)];
			for (unsigned i = 0; i < strlen(str); ++i){
				if (i<num)
					shorter_str[i] = str[i];
				else if (i >= num)
					shorter_str[i] = str[i + 1];
			}
			str = shorter_str;
			--size;
			return str;
		}
	}
	void ASCII(){ //Перевод в ASCII
		char* Rstr = str;
		while (true){
			printf_s("%c is %d", *str, *str);
			++str;
			if (*str == NULL){
				cout << "." << endl;
				str = Rstr;
				break;
			}
			cout << ", ";
		}
	}
	const char* str_up(){ // Верхний регистр
		return _strupr(str);
	}
	const char* str_low(){ // Нижний регистр
		return _strlwr(str);
	}
};
int main(){
	String S("What do u want");          //1
	cout << S.take_string() << endl;
	S.assign("Anyone");                  //2
	cout << S.take_string() << endl;
	cout << S.take_string() << endl;     //3
	cout << S.take_size() << endl;       //4
	S.concat(" you have");               //5
	cout << S.take_string() << endl;
	S.add_in_pos(7, ",");                //6
	cout << S.take_string() << endl;
	S.delete_by_pos(9);                  //6.1
	cout << S.take_string() << endl;
	S.ASCII();                           //7
	cout << S.str_up() << endl;          //8
	cout << S.str_low() << endl;         //9

	return 0;
};
