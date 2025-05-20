//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is uppercase
int isUppercase(char c) {
    return (c >= 'A' && c <= 'Z');
}

// Function to check if a character is lowercase
int isLowercase(char c) {
    return (c >= 'a' && c <= 'z');
}

// Function to check if a character is a digit
int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to check if a character is a special character
int isSpecialCharacter(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%');
}

// Function to check if a password is strong
int isStrongPassword(char *password) {
    // Check if the password is at least 8 characters long
    if (strlen(password) < 8) {
        return 0;
    }

    // Check if the password contains at least one uppercase character
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

    // Check if the password contains at least one lowercase character
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

    // Check if the password contains at least one digit
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

    // Check if the password contains at least one special character
    int hasSpecialCharacter = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isSpecialCharacter(password[i])) {
            hasSpecialCharacter = 1;
            break;
        }
    }
    if (!hasSpecialCharacter) {
        return 0;
    }

    // If all of the checks pass, then the password is strong
    return 1;
}

// Main function
int main() {
    // Get the password from the user
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check if the password is strong
    int isStrong = isStrongPassword(password);

    // Print the result
    if (isStrong) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is not strong.\n");
    }

    return 0;
}