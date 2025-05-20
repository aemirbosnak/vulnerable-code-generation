//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: innovative
#include <stdio.h>
#include <string.h>

// Define the strength levels
#define STRENGTH_VERY_LOW 0
#define STRENGTH_LOW 1
#define STRENGTH_MEDIUM 2
#define STRENGTH_HIGH 3
#define STRENGTH_VERY_HIGH 4

// Define the character types
#define CHAR_TYPE_LOWER 0
#define CHAR_TYPE_UPPER 1
#define CHAR_TYPE_DIGIT 2
#define CHAR_TYPE_SYMBOL 3

// Define the minimum and maximum password lengths
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32

// Define the score calculation constants
#define SCORE_FOR_UPPER_CASE 10
#define SCORE_FOR_DIGIT 10
#define SCORE_FOR_SYMBOL 15
#define SCORE_FOR_LENGTH 5

// Function to check if a character is a lowercase letter
int is_lower_case(char c) {
    return (c >= 'a' && c <= 'z');
}

// Function to check if a character is an uppercase letter
int is_upper_case(char c) {
    return (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a digit
int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to check if a character is a symbol
int is_symbol(char c) {
    return (!is_lower_case(c) && !is_upper_case(c) && !is_digit(c));
}

// Function to calculate the strength of a password
int calculate_password_strength(char *password) {
    int score = 0;
    int i;

    // Check the length of the password
    if (strlen(password) < MIN_PASSWORD_LENGTH || strlen(password) > MAX_PASSWORD_LENGTH) {
        return STRENGTH_VERY_LOW;
    }

    // Check the character types in the password
    for (i = 0; i < strlen(password); i++) {
        if (is_upper_case(password[i])) {
            score += SCORE_FOR_UPPER_CASE;
        } else if (is_digit(password[i])) {
            score += SCORE_FOR_DIGIT;
        } else if (is_symbol(password[i])) {
            score += SCORE_FOR_SYMBOL;
        }
    }

    // Check the length of the password
    score += strlen(password) * SCORE_FOR_LENGTH;

    // Return the strength level
    if (score < 50) {
        return STRENGTH_VERY_LOW;
    } else if (score < 75) {
        return STRENGTH_LOW;
    } else if (score < 100) {
        return STRENGTH_MEDIUM;
    } else if (score < 125) {
        return STRENGTH_HIGH;
    } else {
        return STRENGTH_VERY_HIGH;
    }
}

// Function to display the strength of a password
void display_password_strength(char *password) {
    int strength = calculate_password_strength(password);

    switch (strength) {
        case STRENGTH_VERY_LOW:
            printf("Very Weak Password.\n");
            break;
        case STRENGTH_LOW:
            printf("Weak Password.\n");
            break;
        case STRENGTH_MEDIUM:
            printf("Medium Password.\n");
            break;
        case STRENGTH_HIGH:
            printf("Strong Password.\n");
            break;
        case STRENGTH_VERY_HIGH:
            printf("Very Strong Password.\n");
            break;
    }
}

// Main function
int main() {
    char password[MAX_PASSWORD_LENGTH + 1];

    // Prompt the user to enter a password
    printf("Enter Password: ");
    scanf("%s", password);

    // Display the strength of the password
    display_password_strength(password);

    return 0;
}