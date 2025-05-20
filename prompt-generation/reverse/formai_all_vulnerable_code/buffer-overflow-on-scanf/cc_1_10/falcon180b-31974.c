//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

// Function to check if character is a letter
int is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to check if character is a digit
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Function to check if character is a special character
int is_special(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '?' || c == '-' || c == '+');
}

// Function to check if password is valid
int is_valid_password(char *password) {
    int length = strlen(password);
    int has_letter = 0;
    int has_digit = 0;
    int has_special = 0;

    // Check for letter
    for (int i = 0; i < length; i++) {
        if (is_letter(password[i])) {
            has_letter = 1;
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

    // Check if password contains at least one letter, one digit, and one special character
    if (has_letter && has_digit && has_special) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[MAX_LENGTH];

    // Prompt user for password
    printf("Enter password: ");
    scanf("%s", password);

    // Check if password is valid
    if (is_valid_password(password)) {
        printf("Password is valid.\n");
    } else {
        printf("Password is not valid.\n");
    }

    return 0;
}