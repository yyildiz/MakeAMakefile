#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::vector;
using std::ofstream;
using std::ifstream;

int main() {
	string cc, cflags, lflags, source, exe;
	
	if(ifstream("Makefile") || ifstream("makefile") || ifstream("GNUmakefile")) {
		int choice;
		cout << "It looks like a makefile already exists in this directory.\n";
		cout << "What would you like to do\n";
		cout << "0. Overwrite file.\n";
		cout << "1. Exit Program.";
		cin >> choice;
		cin.ignore();
		if(choice != 0) {
			return -1;
		}
	}
	ofstream makefile;
	makefile.open("Makefile");

	cout << "Enter the name of the executable: ";
	std::getline(cin, exe);
	cout << "Enter your compiler ex: 'gcc': ";
	std::getline(cin, cc);
	cout << "Enter Compiler Flags ex. '-g -std=c++11 -Wall -pedantic': ";
	std::getline(cin, cflags);
	cout << "Enter Linker Flags: ex. '-lsfml-system': ";
	std::getline(cin, lflags);
	
	if(cc == "gcc") source = "c";
	else source = "cpp";
	
	makefile << "#Created using Make A Makefile by Yusuf Yildiz - yildizy.com\n";
	makefile << "CC = " << cc << "\nCFLAGS = " << cflags << "\nLFLAGS = " << lflags << "\n";
	makefile << "BIN = " << exe << "\n\n";
	makefile << "SRC = $(wildcard *." << source << ")\nOBJ= $(SRC:%." << source << "=%.o)\n\n";
	makefile << "\nall: $(OBJ)\n\t$(CC) -o $(BIN) $^ " << lflags <<"\n\n";
	makefile << "%.o: %.c\n\t$(CC) $@ -c $<\n\n";
	makefile << "clean:\n\trm -f *.o *~\n\trm $(BIN)";
	
	makefile.close();

	return 0;

}
