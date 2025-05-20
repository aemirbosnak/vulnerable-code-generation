//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: shocked
/*
 * Unique C Password Strength Checker example program in a shocked style
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 128

int main(void) {
    char password[MAX_PASSWORD_LENGTH];
    int password_length;
    int password_strength;

    printf("Enter a password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password_length = strlen(password);

    // Check for uppercase letters
    if (password_length > 1 && strchr(password, toupper(password[0]))) {
        password_strength++;
    }

    // Check for lowercase letters
    if (password_length > 1 && strchr(password, tolower(password[0]))) {
        password_strength++;
    }

    // Check for numbers
    if (password_length > 1 && strchr(password, '0') || strchr(password, '1') || strchr(password, '2') || strchr(password, '3') || strchr(password, '4') || strchr(password, '5') || strchr(password, '6') || strchr(password, '7') || strchr(password, '8') || strchr(password, '9')) {
        password_strength++;
    }

    // Check for special characters
    if (password_length > 1 && strchr(password, '!') || strchr(password, '@') || strchr(password, '#') || strchr(password, '$') || strchr(password, '%') || strchr(password, '^') || strchr(password, '&') || strchr(password, '*') || strchr(password, '-') || strchr(password, '+') || strchr(password, '=') || strchr(password, '?') || strchr(password, '/') || strchr(password, '~') || strchr(password, '`')) {
        password_strength++;
    }

    // Print the password strength
    if (password_strength == 0) {
        printf("Your password is too weak! Try again.\n");
    } else if (password_strength == 1) {
        printf("Your password is weak. Try adding a few more characters.\n");
    } else if (password_strength == 2) {
        printf("Your password is okay, but could be stronger.\n");
    } else if (password_strength == 3) {
        printf("Your password is strong, but could be even stronger.\n");
    } else if (password_strength == 4) {
        printf("Your password is very strong!\n");
    }

    return 0;
}