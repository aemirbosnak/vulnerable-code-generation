//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_PASS_LEN 8
#define MAX_PASS_LEN 64

int main() {
    char password[MAX_PASS_LEN + 1];
    int passwordStrength;

    printf("Enter your password: ");
    scanf("%s", password);

    passwordStrength = calculatePasswordStrength(password);

    switch (passwordStrength) {
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
            printf("Invalid password strength.\n");
    }

    return 0;
}

int calculatePasswordStrength(char *password) {
    int passwordStrength = 0;

    // Check password length
    if (strlen(password) < MIN_PASS_LEN) {
        passwordStrength += 1;
    } else if (strlen(password) > MAX_PASS_LEN) {
        passwordStrength += 2;
    }

    // Check password character types
    int hasUpper = 0;
    int hasLower = 0;
    int hasDigit = 0;
    int hasSpecial = 0;

    for (int i = 0; i < strlen(password); i++) {
        char c = password[i];

        if (c >= 'A' && c <= 'Z') {
            hasUpper = 1;
        } else if (c >= 'a' && c <= 'z') {
            hasLower = 1;
        } else if (c >= '0' && c <= '9') {
            hasDigit = 1;
        } else {
            hasSpecial = 1;
        }
    }

    // Increment password strength based on character types
    if (!hasUpper) {
        passwordStrength += 1;
    }

    if (!hasLower) {
        passwordStrength += 1;
    }

    if (!hasDigit) {
        passwordStrength += 1;
    }

    if (!hasSpecial) {
        passwordStrength += 1;
    }

    // Increment password strength if password contains common words
    char *commonWords[] = {
        "password",
        "123456",
        "12345678",
        "123456789",
        "qwerty",
        "1qaz2wsx",
        "abc123",
        "iloveyou",
        "princess",
        "rockstar"
    };

    int numCommonWords = sizeof(commonWords) / sizeof(char *);

    for (int i = 0; i < numCommonWords; i++) {
        if (strcmp(password, commonWords[i]) == 0) {
            passwordStrength += 2;
        }
    }

    // Return password strength
    return passwordStrength;
}