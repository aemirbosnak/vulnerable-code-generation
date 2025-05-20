//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100
#define MAX_PASSWORD_SIZE 1000

// Function to check if the given password is strong enough
int is_password_strong(char *password) {
    int length = strlen(password);
    int uppercase = 0;
    int lowercase = 0;
    int number = 0;
    int special = 0;

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
            break;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
            break;
        }
    }

    // Check for numbers
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            number = 1;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            special = 1;
            break;
        }
    }

    // Check if the password contains at least one uppercase letter, one lowercase letter, one number, and one special character
    if (uppercase && lowercase && number && special) {
        return 1; // Password is strong
    } else {
        return 0; // Password is weak
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    // Prompt the user to enter a password
    printf("Enter a password: ");
    if (fgets(password, MAX_PASSWORD_SIZE, stdin) == NULL) {
        printf("Error: Password too long.\n");
        return 1;
    }

    // Remove newline character from password
    int length = strlen(password);
    if (password[length - 1] == '\n') {
        password[length - 1] = '\0';
    }

    // Check if the password is strong
    int result = is_password_strong(password);

    if (result) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}