//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* generatePassword(int length);

int main()
{
    int passwordLength;
    char* password;

    // read password length from user
    printf("Enter password length: ");
    scanf("%d", &passwordLength);

    // generate password
    password = generatePassword(passwordLength);

    // print generated password
    printf("Generated password: %s\n", password);

    // free memory
    free(password);

    return 0;
}

char* generatePassword(int length)
{
    // initialize random seed
    srand(time(NULL));

    char* password = (char*) malloc(length + 1);

    // define character sets
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+-=[]{}|;':\",./<>?\\`~";

    // determine minimum number of characters from each character set
    int minLowercase = length / 4;
    int minUppercase = length / 4;
    int minNumbers = length / 4;
    int minSymbols = length - (minLowercase + minUppercase + minNumbers);

    // initialize counters and flags
    int lowercaseCount = 0;
    int uppercaseCount = 0;
    int numbersCount = 0;
    int symbolsCount = 0;
    int includeLowercase = 1;
    int includeUppercase = 1;
    int includeNumbers = 1;
    int includeSymbols = 1;

    // loop through password length
    for (int i = 0; i < length; i++) {
        // check if minimum number of characters from each set is fulfilled
        if (lowercaseCount >= minLowercase) {
            includeLowercase = 0;
        }
        if (uppercaseCount >= minUppercase) {
            includeUppercase = 0;
        }
        if (numbersCount >= minNumbers) {
            includeNumbers = 0;
        }
        if (symbolsCount >= minSymbols) {
            includeSymbols = 0;
        }

        // determine character set to use
        int charSetChoice = rand() % 4; // choose from 0 to 3

        if (includeLowercase && charSetChoice == 0) {
            password[i] = lowercase[rand() % strlen(lowercase)];
            lowercaseCount++;
        } else if (includeUppercase && charSetChoice == 1) {
            password[i] = uppercase[rand() % strlen(uppercase)];
            uppercaseCount++;
        } else if (includeNumbers && charSetChoice == 2) {
            password[i] = numbers[rand() % strlen(numbers)];
            numbersCount++;
        } else if (includeSymbols && charSetChoice == 3) {
            password[i] = symbols[rand() % strlen(symbols)];
            symbolsCount++;
        } else {
            // if none of the character set conditions are fulfilled, select random character from any set
            int allChoice = rand() % 3; // choose from 0 to 2

            if (allChoice == 0) {
                password[i] = lowercase[rand() % strlen(lowercase)];
                lowercaseCount++;
            } else if (allChoice == 1) {
                password[i] = uppercase[rand() % strlen(uppercase)];
                uppercaseCount++;
            } else if (allChoice == 2) {
                password[i] = numbers[rand() % strlen(numbers)];
                numbersCount++;
            }
        }
    }

    // terminate string
    password[length] = '\0';

    return password;
}