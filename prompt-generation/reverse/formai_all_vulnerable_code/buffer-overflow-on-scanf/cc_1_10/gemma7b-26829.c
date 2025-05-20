//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 256

typedef struct PasswordStrength {
    int strength;
    char message[256];
} PasswordStrength;

PasswordStrength check_password_strength(char *password) {
    PasswordStrength strength = {0, ""};

    // Check for minimum length
    if (strlen(password) < 8) {
        strength.strength = 1;
        sprintf(strength.message, "Password must be at least 8 characters long.");
    }

    // Check for uppercase letter
    if (!strchr(password, 'A')) {
        strength.strength = 2;
        sprintf(strength.message, "Password needs an uppercase letter.");
    }

    // Check for lowercase letter
    if (!strchr(password, 'a')) {
        strength.strength = 3;
        sprintf(strength.message, "Password needs a lowercase letter.");
    }

    // Check for number
    if (!strchr(password, '0') || !strchr(password, '9')) {
        strength.strength = 4;
        sprintf(strength.message, "Password needs a number.");
    }

    // Check for special character
    if (!strchr(password, '$') && !strchr(password, '%') &&
        !strchr(password, '^') && !strchr(password, '&')) {
        strength.strength = 5;
        sprintf(strength.message, "Password needs a special character.");
    }

    return strength;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    PasswordStrength strength = check_password_strength(password);

    switch (strength.strength) {
        case 0:
            printf("Password is very strong!\n");
            break;
        case 1:
            printf("Password is weak, please use at least 8 characters.\n");
            break;
        case 2:
            printf("Password is weak, please use an uppercase letter.\n");
            break;
        case 3:
            printf("Password is weak, please use a lowercase letter.\n");
            break;
        case 4:
            printf("Password is weak, please use a number.\n");
            break;
        case 5:
            printf("Password is weak, please use a special character.\n");
            break;
    }

    return 0;
}