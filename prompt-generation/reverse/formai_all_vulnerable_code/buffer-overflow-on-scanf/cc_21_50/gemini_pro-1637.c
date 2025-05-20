//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 64

typedef enum {
    WEAK,
    MEDIUM,
    STRONG
} PasswordStrength;

int main() {
    char password[MAX_LENGTH + 1];
    int length, score;

    printf("Enter your password: ");
    scanf("%s", password);

    // Check the length of the password
    length = strlen(password);
    if (length < MIN_LENGTH) {
        printf("Password is too short. Please enter a password with at least %d characters.\n", MIN_LENGTH);
        return EXIT_FAILURE;
    } else if (length > MAX_LENGTH) {
        printf("Password is too long. Please enter a password with at most %d characters.\n", MAX_LENGTH);
        return EXIT_FAILURE;
    }

    // Check for uppercase characters
    score = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            score++;
        }
    }

    // Check for lowercase characters
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            score++;
        }
    }

    // Check for digits
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            score++;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
            score++;
        }
    }

    // Determine the password strength
    PasswordStrength strength;
    if (score < 3) {
        strength = WEAK;
    } else if (score >= 3 && score < 6) {
        strength = MEDIUM;
    } else {
        strength = STRONG;
    }

    // Print the password strength
    printf("Your password strength is: ");
    switch (strength) {
        case WEAK:
            printf("Weak\n");
            break;
        case MEDIUM:
            printf("Medium\n");
            break;
        case STRONG:
            printf("Strong\n");
            break;
    }

    return EXIT_SUCCESS;
}