//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: imaginative
#include <stdio.h>
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

// Function to check the strength of a password
int checkPasswordStrength(char* password) {
    int length = strlen(password);
    int hasLetters = 0;
    int hasDigits = 0;
    int hasSpecialChars = 0;

    // Check if the password contains at least one letter
    for (int i = 0; i < length; i++) {
        if (isLetter(password[i])) {
            hasLetters = 1;
            break;
        }
    }

    // Check if the password contains at least one digit
    for (int i = 0; i < length; i++) {
        if (isDigit(password[i])) {
            hasDigits = 1;
            break;
        }
    }

    // Check if the password contains at least one special character
    for (int i = 0; i < length; i++) {
        if (isSpecialChar(password[i])) {
            hasSpecialChars = 1;
            break;
        }
    }

    // Determine the strength of the password based on the number of different character types
    if (hasLetters && hasDigits && hasSpecialChars) {
        return 3; // Strong
    } else if (hasLetters && hasDigits) {
        return 2; // Medium
    } else if (hasLetters || hasDigits) {
        return 1; // Weak
    } else {
        return 0; // Very weak
    }
}

int main() {
    char password[100];

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the strength of the password
    int strength = checkPasswordStrength(password);

    // Print the strength of the password
    switch (strength) {
        case 3:
            printf("Your password is very strong.\n");
            break;
        case 2:
            printf("Your password is strong.\n");
            break;
        case 1:
            printf("Your password is weak.\n");
            break;
        case 0:
            printf("Your password is very weak.\n");
            break;
    }

    return 0;
}