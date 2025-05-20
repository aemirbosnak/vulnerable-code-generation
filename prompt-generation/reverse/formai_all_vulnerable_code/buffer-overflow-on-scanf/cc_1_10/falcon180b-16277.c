//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define LENGTH 8 // minimum length of password

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
    if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '?' || c == ':' || c == ';' || c == '|' || c == '~') {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if a password contains at least one letter, one number and one special character
int checkPasswordStrength(char* password) {
    int hasLetter = 0;
    int hasNumber = 0;
    int hasSpecialChar = 0;

    // Check if password contains at least one letter
    for (int i = 0; i < strlen(password); i++) {
        if (isLetter(password[i])) {
            hasLetter = 1;
            break;
        }
    }

    // Check if password contains at least one number
    for (int i = 0; i < strlen(password); i++) {
        if (isNumber(password[i])) {
            hasNumber = 1;
            break;
        }
    }

    // Check if password contains at least one special character
    for (int i = 0; i < strlen(password); i++) {
        if (isSpecialChar(password[i])) {
            hasSpecialChar = 1;
            break;
        }
    }

    // If password contains at least one letter, one number and one special character, return 1
    if (hasLetter && hasNumber && hasSpecialChar) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[LENGTH];

    // Prompt the user to enter a password
    printf("Enter a password: ");
    scanf("%s", password);

    // Check if the password is strong enough
    if (checkPasswordStrength(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}