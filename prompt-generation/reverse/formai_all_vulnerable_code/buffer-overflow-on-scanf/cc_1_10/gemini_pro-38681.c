//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the password strength levels
#define WEAK 0
#define MEDIUM 1
#define STRONG 2

// Define the minimum password length
#define MIN_LENGTH 8

// Define the maximum password length
#define MAX_LENGTH 64

// Define the character classes
#define UPPERCASE 1
#define LOWERCASE 2
#define DIGIT 4
#define SYMBOL 8

// Define the password strength calculation function
int calculate_password_strength(char *password) {
    // Initialize the password strength to weak
    int strength = WEAK;

    // Check the password length
    if (strlen(password) < MIN_LENGTH) {
        return strength;
    }

    // Check if the password contains uppercase characters
    if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") != NULL) {
        strength |= UPPERCASE;
    }

    // Check if the password contains lowercase characters
    if (strpbrk(password, "abcdefghijklmnopqrstuvwxyz") != NULL) {
        strength |= LOWERCASE;
    }

    // Check if the password contains digits
    if (strpbrk(password, "0123456789") != NULL) {
        strength |= DIGIT;
    }

    // Check if the password contains symbols
    if (strpbrk(password, "!@#$%^&*()-_=+[]{}\\|;:'\",<.>/?") != NULL) {
        strength |= SYMBOL;
    }

    // Return the password strength
    return strength;
}

// Define the main function
int main() {
    // Get the password from the user
    char password[MAX_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    // Calculate the password strength
    int strength = calculate_password_strength(password);

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
    }

    return 0;
}