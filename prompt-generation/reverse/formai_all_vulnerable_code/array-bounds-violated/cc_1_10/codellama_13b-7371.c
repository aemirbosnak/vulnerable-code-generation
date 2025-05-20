//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: curious
/*
 * C Password Strength Checker Example Program
 *
 * Checks the strength of a password and provides feedback
 * on its complexity.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 32

// Define the number of required character classes
#define REQUIRED_CHAR_CLASSES 3

// Define the required character classes
#define REQUIRED_LOWERCASE 0
#define REQUIRED_UPPERCASE 1
#define REQUIRED_DIGITS 2
#define REQUIRED_SPECIAL 3

// Define the character class flags
#define LOWERCASE 0x01
#define UPPERCASE 0x02
#define DIGITS 0x04
#define SPECIAL 0x08

// Define the special characters
#define SPECIAL_CHARS "!@#$%^&*()"

// Define the feedback messages
#define FEEDBACK_WEAK "Password is too weak."
#define FEEDBACK_MEDIUM "Password is medium-strength."
#define FEEDBACK_STRONG "Password is strong."
#define FEEDBACK_EXCELLENT "Password is excellent!"

// Define the function to check the password strength
void check_password_strength(char *password) {
    // Initialize the character class flags
    int flags = 0;

    // Check the password length
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        printf("%s\n", FEEDBACK_WEAK);
        return;
    }

    // Check the required character classes
    for (int i = 0; i < strlen(password); i++) {
        // Check for lowercase characters
        if (islower(password[i])) {
            flags |= LOWERCASE;
        }

        // Check for uppercase characters
        if (isupper(password[i])) {
            flags |= UPPERCASE;
        }

        // Check for digits
        if (isdigit(password[i])) {
            flags |= DIGITS;
        }

        // Check for special characters
        if (strchr(SPECIAL_CHARS, password[i])) {
            flags |= SPECIAL;
        }
    }

    // Check if all required character classes are present
    if (flags != (LOWERCASE | UPPERCASE | DIGITS | SPECIAL)) {
        printf("%s\n", FEEDBACK_WEAK);
        return;
    }

    // Check the password length again
    if (strlen(password) > MAX_PASSWORD_LENGTH) {
        printf("%s\n", FEEDBACK_STRONG);
        return;
    }

    // Check if the password is strong
    if (strlen(password) >= MIN_PASSWORD_LENGTH) {
        printf("%s\n", FEEDBACK_EXCELLENT);
        return;
    }

    // Check if the password is medium-strength
    if (strlen(password) > MIN_PASSWORD_LENGTH && strlen(password) < MAX_PASSWORD_LENGTH) {
        printf("%s\n", FEEDBACK_MEDIUM);
        return;
    }

    // Print a generic feedback message
    printf("%s\n", FEEDBACK_WEAK);
}

// Define the main function
int main() {
    // Get the password from the user
    char password[MAX_PASSWORD_LENGTH + 1];
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);

    // Remove the newline character from the end of the password
    password[strlen(password) - 1] = '\0';

    // Check the password strength
    check_password_strength(password);

    return 0;
}