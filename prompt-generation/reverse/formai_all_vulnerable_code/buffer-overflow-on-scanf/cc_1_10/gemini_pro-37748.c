//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 64

// Define the character types
#define CHAR_TYPE_UPPERCASE 0
#define CHAR_TYPE_LOWERCASE 1
#define CHAR_TYPE_DIGIT 2
#define CHAR_TYPE_SYMBOL 3

// Define the password strength levels
#define PASSWORD_STRENGTH_WEAK 0
#define PASSWORD_STRENGTH_MEDIUM 1
#define PASSWORD_STRENGTH_STRONG 2

// Declare the password strength checker function
int check_password_strength(char *password);

// Main function
int main() {
    // Get the password from the user
    char password[MAX_PASSWORD_LENGTH + 1];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the password strength
    int strength = check_password_strength(password);

    // Print the password strength
    switch (strength) {
        case PASSWORD_STRENGTH_WEAK:
            printf("Your password is weak.\n");
            break;
        case PASSWORD_STRENGTH_MEDIUM:
            printf("Your password is medium.\n");
            break;
        case PASSWORD_STRENGTH_STRONG:
            printf("Your password is strong.\n");
            break;
        default:
            printf("Invalid password strength.\n");
    }

    return 0;
}

// Password strength checker function
int check_password_strength(char *password) {
    // Check the password length
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        return PASSWORD_STRENGTH_WEAK;
    } else if (strlen(password) > MAX_PASSWORD_LENGTH) {
        return PASSWORD_STRENGTH_WEAK;
    }

    // Check the password for character types
    int char_types[CHAR_TYPE_SYMBOL + 1] = {0};
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            char_types[CHAR_TYPE_UPPERCASE]++;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            char_types[CHAR_TYPE_LOWERCASE]++;
        } else if (password[i] >= '0' && password[i] <= '9') {
            char_types[CHAR_TYPE_DIGIT]++;
        } else {
            char_types[CHAR_TYPE_SYMBOL]++;
        }
    }

    // Check if the password contains at least one of each character type
    int num_char_types = 0;
    for (int i = 0; i < CHAR_TYPE_SYMBOL + 1; i++) {
        if (char_types[i] > 0) {
            num_char_types++;
        }
    }

    // Return the password strength
    if (num_char_types < 3) {
        return PASSWORD_STRENGTH_WEAK;
    } else if (num_char_types == 3) {
        return PASSWORD_STRENGTH_MEDIUM;
    } else {
        return PASSWORD_STRENGTH_STRONG;
    }
}