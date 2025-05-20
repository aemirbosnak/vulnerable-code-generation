//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 64

// Define the character classes
#define CHAR_CLASS_LOWER 0x01
#define CHAR_CLASS_UPPER 0x02
#define CHAR_CLASS_DIGIT 0x04
#define CHAR_CLASS_SYMBOL 0x08

// Define the password strength levels
#define PASSWORD_STRENGTH_WEAK 0
#define PASSWORD_STRENGTH_MEDIUM 1
#define PASSWORD_STRENGTH_STRONG 2

// Function to check if a character is in a given character class
int char_in_class(char c, int char_class) {
    switch (char_class) {
        case CHAR_CLASS_LOWER:
            return (c >= 'a' && c <= 'z');
        case CHAR_CLASS_UPPER:
            return (c >= 'A' && c <= 'Z');
        case CHAR_CLASS_DIGIT:
            return (c >= '0' && c <= '9');
        case CHAR_CLASS_SYMBOL:
            return (c >= '!' && c <= '~');
        default:
            return 0;
    }
}

// Function to check the strength of a password
int check_password_strength(char *password) {
    int password_length = strlen(password);

    // Check if the password is too short
    if (password_length < MIN_PASSWORD_LENGTH) {
        return PASSWORD_STRENGTH_WEAK;
    }

    // Check if the password is too long
    if (password_length > MAX_PASSWORD_LENGTH) {
        return PASSWORD_STRENGTH_WEAK;
    }

    // Check if the password contains at least one character from each character class
    int char_classes = 0;
    for (int i = 0; i < password_length; i++) {
        char c = password[i];
        char_classes |= char_in_class(c, CHAR_CLASS_LOWER) | char_in_class(c, CHAR_CLASS_UPPER) | char_in_class(c, CHAR_CLASS_DIGIT) | char_in_class(c, CHAR_CLASS_SYMBOL);
    }

    // Check if the password is strong enough
    if (char_classes == 0x0F) {
        return PASSWORD_STRENGTH_STRONG;
    } else if (char_classes >= 0x07) {
        return PASSWORD_STRENGTH_MEDIUM;
    } else {
        return PASSWORD_STRENGTH_WEAK;
    }
}

// Function to get the password from the user
char *get_password() {
    char *password = malloc(MAX_PASSWORD_LENGTH + 1);

    printf("Enter your password: ");
    scanf("%s", password);

    return password;
}

// Function to print the password strength
void print_password_strength(int password_strength) {
    switch (password_strength) {
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
}

int main() {
    // Get the password from the user
    char *password = get_password();

    // Check the strength of the password
    int password_strength = check_password_strength(password);

    // Print the password strength
    print_password_strength(password_strength);

    // Free the memory allocated for the password
    free(password);

    return 0;
}