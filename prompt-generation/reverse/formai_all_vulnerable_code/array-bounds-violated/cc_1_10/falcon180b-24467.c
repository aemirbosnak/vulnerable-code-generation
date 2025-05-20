//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32

int is_valid_password(char *password);

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int password_length;

    printf("Enter a password: ");
    fgets(password, MAX_PASSWORD_LENGTH + 1, stdin);
    password_length = strlen(password);

    // Remove newline character from input
    password[--password_length] = '\0';

    if (is_valid_password(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}

int is_valid_password(char *password) {
    int lowercase_count = 0;
    int uppercase_count = 0;
    int digit_count = 0;
    int special_character_count = 0;

    for (int i = 0; i < strlen(password); i++) {
        if (isalpha(password[i])) {
            if (islower(password[i])) {
                lowercase_count++;
            } else {
                uppercase_count++;
            }
        } else if (isdigit(password[i])) {
            digit_count++;
        } else {
            special_character_count++;
        }
    }

    // Check for minimum length
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        return 0;
    }

    // Check for lowercase letters
    if (lowercase_count == 0) {
        return 0;
    }

    // Check for uppercase letters
    if (uppercase_count == 0) {
        return 0;
    }

    // Check for digits
    if (digit_count == 0) {
        return 0;
    }

    // Check for special characters
    if (special_character_count == 0) {
        return 0;
    }

    return 1;
}