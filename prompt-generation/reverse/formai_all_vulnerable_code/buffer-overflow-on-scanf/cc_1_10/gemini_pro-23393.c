//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: optimized
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Constants to represent the different password strength levels
#define STRENGTH_WEAK 1
#define STRENGTH_GOOD 2
#define STRENGTH_STRONG 3

// Function to check if a character is a digit
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Function to check if a character is a lowercase letter
int is_lowercase(char c) {
    return c >= 'a' && c <= 'z';
}

// Function to check if a character is an uppercase letter
int is_uppercase(char c) {
    return c >= 'A' && c <= 'Z';
}

// Function to check if a character is a special character
int is_special(char c) {
    return c == '!' || c == '@' || c == '#' || c == '$' || c == '%';
}

// Function to calculate the strength of a password
int calculate_strength(char *password) {
    int length = strlen(password);
    int strength = 0;

    // Check for password length
    if (length < 8) {
        strength += 1;
    } else if (length >= 8 && length <= 12) {
        strength += 2;
    } else {
        strength += 3;
    }

    // Check for character types
    int has_digit = 0;
    int has_lowercase = 0;
    int has_uppercase = 0;
    int has_special = 0;

    for (int i = 0; i < length; i++) {
        if (is_digit(password[i])) {
            has_digit = 1;
        } else if (is_lowercase(password[i])) {
            has_lowercase = 1;
        } else if (is_uppercase(password[i])) {
            has_uppercase = 1;
        } else if (is_special(password[i])) {
            has_special = 1;
        }
    }

    if (has_digit) {
        strength += 1;
    }
    if (has_lowercase) {
        strength += 1;
    }
    if (has_uppercase) {
        strength += 1;
    }
    if (has_special) {
        strength += 1;
    }

    // Return the password strength level
    if (strength <= 3) {
        return STRENGTH_WEAK;
    } else if (strength >= 4 && strength <= 6) {
        return STRENGTH_GOOD;
    } else {
        return STRENGTH_STRONG;
    }
}

int main() {
    // Get the password from the user
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    // Calculate the strength of the password
    int strength = calculate_strength(password);

    // Print the password strength level
    switch (strength) {
        case STRENGTH_WEAK:
            printf("Your password is weak. Please choose a stronger password.\n");
            break;
        case STRENGTH_GOOD:
            printf("Your password is good. However, it could be stronger.\n");
            break;
        case STRENGTH_STRONG:
            printf("Your password is strong. Good job!\n");
            break;
    }

    return 0;
}