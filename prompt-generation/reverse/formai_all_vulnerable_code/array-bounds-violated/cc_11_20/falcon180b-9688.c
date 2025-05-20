//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Dennis Ritchie
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special_char = 0;

    // Get password from user
    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    // Remove trailing newline character
    length = strlen(password) - 1;
    password[length] = '\0';

    // Check password length
    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 1;
    }

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }

    // Check for digits
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_digit = 1;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_special_char = 1;
            break;
        }
    }

    // Check for all four criteria
    if (has_uppercase && has_lowercase && has_digit && has_special_char) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}