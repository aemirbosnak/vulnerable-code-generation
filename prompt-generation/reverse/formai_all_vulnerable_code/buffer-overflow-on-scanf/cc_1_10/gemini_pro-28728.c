//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: relaxed
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
#define PASSWORD_STRENGTH_WEAK_MESSAGE "Weak"
#define PASSWORD_STRENGTH_MEDIUM_MESSAGE "Medium"
#define PASSWORD_STRENGTH_STRONG_MESSAGE "Strong"

// Function to check if a character belongs to a certain character class
int char_class(char c) {
    if (c >= 'a' && c <= 'z') {
        return CHAR_CLASS_LOWERCASE;
    } else if (c >= 'A' && c <= 'Z') {
        return CHAR_CLASS_UPPERCASE;
    } else if (c >= '0' && c <= '9') {
        return CHAR_CLASS_DIGIT;
    } else {
        return CHAR_CLASS_SPECIAL;
    }
}

// Function to calculate the password strength
int password_strength(char *password) {
    // Check if the password is long enough
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        return PASSWORD_STRENGTH_WEAK;
    }

    // Check if the password contains at least one character from each character class
    int char_classes[4] = {0, 0, 0, 0};
    for (int i = 0; i < strlen(password); i++) {
        char_classes[char_class(password[i])] = 1;
    }
    int num_char_classes = 0;
    for (int i = 0; i < 4; i++) {
        num_char_classes += char_classes[i];
    }
    if (num_char_classes < 3) {
        return PASSWORD_STRENGTH_WEAK;
    }

    // Check if the password contains any sequential characters
    for (int i = 0; i < strlen(password) - 1; i++) {
        if (password[i] + 1 == password[i + 1]) {
            return PASSWORD_STRENGTH_MEDIUM;
        }
    }

    // The password is strong
    return PASSWORD_STRENGTH_STRONG;
}

// Main function
int main() {
    // Get the password from the user
    char password[MAX_PASSWORD_LENGTH + 1];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the password strength
    int strength = password_strength(password);

    // Print the password strength message
    switch (strength) {
        case PASSWORD_STRENGTH_WEAK:
            printf("Your password is weak.\n");
            break;
        case PASSWORD_STRENGTH_MEDIUM:
            printf("Your password is medium.\n");
            break;
        case PASSWORD_STRENGTH_STRONG:
            printf("Your password is strong.\n");
            break;
    }

    return 0;
}