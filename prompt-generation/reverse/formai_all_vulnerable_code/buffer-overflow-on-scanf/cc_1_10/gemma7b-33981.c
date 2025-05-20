//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 255

typedef struct PasswordStrength {
    int strength;
    char message[MAX_PASSWORD_LENGTH];
} PasswordStrength;

PasswordStrength checkPasswordStrength(char *password) {
    PasswordStrength strength = {0, ""};

    // Check for minimum length
    if (strlen(password) < 8) {
        strength.strength = 1;
        strcpy(strength.message, "Password too short.");
    }

    // Check for uppercase letter
    if (!strchr(password, 'A')) {
        strength.strength = 2;
        strcat(strength.message, "Missing uppercase letter.");
    }

    // Check for lowercase letter
    if (!strchr(password, 'a')) {
        strength.strength = 3;
        strcat(strength.message, "Missing lowercase letter.");
    }

    // Check for number
    if (!strchr(password, '0') || !strchr(password, '9')) {
        strength.strength = 4;
        strcat(strength.message, "Missing number.");
    }

    // Check for special character
    if (!strchr(password, '!')) {
        strength.strength = 5;
        strcat(strength.message, "Missing special character.");
    }

    // Check for complexity
    if (strength.strength >= 4) {
        strength.strength = 6;
        strcpy(strength.message, "Strong password.");
    }

    return strength;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a password: ");
    scanf("%s", password);

    PasswordStrength strength = checkPasswordStrength(password);

    printf("Password strength: %d\n", strength.strength);
    printf("Message: %s\n", strength.message);

    return 0;
}