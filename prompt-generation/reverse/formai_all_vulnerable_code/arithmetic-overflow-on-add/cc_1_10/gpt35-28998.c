//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// This function generates a random integer between two integers
int getRandomInt(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

// This function returns a random lowercase letter
char getRandomLowercase(){
    return (char)getRandomInt(97, 122);
}

// This function returns a random uppercase letter
char getRandomUppercase(){
    return (char)getRandomInt(65, 90);
}

// This function returns a random digit
char getRandomDigit(){
    return (char)getRandomInt(48, 57);
}

// This function generates a secure password of a specified length
void generatePassword(char *password, int length, int lowerCount, int upperCount, int digitCount, int minLower, int minUpper, int minDigit, int index){
    // Base case: if all characters have been generated
    if(index == length){
        password[index] = '\0';
        return;
    }

    char nextChar;

    // Generate a lowercase character if needed
    if(lowerCount < minLower || (lowerCount < (length - index) && upperCount >= minUpper && digitCount >= minDigit && getRandomInt(0, 1))){
        nextChar = getRandomLowercase();
        password[index] = nextChar;
        generatePassword(password, length, lowerCount + 1, upperCount, digitCount, minLower, minUpper, minDigit, index + 1);
        return;
    }

    // Generate an uppercase character if needed
    if(upperCount < minUpper || (upperCount < (length - index) && lowerCount >= minLower && digitCount >= minDigit && getRandomInt(0, 1))){
        nextChar = getRandomUppercase();
        password[index] = nextChar;
        generatePassword(password, length, lowerCount, upperCount + 1, digitCount, minLower, minUpper, minDigit, index + 1);
        return;
    }

    // Generate a digit if needed
    if(digitCount < minDigit || (digitCount < (length - index) && lowerCount >= minLower && upperCount >= minUpper && getRandomInt(0, 1))){
        nextChar = getRandomDigit();
        password[index] = nextChar;
        generatePassword(password, length, lowerCount, upperCount, digitCount + 1, minLower, minUpper, minDigit, index + 1);
        return;
    }

    // Generate a random character if none of the above conditions are met
    nextChar = (char)getRandomInt(33, 126); // ASCII characters from 33 to 126 are considered printable
    password[index] = nextChar;
    generatePassword(password, length, lowerCount, upperCount, digitCount, minLower, minUpper, minDigit, index + 1);
}

int main(){
    srand(time(NULL));

    int length;
    int minLower;
    int minUpper;
    int minDigit;

    printf("Enter the desired password length: ");
    scanf("%d", &length);

    printf("Enter the minimum number of lowercase letters: ");
    scanf("%d", &minLower);

    printf("Enter the minimum number of uppercase letters: ");
    scanf("%d", &minUpper);

    printf("Enter the minimum number of digits: ");
    scanf("%d", &minDigit);

    char password[length + 1];
    generatePassword(password, length, 0, 0, 0, minLower, minUpper, minDigit, 0);

    printf("Your secure password is: %s\n", password);

    return 0;
}