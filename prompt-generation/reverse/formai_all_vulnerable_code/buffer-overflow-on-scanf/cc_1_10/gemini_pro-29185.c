//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 256

// Function to check if a character is in a given string
int charInString(char c, char *str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (c == str[i]) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a password is strong
int isStrongPassword(char *password) {
    int length, numUpper, numLower, numDigits, numSymbols;
    char *upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *lowerCase = "abcdefghijklmnopqrstuvwxyz";
    char *digits = "0123456789";
    char *symbols = "!@#$%^&*()_+=-`~";

    // Check length
    length = strlen(password);
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        return 0;
    }

    // Check for uppercase characters
    numUpper = 0;
    for (int i = 0; i < length; i++) {
        if (charInString(password[i], upperCase)) {
            numUpper++;
        }
    }
    if (numUpper == 0) {
        return 0;
    }

    // Check for lowercase characters
    numLower = 0;
    for (int i = 0; i < length; i++) {
        if (charInString(password[i], lowerCase)) {
            numLower++;
        }
    }
    if (numLower == 0) {
        return 0;
    }

    // Check for digits
    numDigits = 0;
    for (int i = 0; i < length; i++) {
        if (charInString(password[i], digits)) {
            numDigits++;
        }
    }
    if (numDigits == 0) {
        return 0;
    }

    // Check for symbols
    numSymbols = 0;
    for (int i = 0; i < length; i++) {
        if (charInString(password[i], symbols)) {
            numSymbols++;
        }
    }
    if (numSymbols == 0) {
        return 0;
    }

    // If all checks pass, return 1
    return 1;
}

int main() {
    char password[MAX_LENGTH];

    printf("Enter a password: ");
    scanf("%s", password);

    if (isStrongPassword(password)) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is not strong. Please try again.\n");
    }

    return 0;
}