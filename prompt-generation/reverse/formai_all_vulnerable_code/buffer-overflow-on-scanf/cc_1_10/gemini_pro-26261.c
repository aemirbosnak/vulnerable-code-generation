//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is a digit
int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to check if a character is a lowercase letter
int isLowercase(char c) {
    return (c >= 'a' && c <= 'z');
}

// Function to check if a character is an uppercase letter
int isUppercase(char c) {
    return (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a special character
int isSpecial(char c) {
    return (!isDigit(c) && !isLowercase(c) && !isUppercase(c));
}

// Function to check the strength of a password
int checkPasswordStrength(char *password) {
    int length = strlen(password);
    int score = 0;

    // Check if the password is at least 8 characters long
    if (length >= 8) {
        score += 1;
    }

    // Check if the password contains at least one digit
    int hasDigit = 0;
    for (int i = 0; i < length; i++) {
        if (isDigit(password[i])) {
            hasDigit = 1;
            break;
        }
    }
    if (hasDigit) {
        score += 1;
    }

    // Check if the password contains at least one lowercase letter
    int hasLowercase = 0;
    for (int i = 0; i < length; i++) {
        if (isLowercase(password[i])) {
            hasLowercase = 1;
            break;
        }
    }
    if (hasLowercase) {
        score += 1;
    }

    // Check if the password contains at least one uppercase letter
    int hasUppercase = 0;
    for (int i = 0; i < length; i++) {
        if (isUppercase(password[i])) {
            hasUppercase = 1;
            break;
        }
    }
    if (hasUppercase) {
        score += 1;
    }

    // Check if the password contains at least one special character
    int hasSpecial = 0;
    for (int i = 0; i < length; i++) {
        if (isSpecial(password[i])) {
            hasSpecial = 1;
            break;
        }
    }
    if (hasSpecial) {
        score += 1;
    }

    // Return the password strength score
    return score;
}

// Function to generate a random password
char *generatePassword(int length) {
    char *password = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        password[i] = (rand() % 94) + 33;
    }
    password[length] = '\0';
    return password;
}

int main() {
    // Get the desired password length from the user
    int length;
    printf("Enter the desired password length: ");
    scanf("%d", &length);

    // Generate a random password
    char *password = generatePassword(length);

    // Check the strength of the password
    int strength = checkPasswordStrength(password);

    // Print the password and its strength
    printf("Password: %s\n", password);
    printf("Strength: %d\n", strength);

    // Free the allocated memory
    free(password);

    return 0;
}