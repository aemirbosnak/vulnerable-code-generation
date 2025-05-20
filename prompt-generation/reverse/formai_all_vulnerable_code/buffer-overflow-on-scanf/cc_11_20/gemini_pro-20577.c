//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: curious
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A curious function to check the strength of a password
int checkPasswordStrength(char *password) {
    int strength = 0;

    // Iterate over the password and check for various criteria
    for (int i = 0; i < strlen(password); i++) {
        char c = password[i];

        // Check for uppercase letters
        if (c >= 'A' && c <= 'Z') {
            strength++;
        }

        // Check for lowercase letters
        else if (c >= 'a' && c <= 'z') {
            strength++;
        }

        // Check for digits
        else if (c >= '0' && c <= '9') {
            strength++;
        }

        // Check for special characters
        else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%') {
            strength++;
        }

        // Check for repeated characters
        if (i > 0 && c == password[i - 1]) {
            strength--;
        }
    }

    // Check for the length of the password
    if (strlen(password) < 8) {
        strength -= 2;
    } else if (strlen(password) >= 12) {
        strength++;
    }

    // Check for common passwords
    char *commonPasswords[] = {"password", "123456", "12345678", "123456789", "qwerty"};
    for (int i = 0; i < 5; i++) {
        if (strcmp(password, commonPasswords[i]) == 0) {
            strength -= 3;
        }
    }

    return strength;
}

int main() {
    // Get the password from the user
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the strength of the password
    int strength = checkPasswordStrength(password);

    // Print the strength of the password
    if (strength <= 0) {
        printf("Your password is very weak.\n");
    } else if (strength <= 3) {
        printf("Your password is weak.\n");
    } else if (strength <= 5) {
        printf("Your password is okay.\n");
    } else if (strength <= 7) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is very strong.\n");
    }

    return 0;
}