//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PASSWORD_LENGTH 64
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_ATTEMPTS 3

// Function to check if a given character is a digit
int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to check if a given character is a lowercase letter
int isLowercase(char c) {
    return (c >= 'a' && c <= 'z');
}

// Function to check if a given character is an uppercase letter
int isUppercase(char c) {
    return (c >= 'A' && c <= 'Z');
}

// Function to check if a given character is a special character
int isSpecialChar(char c) {
    return (!isalnum(c));
}

// Function to check if a given password meets the strength requirements
int checkPasswordStrength(char* password) {
    // Check password length
    if (strlen(password) < MIN_PASSWORD_LENGTH || strlen(password) > MAX_PASSWORD_LENGTH) {
        return 0;
    }

    // Check for at least one digit
    int hasDigit = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isDigit(password[i])) {
            hasDigit = 1;
            break;
        }
    }
    if (!hasDigit) {
        return 0;
    }

    // Check for at least one lowercase letter
    int hasLowercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isLowercase(password[i])) {
            hasLowercase = 1;
            break;
        }
    }
    if (!hasLowercase) {
        return 0;
    }

    // Check for at least one uppercase letter
    int hasUppercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isUppercase(password[i])) {
            hasUppercase = 1;
            break;
        }
    }
    if (!hasUppercase) {
        return 0;
    }

    // Check for at least one special character
    int hasSpecialChar = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isSpecialChar(password[i])) {
            hasSpecialChar = 1;
            break;
        }
    }
    if (!hasSpecialChar) {
        return 0;
    }

    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int attempts = 0;

    // Get password from user
    printf("Enter password: ");
    scanf("%s", password);

    // Check password strength
    while (!checkPasswordStrength(password) && attempts < MAX_PASSWORD_ATTEMPTS) {
        printf("Password is not strong enough. Please try again.\n");
        attempts++;
    }

    if (attempts == MAX_PASSWORD_ATTEMPTS) {
        printf("Too many attempts. Exiting.\n");
        return 1;
    }

    printf("Password is strong enough.\n");
    return 0;
}