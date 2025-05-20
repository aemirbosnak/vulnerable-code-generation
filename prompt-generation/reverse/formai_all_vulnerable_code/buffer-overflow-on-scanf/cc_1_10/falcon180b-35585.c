//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
    return!isLetter(c) &&!isDigit(c);
}

// Function to check the strength of the password
int checkPasswordStrength(char* password) {
    int length = strlen(password);
    int hasLetters = 0, hasDigits = 0, hasSpecialChars = 0;

    // Check if the password has at least one letter
    for (int i = 0; i < length; i++) {
        if (isLetter(password[i])) {
            hasLetters = 1;
            break;
        }
    }

    // Check if the password has at least one digit
    for (int i = 0; i < length; i++) {
        if (isDigit(password[i])) {
            hasDigits = 1;
            break;
        }
    }

    // Check if the password has at least one special character
    for (int i = 0; i < length; i++) {
        if (isSpecialChar(password[i])) {
            hasSpecialChars = 1;
            break;
        }
    }

    // Calculate the strength of the password
    int strength = 0;
    if (length >= 8) {
        strength++;
    }
    if (hasLetters && hasDigits) {
        strength++;
    }
    if (hasLetters && hasSpecialChars) {
        strength++;
    }
    if (hasDigits && hasSpecialChars) {
        strength++;
    }

    return strength;
}

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the strength of the password
    int strength = checkPasswordStrength(password);

    if (strength == 0) {
        printf("Weak password\n");
    } else if (strength == 1) {
        printf("Moderate password\n");
    } else {
        printf("Strong password\n");
    }

    return 0;
}