//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum password length.
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length.
#define MAX_PASSWORD_LENGTH 32

// Define the character classes for password strength.
#define CHAR_CLASS_LOWER 0x01
#define CHAR_CLASS_UPPER 0x02
#define CHAR_CLASS_DIGIT 0x04
#define CHAR_CLASS_SPECIAL 0x08

// Define the password strength levels.
#define STRENGTH_LEVEL_WEAK 0
#define STRENGTH_LEVEL_MEDIUM 1
#define STRENGTH_LEVEL_STRONG 2

// Declare the function to check the strength of a password.
int check_password_strength(char *password);

// Declare the main function.
int main() {
    // Define the password variable.
    char password[MAX_PASSWORD_LENGTH + 1];

    // Prompt the user to enter a password.
    printf("Enter a password: ");
    scanf("%s", password);

    // Check the strength of the password.
    int strength = check_password_strength(password);

    // Print the password strength level.
    switch (strength) {
        case STRENGTH_LEVEL_WEAK:
            printf("The password is weak.\n");
            break;
        case STRENGTH_LEVEL_MEDIUM:
            printf("The password is medium.\n");
            break;
        case STRENGTH_LEVEL_STRONG:
            printf("The password is strong.\n");
            break;
        default:
            printf("The password is invalid.\n");
    }

    return 0;
}

// Define the function to check the strength of a password.
int check_password_strength(char *password) {
    // Check if the password is empty.
    if (strlen(password) == 0) {
        return STRENGTH_LEVEL_WEAK;
    }

    // Check if the password is too short.
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        return STRENGTH_LEVEL_WEAK;
    }

    // Check if the password is too long.
    if (strlen(password) > MAX_PASSWORD_LENGTH) {
        return STRENGTH_LEVEL_WEAK;
    }

    // Check if the password contains at least one lowercase letter.
    int has_lowercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
            break;
        }
    }

    // Check if the password contains at least one uppercase letter.
    int has_uppercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
            break;
        }
    }

    // Check if the password contains at least one digit.
    int has_digit = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
            break;
        }
    }

    // Check if the password contains at least one special character.
    int has_special = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] < 'a' || password[i] > 'z') {
            if (password[i] < 'A' || password[i] > 'Z') {
                if (password[i] < '0' || password[i] > '9') {
                    has_special = 1;
                    break;
                }
            }
        }
    }

    // Calculate the password strength level.
    int strength = 0;
    if (has_lowercase) {
        strength |= CHAR_CLASS_LOWER;
    }
    if (has_uppercase) {
        strength |= CHAR_CLASS_UPPER;
    }
    if (has_digit) {
        strength |= CHAR_CLASS_DIGIT;
    }
    if (has_special) {
        strength |= CHAR_CLASS_SPECIAL;
    }

    switch (strength) {
        case CHAR_CLASS_LOWER | CHAR_CLASS_UPPER | CHAR_CLASS_DIGIT:
        case CHAR_CLASS_LOWER | CHAR_CLASS_UPPER | CHAR_CLASS_SPECIAL:
        case CHAR_CLASS_LOWER | CHAR_CLASS_DIGIT | CHAR_CLASS_SPECIAL:
        case CHAR_CLASS_UPPER | CHAR_CLASS_DIGIT | CHAR_CLASS_SPECIAL:
            return STRENGTH_LEVEL_MEDIUM;
        case CHAR_CLASS_LOWER | CHAR_CLASS_UPPER | CHAR_CLASS_DIGIT | CHAR_CLASS_SPECIAL:
            return STRENGTH_LEVEL_STRONG;
        default:
            return STRENGTH_LEVEL_WEAK;
    }
}