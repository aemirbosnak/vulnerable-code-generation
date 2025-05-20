//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 32

int main(void) {
    char password[MAX_PASSWORD_LENGTH + 1];
    int password_length;
    int uppercase_count = 0;
    int lowercase_count = 0;
    int digit_count = 0;
    int special_count = 0;

    printf("Enter your password: ");
    fgets(password, MAX_PASSWORD_LENGTH + 1, stdin);
    password_length = strlen(password);

    // Remove trailing newline character
    password[--password_length] = '\0';

    // Check for empty password
    if (password_length == 0) {
        printf("Password is empty.\n");
        return 1;
    }

    // Check for password length
    if (password_length < 8) {
        printf("Password is too short.\n");
        return 1;
    }

    // Check for uppercase letters
    for (int i = 0; i < password_length; i++) {
        if (isupper(password[i])) {
            uppercase_count++;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < password_length; i++) {
        if (islower(password[i])) {
            lowercase_count++;
        }
    }

    // Check for digits
    for (int i = 0; i < password_length; i++) {
        if (isdigit(password[i])) {
            digit_count++;
        }
    }

    // Check for special characters
    for (int i = 0; i < password_length; i++) {
        if (!isalnum(password[i])) {
            special_count++;
        }
    }

    // Check password strength
    if (uppercase_count && lowercase_count && digit_count && special_count) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}