//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LEN 128

void generatePassword(char *password, int length, int useUpperCase, int useLowerCase, int useDigits, int useSpecialChars) {
    const char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *lower = "abcdefghijklmnopqrstuvwxyz";
    const char *digits = "0123456789";
    const char *specialChars = "!@#$%^&*()-_=+[]{};:,.<>?";

    char charset[MAX_LEN];
    int index = 0;

    if (useUpperCase) {
        strcat(charset, upper);
        index += strlen(upper);
    }
    if (useLowerCase) {
        strcat(charset, lower);
        index += strlen(lower);
    }
    if (useDigits) {
        strcat(charset, digits);
        index += strlen(digits);
    }
    if (useSpecialChars) {
        strcat(charset, specialChars);
        index += strlen(specialChars);
    }

    if (index == 0) {
        printf("Error: At least one character set must be selected.\n");
        exit(1);
    }

    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % index];
    }
    password[length] = '\0'; // Null terminate the string
}

int getInputPasswordLength() {
    int length;
    printf("Enter password length (1 to %d): ", MAX_LEN);
    while (1) {
        scanf("%d", &length);
        if (length >= 1 && length <= MAX_LEN) {
            break;
        }
        printf("Invalid length. Please enter a number between 1 and %d: ", MAX_LEN);
    }
    return length;
}

void getPasswordOptions(int *useUpperCase, int *useLowerCase, int *useDigits, int *useSpecialChars) {
    char choice;
    printf("Include uppercase letters? (y/n): ");
    scanf(" %c", &choice);
    *useUpperCase = (choice == 'y' || choice == 'Y');

    printf("Include lowercase letters? (y/n): ");
    scanf(" %c", &choice);
    *useLowerCase = (choice == 'y' || choice == 'Y');

    printf("Include digits? (y/n): ");
    scanf(" %c", &choice);
    *useDigits = (choice == 'y' || choice == 'Y');

    printf("Include special characters? (y/n): ");
    scanf(" %c", &choice);
    *useSpecialChars = (choice == 'y' || choice == 'Y');
}

int main() {
    int length;
    int useUpperCase, useLowerCase, useDigits, useSpecialChars;
    char password[MAX_LEN + 1];

    srand(time(NULL)); // Seed the random number generator

    length = getInputPasswordLength();
    getPasswordOptions(&useUpperCase, &useLowerCase, &useDigits, &useSpecialChars);

    generatePassword(password, length, useUpperCase, useLowerCase, useDigits, useSpecialChars);

    printf("Generated Password: %s\n", password);
    return 0;
}