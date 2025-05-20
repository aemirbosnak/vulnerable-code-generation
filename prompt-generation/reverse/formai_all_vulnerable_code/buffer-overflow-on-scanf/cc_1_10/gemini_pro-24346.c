//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Password strength checker
int password_strength(char *password) {
    int strength = 0;

    // Check password length
    if (strlen(password) < 8) {
        strength++;
    }

    // Check for uppercase letters
    if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ")) {
        strength++;
    }

    // Check for lowercase letters
    if (strpbrk(password, "abcdefghijklmnopqrstuvwxyz")) {
        strength++;
    }

    // Check for numbers
    if (strpbrk(password, "0123456789")) {
        strength++;
    }

    // Check for special characters
    if (strpbrk(password, "!@#$%^&*()_-+={}[]|:;<>,.?/~")) {
        strength++;
    }

    // Check for repeated characters
    for (int i = 0; i < strlen(password); i++) {
        for (int j = i + 1; j < strlen(password); j++) {
            if (password[i] == password[j]) {
                strength--;
            }
        }
    }

    return strength;
}

// Main function
int main() {
    char password[100];

    printf("Enter your password: ");
    scanf("%s", password);

    int strength = password_strength(password);

    if (strength < 3) {
        printf("Your password is weak.\n");
    } else if (strength == 3) {
        printf("Your password is fair.\n");
    } else if (strength == 4) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is excellent.\n");
    }

    return 0;
}