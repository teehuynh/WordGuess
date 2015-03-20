#include <iostream>
#include <string>

using namespace std;

bool check_word(string);
bool check_letter(char);
void available_letters(string &, char);
void checkStatus(string, string, string &);
bool playAgain(char, string&, string&);

int main() {
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string secret_word;
	string word_dash;
	string letter_missing;
	int num_guesses;
	char letter_guess;
	char answer = ' ';

	do{
		word_dash = "";
		cout << "Player 1, please enter the secret word (only letters): ";
		cin >> secret_word;

		if(check_word(secret_word)) 
		{
			cout << "Enter number of guesses allowed: ";
			cin >> num_guesses;

			for(int i = 0; i < secret_word.length(); i++) { //prints out the number of '-' for the secret word
				word_dash += '-';
			}
		
			while(num_guesses > 0 && word_dash != secret_word)
			{
				bool letter_found = false;
			
				cout << "You currently have " << num_guesses << " guesses left." << endl;
				cout << "The secret word currently looks like this: " << word_dash << endl;
				cout << "\nPlease enter a letter: ";
				cin >> letter_guess;
				tolower(letter_guess);
				if(check_letter(letter_guess)) 
				{//checks to see if the guess is a character
					for(int i = 0; i < secret_word.length(); i++) 
					{
						if(letter_guess == secret_word.at(i)) 
						{
							word_dash.at(i) = letter_guess; //sets the letter to the appropriate spot of the secret word
							letter_found = true;
						}
					}

					if(!letter_found)
					{
						cout << "Sorry that letter was not in the secret word.  Try again. " << endl;
						num_guesses--; //decretments number of guesses if guessed the wrong letter
					}

					available_letters(alphabet, letter_guess);
				}
				else 
				{
					cout << "That is not a valid entry because only letters are allowed!" << endl;
				}

			}//end while

			checkStatus(word_dash, secret_word, letter_missing);

		}// end if
		else
		{
			cout << "This has spaces or non letter.  Please enter a letter" << endl;
		}

	}while(playAgain(answer, alphabet, letter_missing));

	system("pause");
	return 0;
}

bool check_word(string secretWord) 
{//returns false if there is anything other than letters in the string including spaces
	for(int i = 0; i < secretWord.length(); i++) 
	{
		if(isalpha(secretWord.at(i)) == 0 || isspace(secretWord.at(i)) != 0)//checks to see if there letters and spaces in the string
			return false;
	}
	return true;
}

bool check_letter(char letter) { //returns true if it is a letter
	return isalpha(letter);
}

void available_letters(string &alpha, char letterGuess) { //takes in a reference of the alphabet variable which contains the entire alphabet and adds a '-' for the letters guessed by user
	for(int i = 0 ; i < alpha.length(); i++) {
		if(letterGuess == alpha.at(i)) {
			alpha.at(i) = '-';
		}
	}
	cout << "The available letters are: " << alpha << endl;
}

void checkStatus(string guessedWord, string secretWord, string &missingLetters) {
	if(guessedWord == secretWord)
		cout << "You found the word! Congratulations you win!" << endl;
	else
	{
		cout << "You lose!" << endl;
		for(int i = 0; i < secretWord.length(); i++)
		{
			if(secretWord.at(i) != guessedWord.at(i))
			{
				missingLetters += secretWord.at(i);
			}
		}
		cout << "The letters missing were: ";

		for(int i = 0; i < missingLetters.length(); i++)
		{
			cout << missingLetters.at(i) << " ";
		}
		cout << endl;
		cout << "The secret word was: " << secretWord << endl;
	}
}

bool playAgain(char ans, string &alpha, string & missing) {
	cout << "Would you like to play again?(y/n)" << endl;
	cin >> ans;

	if(ans == 'y' || ans == 'Y')
	{
		missing = "";
		alpha = "abcdefghijklmnopqrstuvwxyz";
		return true;
	}
	else
	{
		cout << "Thanks for playing!" << endl;
		return false;
	}
}