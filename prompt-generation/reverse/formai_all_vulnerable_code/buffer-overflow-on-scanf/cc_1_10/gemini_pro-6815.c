//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: detailed
#include <stdio.h>
#include <string.h>

// Define the minimum password length
#define MIN_LENGTH 8

// Define the maximum password length
#define MAX_LENGTH 20

// Define the character classes
#define CHAR_CLASS_LOWERCASE 0
#define CHAR_CLASS_UPPERCASE 1
#define CHAR_CLASS_DIGIT 2
#define CHAR_CLASS_SPECIAL 3

// Define the password strength levels
#define STRENGTH_LEVEL_WEAK 0
#define STRENGTH_LEVEL_MEDIUM 1
#define STRENGTH_LEVEL_STRONG 2

// Define the password strength requirements
#define REQUIREMENT_LENGTH 1
#define REQUIREMENT_LOWERCASE 2
#define REQUIREMENT_UPPERCASE 4
#define REQUIREMENT_DIGIT 8
#define REQUIREMENT_SPECIAL 16

// Function to check if a character is lowercase
int is_lowercase(char c) {
    return (c >= 'a' && c <= 'z');
}

// Function to check if a character is uppercase
int is_uppercase(char c) {
    return (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a digit
int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to check if a character is a special character
int is_special(char c) {
    return (!is_lowercase(c) && !is_uppercase(c) && !is_digit(c));
}

// Function to calculate the password strength
int calculate_strength(char *password) {
    int strength = 0;

    // Check the password length
    if (strlen(password) >= MIN_LENGTH && strlen(password) <= MAX_LENGTH) {
        strength |= REQUIREMENT_LENGTH;
    }

    // Check for lowercase characters
    for (int i = 0; i < strlen(password); i++) {
        if (is_lowercase(password[i])) {
            strength |= REQUIREMENT_LOWERCASE;
            break;
        }
    }

    // Check for uppercase characters
    for (int i = 0; i < strlen(password); i++) {
        if (is_uppercase(password[i])) {
            strength |= REQUIREMENT_UPPERCASE;
            break;
        }
    }

    // Check for digits
    for (int i = 0; i < strlen(password); i++) {
        if (is_digit(password[i])) {
            strength |= REQUIREMENT_DIGIT;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < strlen(password); i++) {
        if (is_special(password[i])) {
            strength |= REQUIREMENT_SPECIAL;
            break;
        }
    }

    // Return the password strength
    return strength;
}

// Function to print the password strength level
void print_strength(int strength) {
    switch (strength) {
        case STRENGTH_LEVEL_WEAK:
            printf("Password strength: Weak\n");
            break;
        case STRENGTH_LEVEL_MEDIUM:
            printf("Password strength: Medium\n");
            break;
        case STRENGTH_LEVEL_STRONG:
            printf("Password strength: Strong\n");
            break;
        default:
            printf("Password strength: Invalid\n");
    }
}

// Main function
int main() {
    // Get the password from the user
    char password[MAX_LENGTH + 1];
    printf("Enter your password: ");
    scanf("%s", password);

    // Calculate the password strength
    int strength = calculate_strength(password);

    // Print the password strength level
    print_strength(strength);

    return 0;
}