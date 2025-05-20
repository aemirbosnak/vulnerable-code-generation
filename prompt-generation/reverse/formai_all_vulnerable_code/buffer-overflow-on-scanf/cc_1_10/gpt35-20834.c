//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

/*
Sherlock Holmes' Secure Password Generator
Written by a_pessimist7
*/

/*
This program generates secure passwords in the style of Sherlock Holmes
to keep your online accounts safe. It uses a combination of upper and lower case letters,
numbers and symbols to create a unique password that is hard to crack.
*/

#define MINIMUM_LENGTH 8
#define MAXIMUM_LENGTH 20

char randomCharacter(int type);
int randomNumber(int max);
bool isCharacterType(char c, int type);

int main(void) {

    int passwordLength = 0;
    int numberOfSpecialCharacters = 0;
    int numberOfNumbers = 0;

    //Prompt user for password length
    printf("What length should the password be? (minimum %d, maximum %d): ", MINIMUM_LENGTH, MAXIMUM_LENGTH);
    scanf("%d", &passwordLength);

    //Validate password length
    if(passwordLength < MINIMUM_LENGTH || passwordLength > MAXIMUM_LENGTH) {
        printf("Invalid password length.\n");
        return -1;
    }

    //Prompt user for number of special characters
    printf("How many special characters should the password have? (minimum 1): ");
    scanf("%d", &numberOfSpecialCharacters);

    //Validate number of special characters
    if(numberOfSpecialCharacters < 1) {
        printf("Invalid number of special characters.\n");
        return -1;
    }

    //Prompt user for number of numbers
    printf("How many numbers should the password have? (minimum 1): ");
    scanf("%d", &numberOfNumbers);

    //Validate number of numbers
    if(numberOfNumbers < 1) {
        printf("Invalid number of numbers.\n");
        return -1;
    }

    //Seed the random number generator
    srand(time(NULL));

    //Generate password
    char password[MAXIMUM_LENGTH + 1] = {0}; //Initialize all characters to null
    int characterTypes[MAXIMUM_LENGTH] = {0};
    int numNeededCharacters = passwordLength - numberOfSpecialCharacters - numberOfNumbers;
    int index = 0;

    //Assign special characters to password
    for(int i = 0; i < numberOfSpecialCharacters; i++) {
        password[i] = randomCharacter(1); //Assign special character type (1)
        characterTypes[i] = 1;
    }

    //Assign numbers to password
    for(int i = 0; i < numberOfNumbers; i++) {
        while(!isCharacterType(password[index], 0)) { //Skip special character or digit already assigned
            index++;
        }
        password[index] = randomCharacter(2); //Assign digit type (2)
        characterTypes[index] = 2;
    }

    //Assign remaining characters to password
    for(int i = 0; i < numNeededCharacters; i++) {
        while(!isCharacterType(password[index], 0)) { //Skip special character or digit already assigned
            index++;
        }
        password[index] = randomCharacter(0); //Assign letter type (0)
        characterTypes[index] = 0;
    }

    //Shuffle password array
    for(int i = passwordLength-1; i > 0; i--) {
        int j = randomNumber(i+1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    //Output password
    printf("\nYour secure password is:\n");
    for(int i = 0; i < passwordLength; i++) {
        printf("%c", password[i]);
    }
    printf("\n\nCharacter types for the password are:\n");
    for(int i = 0; i < passwordLength; i++) {
        printf("%d ", characterTypes[i]);
    }
    printf("\n");

    return 0;
}

//Random character generator
char randomCharacter(int type) {
    char c;
    switch(type) {
        case 0: //Letter
            c = (char)randomNumber(26) + 'a';
            if(randomNumber(2)) {
                c = toupper(c);
            }
            break;
        case 1: //Special character
            switch(randomNumber(4)) {
                case 0:
                    c = '!';
                    break;
                case 1:
                    c = '@';
                    break;
                case 2:
                    c = '#';
                    break;
                case 3:
                    c = '$';
                    break;
                case 4:
                    c = '%';
                    break;
                default:
                    c = '!';
                    break;
            }
            break;
        case 2: //Digit
            c = (char)randomNumber(10) + '0';
            break;
        default:
            c = '\0';
            break;
    }
    return c;
}

//Random number generator
int randomNumber(int max) {
    return rand() % max;
}

//Type checker for characters
bool isCharacterType(char c, int type) {
    switch(type) {
        case 0: //Letter
            return isalpha(c) && !isdigit(c);
        case 1: //Special character
            return !isalnum(c);
        case 2: //Digit
            return isdigit(c);
        default:
            return false;
    }
}