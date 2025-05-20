//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 256

typedef struct {
    char password[MAX_PASSWORD_LENGTH];
    int strength;
    char message[MAX_PASSWORD_LENGTH];
} PasswordStrength;

int calculate_password_strength(char *password) {
    int strength = 0;
    int i = 0;
    int password_length = strlen(password);

    for (i = 0; i < password_length; i++) {
        if (isupper(password[i]) || islower(password[i]) || isdigit(password[i])) {
            strength++;
        }
    }

    if (strength >= 3) {
        return strength;
    } else {
        return 0;
    }
}

void generate_password_strength_message(int strength, char *message) {
    switch (strength) {
        case 0:
            strcpy(message, "Very Weak");
            break;
        case 1:
            strcpy(message, "Weak");
            break;
        case 2:
            strcpy(message, "Moderate");
            break;
        case 3:
            strcpy(message, "Strong");
            break;
        default:
            strcpy(message, "Very Strong");
            break;
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int strength;
    char message[MAX_PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    strength = calculate_password_strength(password);
    generate_password_strength_message(strength, message);

    printf("Your password strength is: %s\n", message);

    return 0;
}