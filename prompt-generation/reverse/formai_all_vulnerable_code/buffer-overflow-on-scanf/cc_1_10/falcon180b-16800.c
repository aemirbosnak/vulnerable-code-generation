//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: portable
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 100

// Function to check if a character is a letter
bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a digit
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Function to check if a character is a special character
bool isSpecialChar(char c) {
    return strchr("!@#$%^&*()_+-=[]{}|;:,.<>/?", c)!= NULL;
}

// Function to check if a password meets the minimum length requirement
bool isPasswordLongEnough(char* password, int length) {
    return strlen(password) >= length;
}

// Function to check if a password contains at least one letter, one digit, and one special character
bool isPasswordStrong(char* password, int length) {
    int numLetters = 0;
    int numDigits = 0;
    int numSpecialChars = 0;
    for (int i = 0; i < length; i++) {
        if (isLetter(password[i])) {
            numLetters++;
        } else if (isDigit(password[i])) {
            numDigits++;
        } else if (isSpecialChar(password[i])) {
            numSpecialChars++;
        }
    }
    return (numLetters >= 1 && numDigits >= 1 && numSpecialChars >= 1);
}

// Function to get a password from the user
void getPassword(char* password, int length) {
    printf("Enter a password: ");
    fgets(password, length, stdin);
    password[strcspn(password, "\n")] = '\0';
}

// Main function
int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;
    do {
        printf("Enter the desired password length (between 1 and %d): ", MAX_PASSWORD_LENGTH);
        scanf("%d", &length);
    } while (length < 1 || length > MAX_PASSWORD_LENGTH);

    getPassword(password, length);

    if (isPasswordLongEnough(password, length)) {
        if (isPasswordStrong(password, length)) {
            printf("Password is strong.\n");
        } else {
            printf("Password is not strong.\n");
        }
    } else {
        printf("Password is too short.\n");
    }

    return 0;
}