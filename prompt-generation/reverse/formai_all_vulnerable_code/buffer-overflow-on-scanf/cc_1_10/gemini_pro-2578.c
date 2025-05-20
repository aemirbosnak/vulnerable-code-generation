//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 64

// Define the password strength levels
typedef enum {
    WEAK,
    MEDIUM,
    STRONG,
    VERY_STRONG
} PasswordStrength;

// Function to check if a character is a digit
bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Function to check if a character is a lowercase letter
bool is_lowercase(char c) {
    return c >= 'a' && c <= 'z';
}

// Function to check if a character is an uppercase letter
bool is_uppercase(char c) {
    return c >= 'A' && c <= 'Z';
}

// Function to check if a character is a special character
bool is_special(char c) {
    return !is_digit(c) && !is_lowercase(c) && !is_uppercase(c);
}

// Function to calculate the password strength
PasswordStrength calculate_password_strength(char *password) {
    int password_length = strlen(password);

    // Check if the password meets the minimum length requirement
    if (password_length < MIN_PASSWORD_LENGTH) {
        return WEAK;
    }

    // Check if the password contains at least one digit, one lowercase letter, one uppercase letter, and one special character
    int num_digits = 0;
    int num_lowercase = 0;
    int num_uppercase = 0;
    int num_special = 0;

    for (int i = 0; i < password_length; i++) {
        char c = password[i];

        if (is_digit(c)) {
            num_digits++;
        } else if (is_lowercase(c)) {
            num_lowercase++;
        } else if (is_uppercase(c)) {
            num_uppercase++;
        } else if (is_special(c)) {
            num_special++;
        }
    }

    if (num_digits == 0 || num_lowercase == 0 || num_uppercase == 0 || num_special == 0) {
        return WEAK;
    }

    // Check if the password contains at least three of the following: a digit, a lowercase letter, an uppercase letter, or a special character
    int num_valid_characters = num_digits + num_lowercase + num_uppercase + num_special;

    if (num_valid_characters >= 3) {
        return MEDIUM;
    }

    // Check if the password contains at least four of the following: a digit, a lowercase letter, an uppercase letter, or a special character
    if (num_valid_characters >= 4) {
        return STRONG;
    }

    // The password must be very strong if it contains at least five of the following: a digit, a lowercase letter, an uppercase letter, or a special character
    return VERY_STRONG;
}

int main() {
    // Get the password from the user
    char password[MAX_PASSWORD_LENGTH + 1];
    printf("Enter your password: ");
    scanf("%s", password);

    // Calculate the password strength
    PasswordStrength strength = calculate_password_strength(password);

    // Print the password strength
    switch (strength) {
        case WEAK:
            printf("Your password is weak.\n");
            break;
        case MEDIUM:
            printf("Your password is medium.\n");
            break;
        case STRONG:
            printf("Your password is strong.\n");
            break;
        case VERY_STRONG:
            printf("Your password is very strong.\n");
            break;
    }

    return 0;
}