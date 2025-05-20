//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the minimum password length
#define MIN_PASS_LEN 8

// Define the maximum password length
#define MAX_PASS_LEN 64

// Define the character classes
#define CHAR_CLASS_LOWER 1
#define CHAR_CLASS_UPPER 2
#define CHAR_CLASS_DIGIT 4
#define CHAR_CLASS_SYMBOL 8

// Define the password strength levels
#define PASS_STRENGTH_WEAK 1
#define PASS_STRENGTH_MEDIUM 2
#define PASS_STRENGTH_STRONG 3

// Define the password strength messages
#define PASS_STRENGTH_WEAK_MSG "Weak password"
#define PASS_STRENGTH_MEDIUM_MSG "Medium password"
#define PASS_STRENGTH_STRONG_MSG "Strong password"

// Function to check if a character is in a given character class
int is_char_in_class(char ch, int char_class) {
    switch (char_class) {
        case CHAR_CLASS_LOWER:
            return islower(ch);
        case CHAR_CLASS_UPPER:
            return isupper(ch);
        case CHAR_CLASS_DIGIT:
            return isdigit(ch);
        case CHAR_CLASS_SYMBOL:
            return ispunct(ch);
        default:
            return 0;
    }
}

// Function to check the strength of a password
int check_password_strength(char *password) {
    int password_len = strlen(password);

    // Check if the password is too short
    if (password_len < MIN_PASS_LEN) {
        return PASS_STRENGTH_WEAK;
    }

    // Check if the password is too long
    if (password_len > MAX_PASS_LEN) {
        return PASS_STRENGTH_WEAK;
    }

    // Check if the password contains at least one character from each character class
    int char_classes_present = 0;
    for (int i = 0; i < password_len; i++) {
        char ch = password[i];
        if (is_char_in_class(ch, CHAR_CLASS_LOWER)) {
            char_classes_present |= CHAR_CLASS_LOWER;
        } else if (is_char_in_class(ch, CHAR_CLASS_UPPER)) {
            char_classes_present |= CHAR_CLASS_UPPER;
        } else if (is_char_in_class(ch, CHAR_CLASS_DIGIT)) {
            char_classes_present |= CHAR_CLASS_DIGIT;
        } else if (is_char_in_class(ch, CHAR_CLASS_SYMBOL)) {
            char_classes_present |= CHAR_CLASS_SYMBOL;
        }
    }

    if (char_classes_present != (CHAR_CLASS_LOWER | CHAR_CLASS_UPPER | CHAR_CLASS_DIGIT | CHAR_CLASS_SYMBOL)) {
        return PASS_STRENGTH_WEAK;
    }

    // Check if the password contains any consecutive repeated characters
    for (int i = 0; i < password_len - 1; i++) {
        if (password[i] == password[i + 1]) {
            return PASS_STRENGTH_WEAK;
        }
    }

    // The password is strong
    return PASS_STRENGTH_STRONG;
}

// Main function
int main() {
    // Get the password from the user
    char password[MAX_PASS_LEN + 1];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the strength of the password
    int password_strength = check_password_strength(password);

    // Print the password strength message
    switch (password_strength) {
        case PASS_STRENGTH_WEAK:
            printf("%s\n", PASS_STRENGTH_WEAK_MSG);
            break;
        case PASS_STRENGTH_MEDIUM:
            printf("%s\n", PASS_STRENGTH_MEDIUM_MSG);
            break;
        case PASS_STRENGTH_STRONG:
            printf("%s\n", PASS_STRENGTH_STRONG_MSG);
            break;
    }

    return 0;
}