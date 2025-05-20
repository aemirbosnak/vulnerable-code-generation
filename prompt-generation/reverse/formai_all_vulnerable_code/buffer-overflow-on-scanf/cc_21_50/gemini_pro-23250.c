//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Declare variables
    char password[101];
    int strength;

    // Get password from user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check password length
    if (strlen(password) < 8) {
        strength = 0;
    } else if (strlen(password) >= 8 && strlen(password) <= 12) {
        strength = 1;
    } else if (strlen(password) > 12 && strlen(password) <= 16) {
        strength = 2;
    } else {
        strength = 3;
    }

    // Check password complexity
    int hasUppercase = 0;
    int hasLowercase = 0;
    int hasDigit = 0;
    int hasSpecialCharacter = 0;

    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUppercase = 1;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            hasLowercase = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
        } else {
            hasSpecialCharacter = 1;
        }
    }

    if (hasUppercase && hasLowercase && hasDigit && hasSpecialCharacter) {
        strength += 4;
    } else if (hasUppercase && hasLowercase && hasDigit) {
        strength += 3;
    } else if (hasUppercase && hasLowercase) {
        strength += 2;
    } else if (hasUppercase || hasLowercase || hasDigit) {
        strength += 1;
    }

    // Print password strength
    printf("Password strength: %d\n", strength);

    // Check if password is strong enough
    if (strength >= 4) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is not strong enough.\n");
    }

    return 0;
}