//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PASSWORD_LENGTH 256

typedef struct PasswordStrength {
    int strength;
    char message[MAX_PASSWORD_LENGTH];
} PasswordStrength;

PasswordStrength check_password_strength(char *password) {
    PasswordStrength strength = {0, ""};

    if (strlen(password) < 8) {
        strength.strength = 1;
        strcpy(strength.message, "Weak - too short!");
    } else if (strlen(password) >= 8 && strlen(password) < 12) {
        strength.strength = 2;
        strcpy(strength.message, "Fair - meets minimum length!");
    } else if (strlen(password) >= 12) {
        strength.strength = 3;
        strcpy(strength.message, "Good - strong and long!");
    } else {
        strength.strength = 0;
        strcpy(strength.message, "Very weak - unacceptable!");
    }

    return strength;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a password: ");
    scanf("%s", password);

    PasswordStrength strength = check_password_strength(password);

    switch (strength.strength) {
        case 0:
            printf("Password: %s\n", password);
            printf("Strength: Very weak - unacceptable!\n");
            break;
        case 1:
            printf("Password: %s\n", password);
            printf("Strength: Weak - too short!\n");
            break;
        case 2:
            printf("Password: %s\n", password);
            printf("Strength: Fair - meets minimum length!\n");
            break;
        case 3:
            printf("Password: %s\n", password);
            printf("Strength: Good - strong and long!\n");
            break;
    }

    return 0;
}