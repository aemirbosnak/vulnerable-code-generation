//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 256

// Define the character classes
#define CLASS_UPPERCASE 0x01
#define CLASS_LOWERCASE 0x02
#define CLASS_DIGIT 0x04
#define CLASS_SPECIAL 0x08

// Define the password strength levels
#define STRENGTH_WEAK 0
#define STRENGTH_MEDIUM 1
#define STRENGTH_STRONG 2

// Check if a character is uppercase
int is_uppercase(char c) {
    return c >= 'A' && c <= 'Z';
}

// Check if a character is lowercase
int is_lowercase(char c) {
    return c >= 'a' && c <= 'z';
}

// Check if a character is a digit
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Check if a character is a special character
int is_special(char c) {
    return !is_uppercase(c) && !is_lowercase(c) && !is_digit(c);
}

// Calculate the password strength
int calculate_password_strength(char *password) {
    int strength = 0;

    // Check the password length
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        return STRENGTH_WEAK;
    } else if (strlen(password) > MAX_PASSWORD_LENGTH) {
        return STRENGTH_WEAK;
    }

    // Check the character classes
    int classes = 0;
    if (strchr(password, 'A') || strchr(password, 'Z')) {
        classes |= CLASS_UPPERCASE;
    }
    if (strchr(password, 'a') || strchr(password, 'z')) {
        classes |= CLASS_LOWERCASE;
    }
    if (strchr(password, '0') || strchr(password, '9')) {
        classes |= CLASS_DIGIT;
    }
    if (strchr(password, '!') || strchr(password, '@') || strchr(password, '#') || strchr(password, '$') || strchr(password, '%') || strchr(password, '^') || strchr(password, '&') || strchr(password, '*')) {
        classes |= CLASS_SPECIAL;
    }

    // Calculate the strength based on the number of character classes
    switch (classes) {
        case CLASS_UPPERCASE | CLASS_LOWERCASE | CLASS_DIGIT | CLASS_SPECIAL:
            strength = STRENGTH_STRONG;
            break;
        case CLASS_UPPERCASE | CLASS_LOWERCASE | CLASS_DIGIT:
        case CLASS_UPPERCASE | CLASS_LOWERCASE | CLASS_SPECIAL:
        case CLASS_LOWERCASE | CLASS_DIGIT | CLASS_SPECIAL:
            strength = STRENGTH_MEDIUM;
            break;
        default:
            strength = STRENGTH_WEAK;
            break;
    }

    return strength;
}

// Print the password strength
void print_password_strength(int strength) {
    switch (strength) {
        case STRENGTH_WEAK:
            printf("Weak password\n");
            break;
        case STRENGTH_MEDIUM:
            printf("Medium password\n");
            break;
        case STRENGTH_STRONG:
            printf("Strong password\n");
            break;
    }
}

// Get a password from the user
char *get_password() {
    char *password = malloc(MAX_PASSWORD_LENGTH + 1);
    printf("Enter a password: ");
    scanf("%s", password);
    return password;
}

// Main function
int main() {
    // Get a password from the user
    char *password = get_password();

    // Calculate the password strength
    int strength = calculate_password_strength(password);

    // Print the password strength
    print_password_strength(strength);

    // Free the memory allocated for the password
    free(password);

    return 0;
}