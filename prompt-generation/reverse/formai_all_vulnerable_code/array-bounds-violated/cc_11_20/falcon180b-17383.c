//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 64

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int password_length;
    int uppercase_count = 0;
    int lowercase_count = 0;
    int digit_count = 0;
    int special_count = 0;

    printf("Enter your password: ");
    fgets(password, MAX_PASSWORD_LENGTH + 1, stdin);
    password_length = strlen(password);

    // Remove newline character from input
    password[password_length - 1] = '\0';

    // Check for minimum password length
    if (password_length < MIN_PASSWORD_LENGTH) {
        printf("Password must be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
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

    // Check for at least one uppercase letter
    if (uppercase_count == 0) {
        printf("Password must contain at least one uppercase letter.\n");
        return 1;
    }

    // Check for at least one lowercase letter
    if (lowercase_count == 0) {
        printf("Password must contain at least one lowercase letter.\n");
        return 1;
    }

    // Check for at least one digit
    if (digit_count == 0) {
        printf("Password must contain at least one digit.\n");
        return 1;
    }

    // Check for at least one special character
    if (special_count == 0) {
        printf("Password must contain at least one special character.\n");
        return 1;
    }

    printf("Password is strong.\n");
    return 0;
}