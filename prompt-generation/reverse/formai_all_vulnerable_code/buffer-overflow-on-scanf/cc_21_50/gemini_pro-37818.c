//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char password[101];  // Array to store the password.
    int strength = 0;    // Variable to store the strength of the password.

    printf("Enter your password: ");
    scanf("%s", password);

    // Check the length of the password.
    if (strlen(password) < 8) {
        printf("Your password is too short! It must be at least 8 characters long.\n");
    } else {
        strength++;
    }

    // Check if the password contains at least one uppercase letter.
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            strength++;
            break;
        }
    }

    // Check if the password contains at least one lowercase letter.
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            strength++;
            break;
        }
    }

    // Check if the password contains at least one digit.
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            strength++;
            break;
        }
    }

    // Check if the password contains at least one special character.
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
            strength++;
            break;
        }
    }

    // Check if the password is unique.
    int unique = 1;
    for (int i = 0; i < strlen(password); i++) {
        for (int j = i + 1; j < strlen(password); j++) {
            if (password[i] == password[j]) {
                unique = 0;
                break;
            }
        }
    }
    if (unique) {
        strength += 2;
    }

    // Print the strength of the password.
    if (strength < 3) {
        printf("Your password is weak. Please try again.\n");
    } else if (strength == 3 || strength == 4) {
        printf("Your password is moderate. Please try again.\n");
    } else if (strength == 5) {
        printf("Your password is strong! Good job.\n");
    } else if (strength == 6) {
        printf("Your password is very strong! Congratulations!\n");
    }

    return 0;
}