//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 64

// Define the number of password strength levels
#define NUM_PASSWORD_STRENGTH_LEVELS 5

// Define the password strength level names
const char *password_strength_level_names[] = {
    "Very Weak",
    "Weak",
    "Moderate",
    "Strong",
    "Very Strong"
};

// Define the password strength level scores
const int password_strength_level_scores[] = {
    0,
    10,
    20,
    30,
    40
};

// Define the password strength level descriptions
const char *password_strength_level_descriptions[] = {
    "A very weak password is easy to guess and should be changed immediately.",
    "A weak password is not very difficult to guess and should be changed soon.",
    "A moderate password is somewhat difficult to guess but could be improved.",
    "A strong password is difficult to guess and should be changed periodically.",
    "A very strong password is very difficult to guess and should be changed only if necessary."
};

// Define the password strength check function
int check_password_strength(const char *password) {
    // Check the password length
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        return 0;
    } else if (strlen(password) > MAX_PASSWORD_LENGTH) {
        return 0;
    }

    // Check the password for uppercase letters
    int has_uppercase_letter = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            has_uppercase_letter = 1;
            break;
        }
    }

    // Check the password for lowercase letters
    int has_lowercase_letter = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            has_lowercase_letter = 1;
            break;
        }
    }

    // Check the password for digits
    int has_digit = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            has_digit = 1;
            break;
        }
    }

    // Check the password for special characters
    int has_special_character = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            has_special_character = 1;
            break;
        }
    }

    // Calculate the password strength score
    int password_strength_score = 0;
    if (has_uppercase_letter) {
        password_strength_score += 10;
    }
    if (has_lowercase_letter) {
        password_strength_score += 10;
    }
    if (has_digit) {
        password_strength_score += 10;
    }
    if (has_special_character) {
        password_strength_score += 10;
    }
    if (strlen(password) >= 12) {
        password_strength_score += 10;
    }

    // Return the password strength level
    for (int i = 0; i < NUM_PASSWORD_STRENGTH_LEVELS; i++) {
        if (password_strength_score >= password_strength_level_scores[i]) {
            return i;
        }
    }

    return -1;
}

// Define the main function
int main(void) {
    // Get the password from the user
    char password[MAX_PASSWORD_LENGTH + 1];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the password strength
    int password_strength_level = check_password_strength(password);

    // Print the password strength level
    printf("Your password strength is: %s\n", password_strength_level_names[password_strength_level]);

    // Print the password strength level description
    printf("%s\n", password_strength_level_descriptions[password_strength_level]);

    return 0;
}