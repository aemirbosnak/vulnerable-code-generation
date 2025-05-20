//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 255

typedef struct PasswordStrength {
    int strength;
    char message[256];
} PasswordStrength;

PasswordStrength checkPasswordStrength(char *password) {
    PasswordStrength ps;
    int passwordLength = strlen(password);
    int hasUppercase = 0;
    int hasLowercase = 0;
    int hasNumbers = 0;
    int hasSpecialCharacters = 0;

    ps.strength = 0;
    ps.message[0] = '\0';

    // Check for uppercase letters
    for (int i = 0; i < passwordLength; i++) {
        if (isupper(password[i])) {
            hasUppercase = 1;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < passwordLength; i++) {
        if (islower(password[i])) {
            hasLowercase = 1;
        }
    }

    // Check for numbers
    for (int i = 0; i < passwordLength; i++) {
        if (isdigit(password[i])) {
            hasNumbers = 1;
        }
    }

    // Check for special characters
    for (int i = 0; i < passwordLength; i++) {
        if (!isalnum(password[i])) {
            hasSpecialCharacters = 1;
        }
    }

    // Calculate password strength
    if (hasUppercase && hasLowercase && hasNumbers && hasSpecialCharacters) {
        ps.strength = 5;
        strcpy(ps.message, "Very Strong");
    } else if (hasUppercase || hasLowercase || hasNumbers || hasSpecialCharacters) {
        ps.strength = 3;
        strcpy(ps.message, "Strong");
    } else {
        ps.strength = 1;
        strcpy(ps.message, "Weak");
    }

    return ps;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a password: ");
    scanf("%s", password);

    PasswordStrength ps = checkPasswordStrength(password);

    printf("Password strength: %d\n", ps.strength);
    printf("Password message: %s\n", ps.message);

    return 0;
}