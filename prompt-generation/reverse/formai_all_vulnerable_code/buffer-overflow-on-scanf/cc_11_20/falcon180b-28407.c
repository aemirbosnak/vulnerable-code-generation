//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

// Function to check if a character is a letter
int isLetter(char c) {
    if (isalpha(c)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if a character is a number
int isNumber(char c) {
    if (isdigit(c)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if a character is a special character
int isSpecialChar(char c) {
    if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '_' || c == '+' || c == '=' || c == '{' || c == '}' || c == '[' || c == ']' || c == '|' || c == '\\' || c == ':' || c == ';' || c == '"' || c == '\'' || c == ','|| c == '.' || c == '/' || c == '?' || c == '<' || c == '>') {
        return 1;
    } else {
        return 0;
    }
}

// Function to check the strength of a password
int checkPasswordStrength(char *password) {
    int length = strlen(password);
    int hasLetter = 0;
    int hasNumber = 0;
    int hasSpecialChar = 0;

    // Check for at least one letter
    for (int i = 0; i < length; i++) {
        if (isLetter(password[i])) {
            hasLetter = 1;
            break;
        }
    }

    // Check for at least one number
    for (int i = 0; i < length; i++) {
        if (isNumber(password[i])) {
            hasNumber = 1;
            break;
        }
    }

    // Check for at least one special character
    for (int i = 0; i < length; i++) {
        if (isSpecialChar(password[i])) {
            hasSpecialChar = 1;
            break;
        }
    }

    // Determine password strength
    if (length < 8) {
        return 1; // Weak
    } else if (length >= 8 && length < 12) {
        if (hasLetter && hasNumber) {
            return 2; // Medium
        } else {
            return 1; // Weak
        }
    } else if (length >= 12 && hasLetter && hasNumber && hasSpecialChar) {
        return 3; // Strong
    } else {
        return 2; // Medium
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    // Prompt user for password
    printf("Enter password: ");
    scanf("%s", password);

    // Check password strength
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
    }

    return 0;
}