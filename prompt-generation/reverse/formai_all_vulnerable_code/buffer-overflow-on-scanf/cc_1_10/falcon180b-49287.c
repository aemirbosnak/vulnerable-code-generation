//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100

// Function to check if a character is a letter
int isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a digit
int isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Function to check if a character is a special character
int isSpecialChar(char c) {
    return strchr("!@#$%^&*()-_+=[]{}\\|;:,.<>?/", c)!= NULL;
}

// Function to check the strength of a password
int checkPasswordStrength(char *password) {
    int length = strlen(password);
    int hasLetters = 0;
    int hasDigits = 0;
    int hasSpecialChars = 0;

    for (int i = 0; i < length; i++) {
        if (isLetter(password[i])) {
            hasLetters = 1;
        } else if (isDigit(password[i])) {
            hasDigits = 1;
        } else if (isSpecialChar(password[i])) {
            hasSpecialChars = 1;
        }
    }

    if (length < 8) {
        return 1; // Weak
    } else if (hasLetters && hasDigits && hasSpecialChars) {
        return 5; // Strongest
    } else if (hasLetters && hasDigits) {
        return 4; // Strong
    } else if (hasLetters && hasSpecialChars) {
        return 3; // Medium
    } else if (hasDigits && hasSpecialChars) {
        return 2; // Weak
    } else {
        return 1; // Weak
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter a password: ");
    scanf("%s", password);

    int strength = checkPasswordStrength(password);

    switch (strength) {
        case 1:
            printf("Weak\n");
            break;
        case 2:
            printf("Weak\n");
            break;
        case 3:
            printf("Medium\n");
            break;
        case 4:
            printf("Strong\n");
            break;
        case 5:
            printf("Strongest\n");
            break;
    }

    return 0;
}