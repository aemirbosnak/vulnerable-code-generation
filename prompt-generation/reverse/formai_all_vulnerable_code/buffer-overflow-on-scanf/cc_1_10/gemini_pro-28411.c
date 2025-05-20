//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 32

// Define the character sets
#define LOWERCASE_CHARACTERS "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE_CHARACTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBER_CHARACTERS "0123456789"
#define SYMBOL_CHARACTERS "!@#$%^&*()-=_+[]{};:,<.>/?~"

// Define the password strength levels
enum PasswordStrengthLevel {
    VERY_WEAK,
    WEAK,
    MEDIUM,
    STRONG,
    VERY_STRONG
};

// Check if the password is long enough
bool is_password_long_enough(const char *password) {
    return strlen(password) >= MIN_PASSWORD_LENGTH;
}

// Check if the password contains at least one lowercase character
bool contains_lowercase_character(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return true;
        }
    }
    return false;
}

// Check if the password contains at least one uppercase character
bool contains_uppercase_character(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return true;
        }
    }
    return false;
}

// Check if the password contains at least one number
bool contains_number(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return true;
        }
    }
    return false;
}

// Check if the password contains at least one symbol
bool contains_symbol(const char *password) {
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            return true;
        }
    }
    return false;
}

// Check the password strength
enum PasswordStrengthLevel check_password_strength(const char *password) {
    int score = 0;

    // Check if the password is long enough
    if (is_password_long_enough(password)) {
        score++;
    }

    // Check if the password contains at least one lowercase character
    if (contains_lowercase_character(password)) {
        score++;
    }

    // Check if the password contains at least one uppercase character
    if (contains_uppercase_character(password)) {
        score++;
    }

    // Check if the password contains at least one number
    if (contains_number(password)) {
        score++;
    }

    // Check if the password contains at least one symbol
    if (contains_symbol(password)) {
        score++;
    }

    // Return the password strength level
    switch (score) {
        case 0:
            return VERY_WEAK;
        case 1:
            return WEAK;
        case 2:
            return MEDIUM;
        case 3:
            return STRONG;
        case 4:
            return VERY_STRONG;
        default:
            return VERY_STRONG;
    }
}

// Print the password strength level
void print_password_strength_level(enum PasswordStrengthLevel strength_level) {
    switch (strength_level) {
        case VERY_WEAK:
            printf("Very weak\n");
            break;
        case WEAK:
            printf("Weak\n");
            break;
        case MEDIUM:
            printf("Medium\n");
            break;
        case STRONG:
            printf("Strong\n");
            break;
        case VERY_STRONG:
            printf("Very strong\n");
            break;
    }
}

int main() {
    // Prompt the user to enter a password
    char password[MAX_PASSWORD_LENGTH + 1];
    printf("Enter a password: ");
    scanf("%s", password);

    // Check the password strength
    enum PasswordStrengthLevel strength_level = check_password_strength(password);

    // Print the password strength level
    printf("Password strength: ");
    print_password_strength_level(strength_level);

    return 0;
}