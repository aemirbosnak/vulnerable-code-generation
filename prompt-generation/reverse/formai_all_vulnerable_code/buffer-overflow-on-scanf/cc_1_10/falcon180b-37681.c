//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is an uppercase letter
int isUpperCase(char c) {
    return (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a lowercase letter
int isLowerCase(char c) {
    return (c >= 'a' && c <= 'z');
}

// Function to check if a character is a digit
int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to check if a character is a special character
int isSpecialChar(char c) {
    return (!isUpperCase(c) &&!isLowerCase(c) &&!isDigit(c));
}

// Function to check the strength of a password
int checkPasswordStrength(char *password) {
    int length = strlen(password);
    int hasUpperCase = 0;
    int hasLowerCase = 0;
    int hasDigit = 0;
    int hasSpecialChar = 0;

    for (int i = 0; i < length; i++) {
        char c = password[i];

        if (isUpperCase(c)) {
            hasUpperCase = 1;
        } else if (isLowerCase(c)) {
            hasLowerCase = 1;
        } else if (isDigit(c)) {
            hasDigit = 1;
        } else if (isSpecialChar(c)) {
            hasSpecialChar = 1;
        }
    }

    if (length < 8) {
        return 1; // Weak
    } else if (length >= 8 && length < 12) {
        if (hasUpperCase && hasLowerCase && hasDigit) {
            return 2; // Medium
        } else {
            return 1; // Weak
        }
    } else if (length >= 12) {
        if (hasUpperCase && hasLowerCase && hasDigit && hasSpecialChar) {
            return 3; // Strong
        } else if (hasUpperCase && hasLowerCase && hasDigit) {
            return 2; // Medium
        } else {
            return 1; // Weak
        }
    }
}

int main() {
    char password[100];

    printf("Enter your password: ");
    scanf("%s", password);

    int strength = checkPasswordStrength(password);

    switch (strength) {
        case 1:
            printf("Weak\n");
            break;
        case 2:
            printf("Medium\n");
            break;
        case 3:
            printf("Strong\n");
            break;
        default:
            printf("Invalid\n");
            break;
    }

    return 0;
}