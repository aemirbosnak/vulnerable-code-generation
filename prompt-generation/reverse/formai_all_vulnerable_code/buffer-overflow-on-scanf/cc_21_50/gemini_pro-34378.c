//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8

int main() {
    char password[100];
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    // Check the length of the password
    if (strlen(password) < MIN_LENGTH) {
        printf("Your password is too short. It must be at least %d characters long.\n", MIN_LENGTH);
        return 1;
    }

    // Check for uppercase letters
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            strength++;
            break;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            strength++;
            break;
        }
    }

    // Check for digits
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            strength++;
            break;
        }
    }

    // Check for symbols
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
            strength++;
            break;
        }
    }

    // Check for repeated characters
    for (int i = 0; i < strlen(password); i++) {
        for (int j = i + 1; j < strlen(password); j++) {
            if (password[i] == password[j]) {
                strength--;
                break;
            }
        }
    }

    // Print the strength of the password
    switch (strength) {
        case 0:
            printf("Your password is very weak.\n");
            break;
        case 1:
            printf("Your password is weak.\n");
            break;
        case 2:
            printf("Your password is moderate.\n");
            break;
        case 3:
            printf("Your password is strong.\n");
            break;
        case 4:
            printf("Your password is very strong.\n");
            break;
        default:
            printf("Your password is extremely strong.\n");
    }

    return 0;
}