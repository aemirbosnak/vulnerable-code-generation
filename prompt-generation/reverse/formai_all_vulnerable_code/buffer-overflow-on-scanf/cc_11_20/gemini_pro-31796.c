//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: introspective
// Embark on a quest to unravel the enigma of password strength.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants to guide the strength assessment.
#define MIN_LENGTH 8
#define MAX_LENGTH 20
#define STRENGTH_LOW 0
#define STRENGTH_MEDIUM 1
#define STRENGTH_HIGH 2

// Assess the strength of a password.
int assess_strength(char *password) {
    int length = strlen(password);

    // Enforce the password length requirements.
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Password length must be between %d and %d characters.\n", MIN_LENGTH, MAX_LENGTH);
        return STRENGTH_LOW;
    }

    // Check for character diversity.
    int has_lowercase = 0;
    int has_uppercase = 0;
    int has_digit = 0;
    int has_symbol = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
        } else {
            has_symbol = 1;
        }
    }

    // Determine the strength level.
    int strength = STRENGTH_LOW;
    if (has_lowercase && has_uppercase && has_digit && has_symbol) {
        strength = STRENGTH_HIGH;
    } else if (has_lowercase && has_uppercase && has_digit) {
        strength = STRENGTH_MEDIUM;
    }

    // Provide feedback on the password strength.
    switch (strength) {
        case STRENGTH_LOW:
            printf("Password strength: Low. Consider using a longer password with a mix of characters.");
            break;
        case STRENGTH_MEDIUM:
            printf("Password strength: Medium. Consider adding a symbol for enhanced security.");
            break;
        case STRENGTH_HIGH:
            printf("Password strength: High. Excellent work!");
            break;
    }

    return strength;
}

int main() {
    // Prompt the user for a password.
    char password[MAX_LENGTH + 1];
    printf("Enter a password: ");
    scanf("%s", password);

    // Assess the password strength.
    int strength = assess_strength(password);

    // Reflect on the password strength analysis.
    printf("\nAfter careful scrutiny, the password strength has been assessed as ");
    switch (strength) {
        case STRENGTH_LOW:
            printf("weak.");
            break;
        case STRENGTH_MEDIUM:
            printf("moderate.");
            break;
        case STRENGTH_HIGH:
            printf("strong.");
            break;
    }

    // Encourage the user to strengthen their password if necessary.
    if (strength < STRENGTH_HIGH) {
        printf("\nConsider revising your password for enhanced security.\n");
    }

    return 0;
}