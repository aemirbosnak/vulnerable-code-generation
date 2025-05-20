//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 64

// Define the password scoring criteria
#define SCORE_UPPERCASE 10
#define SCORE_LOWERCASE 10
#define SCORE_NUMBER 10
#define SCORE_SYMBOL 15

// Define the password strength levels
#define STRENGTH_WEAK 0
#define STRENGTH_MEDIUM 1
#define STRENGTH_STRONG 2

// Function to check if a character is uppercase
int is_uppercase(char character) {
    return character >= 'A' && character <= 'Z';
}

// Function to check if a character is lowercase
int is_lowercase(char character) {
    return character >= 'a' && character <= 'z';
}

// Function to check if a character is a number
int is_number(char character) {
    return character >= '0' && character <= '9';
}

// Function to check if a character is a symbol
int is_symbol(char character) {
    return !is_uppercase(character) && !is_lowercase(character) && !is_number(character);
}

// Function to calculate the password score
int calculate_password_score(char *password) {
    int score = 0;

    // Check for uppercase characters
    for (int i = 0; i < strlen(password); i++) {
        if (is_uppercase(password[i])) {
            score += SCORE_UPPERCASE;
        }
    }

    // Check for lowercase characters
    for (int i = 0; i < strlen(password); i++) {
        if (is_lowercase(password[i])) {
            score += SCORE_LOWERCASE;
        }
    }

    // Check for numbers
    for (int i = 0; i < strlen(password); i++) {
        if (is_number(password[i])) {
            score += SCORE_NUMBER;
        }
    }

    // Check for symbols
    for (int i = 0; i < strlen(password); i++) {
        if (is_symbol(password[i])) {
            score += SCORE_SYMBOL;
        }
    }

    // Return the password score
    return score;
}

// Function to determine the password strength
int determine_password_strength(int score) {
    if (score < 50) {
        return STRENGTH_WEAK;
    } else if (score >= 50 && score < 75) {
        return STRENGTH_MEDIUM;
    } else {
        return STRENGTH_STRONG;
    }
}

// Main function
int main() {
    // Declare variables
    char password[MAX_PASSWORD_LENGTH + 1];
    int score;
    int strength;

    // Prompt the user to enter a password
    printf("Enter a password: ");
    scanf("%s", password);

    // Check if the password is valid
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        printf("Password must be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
        return 1;
    } else if (strlen(password) > MAX_PASSWORD_LENGTH) {
        printf("Password must be at most %d characters long.\n", MAX_PASSWORD_LENGTH);
        return 1;
    }

    // Calculate the password score
    score = calculate_password_score(password);

    // Determine the password strength
    strength = determine_password_strength(score);

    // Print the password score and strength
    printf("Password score: %d\n", score);
    printf("Password strength: ");
    switch (strength) {
        case STRENGTH_WEAK:
            printf("Weak\n");
            break;
        case STRENGTH_MEDIUM:
            printf("Medium\n");
            break;
        case STRENGTH_STRONG:
            printf("Strong\n");
            break;
    }

    return 0;
}