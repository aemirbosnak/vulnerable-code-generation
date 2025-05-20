//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 64

// Define the character classes
#define CHAR_CLASS_LOWERCASE 0
#define CHAR_CLASS_UPPERCASE 1
#define CHAR_CLASS_DIGIT 2
#define CHAR_CLASS_SPECIAL 3

// Define the password strength levels
#define PASSWORD_STRENGTH_WEAK 0
#define PASSWORD_STRENGTH_MEDIUM 1
#define PASSWORD_STRENGTH_STRONG 2

// Define the password strength messages
char *password_strength_messages[] = {
    "Weak",
    "Medium",
    "Strong"
};

// Check if a character is lowercase
int is_lowercase(char c) {
    return (c >= 'a' && c <= 'z');
}

// Check if a character is uppercase
int is_uppercase(char c) {
    return (c >= 'A' && c <= 'Z');
}

// Check if a character is a digit
int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

// Check if a character is a special character
int is_special(char c) {
    return (!is_lowercase(c) && !is_uppercase(c) && !is_digit(c));
}

// Get the character class of a character
int get_char_class(char c) {
    if (is_lowercase(c)) {
        return CHAR_CLASS_LOWERCASE;
    } else if (is_uppercase(c)) {
        return CHAR_CLASS_UPPERCASE;
    } else if (is_digit(c)) {
        return CHAR_CLASS_DIGIT;
    } else {
        return CHAR_CLASS_SPECIAL;
    }
}

// Check the strength of a password
int check_password_strength(char *password) {
    // Check the password length
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        return PASSWORD_STRENGTH_WEAK;
    } else if (strlen(password) > MAX_PASSWORD_LENGTH) {
        return PASSWORD_STRENGTH_WEAK;
    }

    // Check the password character classes
    int char_classes[CHAR_CLASS_SPECIAL + 1] = {0};
    for (int i = 0; i < strlen(password); i++) {
        char_classes[get_char_class(password[i])]++;
    }

    int num_char_classes = 0;
    for (int i = 0; i < CHAR_CLASS_SPECIAL + 1; i++) {
        if (char_classes[i] > 0) {
            num_char_classes++;
        }
    }

    // Check the password strength
    if (num_char_classes < 3) {
        return PASSWORD_STRENGTH_WEAK;
    } else if (num_char_classes == 3) {
        return PASSWORD_STRENGTH_MEDIUM;
    } else {
        return PASSWORD_STRENGTH_STRONG;
    }
}

// Get the password strength message
char *get_password_strength_message(int password_strength) {
    return password_strength_messages[password_strength];
}

// Main function
int main() {
    // Get the password from the user
    char password[MAX_PASSWORD_LENGTH + 1];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the password strength
    int password_strength = check_password_strength(password);

    // Get the password strength message
    char *password_strength_message = get_password_strength_message(password_strength);

    // Print the password strength message
    printf("Your password strength is: %s\n", password_strength_message);

    return 0;
}