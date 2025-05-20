//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define password complexity criteria
#define MIN_LENGTH 8
#define MAX_LENGTH 64
#define MIN_UPPERCASE 1
#define MIN_LOWERCASE 1
#define MIN_DIGITS 1
#define MIN_SPECIAL_CHARS 1

// Define password score calculation factors
#define UPPERCASE_FACTOR 2
#define LOWERCASE_FACTOR 2
#define DIGIT_FACTOR 3
#define SPECIAL_CHAR_FACTOR 5

// Define error messages
#define ERR_INVALID_LENGTH "Password must be between 8 and 64 characters long."
#define ERR_MISSING_UPPERCASE "Password must contain at least 1 uppercase letter."
#define ERR_MISSING_LOWERCASE "Password must contain at least 1 lowercase letter."
#define ERR_MISSING_DIGITS "Password must contain at least 1 digit."
#define ERR_MISSING_SPECIAL_CHARS "Password must contain at least 1 special character."

// Function to check password strength
int check_password_strength(char* password) {
    int score = 0;
    int length = strlen(password);

    // Check password length
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        return ERR_INVALID_LENGTH;
    }

    // Check for uppercase letters
    int uppercase_count = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            uppercase_count++;
        }
    }

    if (uppercase_count < MIN_UPPERCASE) {
        return ERR_MISSING_UPPERCASE;
    }

    score += uppercase_count * UPPERCASE_FACTOR;

    // Check for lowercase letters
    int lowercase_count = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            lowercase_count++;
        }
    }

    if (lowercase_count < MIN_LOWERCASE) {
        return ERR_MISSING_LOWERCASE;
    }

    score += lowercase_count * LOWERCASE_FACTOR;

    // Check for digits
    int digit_count = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            digit_count++;
        }
    }

    if (digit_count < MIN_DIGITS) {
        return ERR_MISSING_DIGITS;
    }

    score += digit_count * DIGIT_FACTOR;

    // Check for special characters
    int special_char_count = 0;
    for (int i = 0; i < length; i++) {
        if (!((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= '0' && password[i] <= '9'))) {
            special_char_count++;
        }
    }

    if (special_char_count < MIN_SPECIAL_CHARS) {
        return ERR_MISSING_SPECIAL_CHARS;
    }

    score += special_char_count * SPECIAL_CHAR_FACTOR;

    return score;
}

// Function to print password strength assessment
void print_password_strength(int score) {
    if (score < 10) {
        printf("Password strength: Very weak\n");
    } else if (score < 20) {
        printf("Password strength: Weak\n");
    } else if (score < 30) {
        printf("Password strength: Fair\n");
    } else if (score < 40) {
        printf("Password strength: Strong\n");
    } else {
        printf("Password strength: Very strong\n");
    }
}

// Main function
int main() {
    char password[MAX_LENGTH + 1];

    // Prompt user for password
    printf("Enter password: ");
    scanf("%s", password);

    // Check password strength
    int score = check_password_strength(password);

    // Print password strength assessment
    if (score < 0) {
        printf("Error: %s\n", score);
    } else {
        printf("Password strength: ");
        print_password_strength(score);
    }

    return 0;
}