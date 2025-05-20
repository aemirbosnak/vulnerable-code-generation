//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: realistic
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 32
#define MIN_PASSWORD_LENGTH 8

// Function to check if a password is strong enough
int is_password_strong(char *password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_char = 0;

    // Check if password contains at least one uppercase letter
    if (isupper(password[0])) {
        has_uppercase = 1;
    }

    // Check if password contains at least one lowercase letter
    if (islower(password[0])) {
        has_lowercase = 1;
    }

    // Check if password contains at least one number
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_number = 1;
            break;
        }
    }

    // Check if password contains at least one special character
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_special_char = 1;
            break;
        }
    }

    // Check if password is long enough
    if (length < MIN_PASSWORD_LENGTH) {
        return 0;
    }

    // Check if password meets all strength criteria
    if (has_uppercase && has_lowercase && has_number && has_special_char) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    // Prompt user for password
    printf("Enter your password: ");
    scanf("%s", password);

    // Check if password is strong enough
    if (is_password_strong(password)) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is weak. Please choose a stronger password.\n");
    }

    return 0;
}