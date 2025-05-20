//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

void printHeader() {
    printf("Welcome to Secure Password Generator\n");
    printf("-----------------------------------\n");
}

void printFooter() {
    printf("-----------------------------------\n");
    printf("Please remember to keep your generated password safe!\n");
}

char generateRandomChar() {
    char c;
    int letterOrDigit = rand() % 2;
    if (letterOrDigit == 0) {
        c = 'a' + (rand() % 26);
    } else {
        c = '0' + (rand() % 10);
    }
    return c;
}

int main() {
    srand(time(NULL));
    printHeader();

    int passwordLength = 0;
    while (passwordLength < MIN_PASSWORD_LENGTH || passwordLength > MAX_PASSWORD_LENGTH) {
        printf("How long would you like your password to be? (between %d and %d characters): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        scanf("%d", &passwordLength);
    }

    char password[MAX_PASSWORD_LENGTH + 1];
    for (int i = 0; i < passwordLength; i++) {
        char randomChar = generateRandomChar();
        password[i] = randomChar;
    }
    password[passwordLength] = '\0';

    printf("\nHere is your randomly generated password: \n");
    printf("%s\n\n", password);
    printf("This password contains %d characters.\n", passwordLength);

    int uppercaseLetters = 0, lowercaseLetters = 0, numbers = 0, specialCharacters = 0;
    for (int i = 0; i < passwordLength; i++) {
        if (isdigit(password[i])) {
            numbers++;
        } else if (isupper(password[i])) {
            uppercaseLetters++;
        } else if (islower(password[i])) {
            lowercaseLetters++;
        } else {
            specialCharacters++;
        }
    }

    printf("%d of the characters are uppercase letters.\n", uppercaseLetters);
    printf("%d of the characters are lowercase letters.\n", lowercaseLetters);
    printf("%d of the characters are numbers.\n", numbers);
    printf("%d of the characters are special characters.\n\n", specialCharacters);

    printFooter();
    return 0;
}