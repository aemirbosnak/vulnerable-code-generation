//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 30

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
    return strchr("!@#$%^&*()_+-=[]{}|;:,.<>/?", c)!= NULL;
}

// Function to check password strength
int checkPasswordStrength(char* password) {
    int length = strlen(password);
    int hasLetter = 0;
    int hasDigit = 0;
    int hasSpecialChar = 0;

    for (int i = 0; i < length; i++) {
        if (isLetter(password[i])) {
            hasLetter = 1;
        } else if (isDigit(password[i])) {
            hasDigit = 1;
        } else if (isSpecialChar(password[i])) {
            hasSpecialChar = 1;
        }
    }

    if (length < 8) {
        return 1; // Weak
    } else if (length >= 8 && length < 12) {
        if (hasLetter && hasDigit) {
            return 2; // Medium
        } else {
            return 1; // Weak
        }
    } else if (length >= 12) {
        if (hasLetter && hasDigit && hasSpecialChar) {
            return 3; // Strong
        } else if (hasLetter && hasDigit) {
            return 2; // Medium
        } else {
            return 1; // Weak
        }
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    int strength = checkPasswordStrength(password);

    switch (strength) {
        case 1:
            printf("Weak password. Please choose a stronger one.\n");
            break;
        case 2:
            printf("Medium password. It's okay, but could be stronger.\n");
            break;
        case 3:
            printf("Strong password. Well done!\n");
            break;
    }

    return 0;
}