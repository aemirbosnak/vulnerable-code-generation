//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 64

// Define the character types
#define CHAR_TYPE_UPPERCASE 1
#define CHAR_TYPE_LOWERCASE 2
#define CHAR_TYPE_DIGIT 3
#define CHAR_TYPE_SYMBOL 4

// Define the password strength levels
#define PASSWORD_STRENGTH_WEAK 1
#define PASSWORD_STRENGTH_MEDIUM 2
#define PASSWORD_STRENGTH_STRONG 3

// Function to check if a character is uppercase
int is_uppercase(char c) {
    return c >= 'A' && c <= 'Z';
}

// Function to check if a character is lowercase
int is_lowercase(char c) {
    return c >= 'a' && c <= 'z';
}

// Function to check if a character is a digit
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Function to check if a character is a symbol
int is_symbol(char c) {
    return !is_uppercase(c) && !is_lowercase(c) && !is_digit(c);
}

// Function to calculate the password strength
int calculate_password_strength(char *password) {
    int strength = 0;
    int length = strlen(password);
    int char_types = 0;

    // Check the password length
    if (length < MIN_PASSWORD_LENGTH) {
        return PASSWORD_STRENGTH_WEAK;
    } else if (length > MAX_PASSWORD_LENGTH) {
        return PASSWORD_STRENGTH_WEAK;
    } else {
        strength++;
    }

    // Check the character types
    for (int i = 0; i < length; i++) {
        char c = password[i];
        if (is_uppercase(c)) {
            char_types |= CHAR_TYPE_UPPERCASE;
        } else if (is_lowercase(c)) {
            char_types |= CHAR_TYPE_LOWERCASE;
        } else if (is_digit(c)) {
            char_types |= CHAR_TYPE_DIGIT;
        } else if (is_symbol(c)) {
            char_types |= CHAR_TYPE_SYMBOL;
        }
    }

    // Check the number of character types
    if (char_types >= 3) {
        strength++;
    }

    // Check the password strength
    if (strength == 3) {
        return PASSWORD_STRENGTH_STRONG;
    } else if (strength == 2) {
        return PASSWORD_STRENGTH_MEDIUM;
    } else {
        return PASSWORD_STRENGTH_WEAK;
    }
}

// Function to print the password strength
void print_password_strength(int strength) {
    switch (strength) {
        case PASSWORD_STRENGTH_WEAK:
            printf("Weak\n");
            break;
        case PASSWORD_STRENGTH_MEDIUM:
            printf("Medium\n");
            break;
        case PASSWORD_STRENGTH_STRONG:
            printf("Strong\n");
            break;
    }
}

// Main function
int main() {
    // Get the password from the user
    char password[MAX_PASSWORD_LENGTH + 1];
    printf("Enter your password: ");
    scanf("%s", password);

    // Calculate the password strength
    int strength = calculate_password_strength(password);

    // Print the password strength
    printf("Your password strength is: ");
    print_password_strength(strength);

    return 0;
}