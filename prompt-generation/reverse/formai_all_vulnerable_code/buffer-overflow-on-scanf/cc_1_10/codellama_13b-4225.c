//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the password strength checker configuration
typedef struct {
    int min_length;
    int max_length;
    int min_lowercase;
    int min_uppercase;
    int min_numbers;
    int min_symbols;
    int min_unique_chars;
} PasswordStrengthCheckerConfig;

// Function to check if a character is a lowercase letter
int is_lowercase(char c) {
    return (c >= 'a' && c <= 'z');
}

// Function to check if a character is an uppercase letter
int is_uppercase(char c) {
    return (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a number
int is_number(char c) {
    return (c >= '0' && c <= '9');
}

// Function to check if a character is a symbol
int is_symbol(char c) {
    return !(is_lowercase(c) || is_uppercase(c) || is_number(c));
}

// Function to check if a password is strong enough
int is_password_strong(char* password, PasswordStrengthCheckerConfig* config) {
    int length = strlen(password);
    int lowercase = 0;
    int uppercase = 0;
    int numbers = 0;
    int symbols = 0;
    int unique_chars = 0;

    // Check if the password length is within the specified range
    if (length < config->min_length || length > config->max_length) {
        return 0;
    }

    // Count the number of lowercase, uppercase, numbers, and symbols in the password
    for (int i = 0; i < length; i++) {
        if (is_lowercase(password[i])) {
            lowercase++;
        } else if (is_uppercase(password[i])) {
            uppercase++;
        } else if (is_number(password[i])) {
            numbers++;
        } else if (is_symbol(password[i])) {
            symbols++;
        }
        unique_chars += (password[i] != password[i-1]);
    }

    // Check if the password has enough of each character type
    if (lowercase < config->min_lowercase || uppercase < config->min_uppercase || numbers < config->min_numbers || symbols < config->min_symbols) {
        return 0;
    }

    // Check if the password has enough unique characters
    if (unique_chars < config->min_unique_chars) {
        return 0;
    }

    // If all the checks pass, return 1
    return 1;
}

int main() {
    // Configure the password strength checker
    PasswordStrengthCheckerConfig config;
    config.min_length = 8;
    config.max_length = 16;
    config.min_lowercase = 1;
    config.min_uppercase = 1;
    config.min_numbers = 1;
    config.min_symbols = 1;
    config.min_unique_chars = 4;

    // Prompt the user for a password
    char password[100];
    printf("Enter a password: ");
    scanf("%s", password);

    // Check if the password is strong enough
    int is_strong = is_password_strong(password, &config);
    if (is_strong) {
        printf("The password is strong enough!\n");
    } else {
        printf("The password is not strong enough.\n");
    }

    return 0;
}