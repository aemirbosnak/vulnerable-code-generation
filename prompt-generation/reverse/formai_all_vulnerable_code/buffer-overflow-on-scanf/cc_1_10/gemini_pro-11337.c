//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the minimum password length
#define MIN_LENGTH 8

// Define the maximum password length
#define MAX_LENGTH 64

// Define the character classes
#define CLASS_LOWER 0
#define CLASS_UPPER 1
#define CLASS_DIGIT 2
#define CLASS_SPECIAL 3

// Define the password strength levels
#define STRENGTH_WEAK 0
#define STRENGTH_MEDIUM 1
#define STRENGTH_STRONG 2

// Define the password strength messages
#define MSG_WEAK "Weak"
#define MSG_MEDIUM "Medium"
#define MSG_STRONG "Strong"

// Define the special characters
#define SPECIAL_CHARS "!@#$%^&*()_+=-`~[]\\;',./<>?"

// Check if a character is in a certain character class
int char_in_class(char c, int class) {
    switch (class) {
        case CLASS_LOWER:
            return islower(c);
        case CLASS_UPPER:
            return isupper(c);
        case CLASS_DIGIT:
            return isdigit(c);
        case CLASS_SPECIAL:
            return strchr(SPECIAL_CHARS, c) != NULL;
        default:
            return 0;
    }
}

// Check the strength of a password
int check_strength(char *password) {
    // Check the length of the password
    if (strlen(password) < MIN_LENGTH) {
        return STRENGTH_WEAK;
    } else if (strlen(password) > MAX_LENGTH) {
        return STRENGTH_WEAK;
    }

    // Check the character classes
    int classes = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (char_in_class(password[i], CLASS_LOWER)) {
            classes |= 1 << CLASS_LOWER;
        } else if (char_in_class(password[i], CLASS_UPPER)) {
            classes |= 1 << CLASS_UPPER;
        } else if (char_in_class(password[i], CLASS_DIGIT)) {
            classes |= 1 << CLASS_DIGIT;
        } else if (char_in_class(password[i], CLASS_SPECIAL)) {
            classes |= 1 << CLASS_SPECIAL;
        }
    }

    // Check the strength of the password
    if (classes == (1 << CLASS_LOWER) | (1 << CLASS_UPPER) | (1 << CLASS_DIGIT) | (1 << CLASS_SPECIAL)) {
        return STRENGTH_STRONG;
    } else if (classes == (1 << CLASS_LOWER) | (1 << CLASS_UPPER) | (1 << CLASS_DIGIT)) {
        return STRENGTH_MEDIUM;
    } else {
        return STRENGTH_WEAK;
    }
}

// Get the password strength message
char *get_strength_message(int strength) {
    switch (strength) {
        case STRENGTH_WEAK:
            return MSG_WEAK;
        case STRENGTH_MEDIUM:
            return MSG_MEDIUM;
        case STRENGTH_STRONG:
            return MSG_STRONG;
        default:
            return "Unknown";
    }
}

// Print the password strength
void print_strength(char *password) {
    int strength = check_strength(password);
    char *message = get_strength_message(strength);
    printf("Password strength: %s\n", message);
}

// Get the password from the user
char *get_password() {
    char *password = malloc(MAX_LENGTH + 1);
    printf("Enter your password: ");
    scanf("%s", password);
    return password;
}

// Main function
int main() {
    char *password = get_password();
    print_strength(password);
    free(password);
    return 0;
}