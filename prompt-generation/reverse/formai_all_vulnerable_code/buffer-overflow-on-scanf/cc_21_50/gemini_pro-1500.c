//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: Alan Turing
#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    int strength, i, len;

    // Get the password from the user.
    printf("Enter your password: ");
    scanf("%s", password);

    // Calculate the length of the password.
    len = strlen(password);

    // Initialize the strength of the password.
    strength = 0;

    // Check the length of the password.
    if (len < 8) {
        strength += 1;
    } else if (len >= 8 && len < 12) {
        strength += 2;
    } else if (len >= 12) {
        strength += 3;
    }

    // Check the number of uppercase letters in the password.
    for (i = 0; i < len; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            strength += 1;
        }
    }

    // Check the number of lowercase letters in the password.
    for (i = 0; i < len; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            strength += 1;
        }
    }

    // Check the number of digits in the password.
    for (i = 0; i < len; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            strength += 1;
        }
    }

    // Check the number of special characters in the password.
    for (i = 0; i < len; i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
            strength += 1;
        }
    }

    // Print the strength of the password.
    if (strength < 3) {
        printf("Weak password.\n");
    } else if (strength >= 3 && strength < 5) {
        printf("Moderate password.\n");
    } else if (strength >= 5) {
        printf("Strong password.\n");
    }

    return 0;
}