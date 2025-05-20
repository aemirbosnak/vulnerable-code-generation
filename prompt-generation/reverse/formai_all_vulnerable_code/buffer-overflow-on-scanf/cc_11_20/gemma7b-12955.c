//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 255

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int password_length;
    int strength = 0;
    int has_numbers = 0;
    int has_letters = 0;
    int has_symbols = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    password_length = strlen(password);

    // Check for numbers
    for (int i = 0; i < password_length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            has_numbers = 1;
        }
    }

    // Check for letters
    for (int i = 0; i < password_length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            has_letters = 1;
        }
    }

    // Check for symbols
    for (int i = 0; i < password_length; i++) {
        if (password[i] >= '!' && password[i] <= '~') {
            has_symbols = 1;
        }
    }

    // Calculate strength
    if (has_numbers && has_letters && has_symbols) {
        strength = 3;
    } else if (has_numbers || has_letters || has_symbols) {
        strength = 2;
    } else {
        strength = 1;
    }

    // Print strength
    switch (strength) {
        case 3:
            printf("Your password is very strong.\n");
            break;
        case 2:
            printf("Your password is strong.\n");
            break;
        case 1:
            printf("Your password is weak.\n");
            break;
    }

    return 0;
}