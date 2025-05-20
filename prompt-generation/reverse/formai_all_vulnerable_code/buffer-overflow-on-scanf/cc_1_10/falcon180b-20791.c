//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: complex
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 100

// Function to check if a character is a letter
int is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a digit
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Function to check if a character is a special character
int is_special(char c) {
    return!(is_letter(c) || is_digit(c));
}

// Function to check if a password is strong
int is_strong_password(char *password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special = 0;

    // Check for uppercase letter
    for (int i = 0; i < length; i++) {
        if (is_letter(password[i]) && isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }

    // Check for lowercase letter
    for (int i = 0; i < length; i++) {
        if (is_letter(password[i]) && islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }

    // Check for digit
    for (int i = 0; i < length; i++) {
        if (is_digit(password[i])) {
            has_digit = 1;
            break;
        }
    }

    // Check for special character
    for (int i = 0; i < length; i++) {
        if (is_special(password[i])) {
            has_special = 1;
            break;
        }
    }

    // Check if password meets all criteria
    if (length >= 8 && has_uppercase && has_lowercase && has_digit && has_special) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[MAX_LENGTH];

    // Get password from user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check if password is strong
    if (is_strong_password(password)) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is weak.\n");
    }

    return 0;
}