#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

void Code(int* code1, int* code2, int* code3, int* code4)
{
	*code1 = 1 + rand() % 6;
	*code2 = 1 + rand() % 6;
	*code3 = 1 + rand() % 6;
	*code4 = 1 + rand() % 6;
}

enum {
	PEG_NO_MATCH,
	PEG_BLACK,
	PEG_WHITE,
};

int main()
{
	srand(time(0));
	int i = 0;
	int code[4];
	int guess[4];
	int match[4];
	int code1 = 0;
	int code2 = 0;
	int code3 = 0;
	int code4 = 0;
	int selection1;
	bool menu = true;

	cout << "Mastermind!" << endl;

	while (menu) {
		cout << "1) Play" << endl;
		cout << "2) Rules" << endl;
		cout << "3) Exit" << endl;
		cout << "Enter a selection: ";
		cin >> selection1;

		switch (selection1)
		{
		case 1:
		{
			Code(&code1, &code2, &code3, &code4);
			code[0] = code1;
			code[1] = code2;
			code[2] = code3;
			code[3] = code4;
			cout << endl << "Crack the code!" << endl;

			for (int attempt = 1; attempt < 11; ++attempt)
			{
				int i = 0;
				cout << endl << "Attempt " << attempt << " - " << "Enter your guesses for the code." << endl;
				do
				{
					cout << "Digit " << (i + 1) << ": ";
					cin >> guess[i];
					if (guess[i] < 1 || guess[i] > 6)
						cout << "Invalid digit. Enter a number from 1-6." << endl;
					else
						i += 1;
				} while (i < 4);

				cout << endl << "Your guess: ";
				for (i = 0; i < 4; ++i)
				{
					cout << guess[i];
				}
				cout << endl;
				int CorrectPos = 0;
				for (i = 0; i < 4; ++i)
				{
					if (guess[i] == code[i])
					{
						CorrectPos++;
						match[i] = PEG_BLACK;
					}
					else match[i] = PEG_NO_MATCH;
				}
				cout << endl;
				if (attempt == 10 && CorrectPos < 4)
				{
					cout << "Sorry! The code was ";
					for (i = 0; i < 4; ++i)
					{
						cout << code[i];
					}
					cout << endl << "Better luck next time!" << endl << endl;
					break;
				}
				else if (CorrectPos == 4)
				{
					cout << "CONGRATULATIONS! You cracked the code!" << endl;
					break;
				}
				else if (CorrectPos == 3)
					cout << "Three numbers are in the right position." << endl;
				else if (CorrectPos == 2)
					cout << "Two numbers are in the right position." << endl;
				else if (CorrectPos == 1)
					cout << "One number is in the right position." << endl;

				int CorrectNum = 0;
				for (int i = 0; i < 4; i++)
				{
					if (match[i] != PEG_BLACK)
					{
						for (int k = 0; k < 4; k++)
						{
							if ((i != k) && (match[k] == PEG_NO_MATCH) && (guess[i] == code[k]))
							{
								match[k] = PEG_WHITE;
								CorrectNum++;
								break;
							}
						}
					}
				}

				if (CorrectNum == 4)
					cout << "All numbers are in the code, but in the wrong position." << endl;
				else if (CorrectNum == 3)
					cout << "Three numbers are in the code, but in the wrong position." << endl;
				else if (CorrectNum == 2)
					cout << "Two numbers are in the code, but in the wrong position." << endl;
				else if (CorrectNum == 1)
					cout << "One number is in the code, but in the wrong position." << endl;
			}
			break;
		}
		case 2:
		{
			cout << "=============================================================" << endl;
			cout << endl << "In Mastermind, your only object is to: Crack the Code!" << endl << endl;
			cout << "When the game starts, a randomized code will be created, made up of 4 digits, with each digit ranging from 1-6." << endl;
			cout << "Type in your guesses for what you think each digit is, then press Enter." << endl;
			cout << "Clues will be given to you depending on if your guesses matched the code or not." << endl;
			cout << "You can use these clues to help you with deciphering the code!" << endl << endl;
			cout << "If you crack the code in 10 attempts or lower, you win!" << endl << endl;
			cout << "=============================================================" << endl;
			break;
		}
		default:
			cout << "Exiting..." << endl;
			return selection1;
		}
	}
}