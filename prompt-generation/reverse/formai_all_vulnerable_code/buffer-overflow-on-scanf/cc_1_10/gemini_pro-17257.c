//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the password strength levels
#define WEAK 1
#define MEDIUM 2
#define STRONG 3

// Define the password complexity requirements
#define MIN_LENGTH 8
#define MIN_UPPERCASE 1
#define MIN_LOWERCASE 1
#define MIN_DIGIT 1
#define MIN_SPECIAL 1

// Define the password character sets
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define DIGITS "0123456789"
#define SPECIAL "!@#$%^&*()"

// Function to check if a character is in a string
int str_contains(char *str, char c) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a password meets the complexity requirements
int password_is_complex(char *password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special = 0;

    // Check the length of the password
    if (length < MIN_LENGTH) {
        return 0;
    }

    // Check for uppercase, lowercase, digits, and special characters
    for (int i = 0; i < length; i++) {
        if (str_contains(UPPERCASE, password[i])) {
            has_uppercase = 1;
        } else if (str_contains(LOWERCASE, password[i])) {
            has_lowercase = 1;
        } else if (str_contains(DIGITS, password[i])) {
            has_digit = 1;
        } else if (str_contains(SPECIAL, password[i])) {
            has_special = 1;
        }
    }

    // Check if all the complexity requirements are met
    return has_uppercase && has_lowercase && has_digit && has_special;
}

// Function to calculate the strength of a password
int password_strength(char *password) {
    int complexity = password_is_complex(password);
    int length = strlen(password);

    // Calculate the strength of the password based on its complexity and length
    if (complexity == 0) {
        return WEAK;
    } else if (length < 12) {
        return MEDIUM;
    } else {
        return STRONG;
    }
}

// Function to get the password strength level as a string
char *password_strength_str(int strength) {
    switch (strength) {
        case WEAK:
            return "Weak";
        case MEDIUM:
            return "Medium";
        case STRONG:
            return "Strong";
        default:
            return "Invalid";
    }
}

// Main function
int main() {
    // Initialize the password
    char password[100];

    // Prompt the user to enter a password
    printf("Enter a password: ");
    scanf("%s", password);

    // Calculate the strength of the password
    int strength = password_strength(password);

    // Print the password strength
    printf("Password strength: %s\n", password_strength_str(strength));

    return 0;
}