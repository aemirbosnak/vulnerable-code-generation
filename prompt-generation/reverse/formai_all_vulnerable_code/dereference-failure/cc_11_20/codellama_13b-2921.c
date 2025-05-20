//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: detailed
/*
 * Password Strength Checker
 *
 * Checks the strength of a given password
 *
 * Usage:
 *  - Enter the password as a command-line argument
 *  - The password will be checked for strength and the result will be displayed
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *password;
    int length;
    int uppercase, lowercase, numbers, special;

    // Check if a password is provided as a command-line argument
    if (argc < 2) {
        printf("Usage: password_strength <password>\n");
        return 1;
    }

    // Get the password from the command-line argument
    password = argv[1];
    length = strlen(password);

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            uppercase++;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            lowercase++;
        }
    }

    // Check for numbers
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            numbers++;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (password[i] >= '!' && password[i] <= '/') {
            special++;
        }
    }

    // Print the password strength
    printf("Password strength: ");
    if (length >= 8) {
        printf("Good\n");
    } else {
        printf("Weak\n");
    }
    if (uppercase > 0) {
        printf("Uppercase letters found\n");
    }
    if (lowercase > 0) {
        printf("Lowercase letters found\n");
    }
    if (numbers > 0) {
        printf("Numbers found\n");
    }
    if (special > 0) {
        printf("Special characters found\n");
    }

    return 0;
}