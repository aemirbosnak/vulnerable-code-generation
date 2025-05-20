//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: futuristic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define PASSWORD_MAX_LENGTH 255

typedef struct _PasswordStrength {
    int score;
    char message[256];
} PasswordStrength;

int calculatePasswordStrength(char *password) {
    int length = strlen(password);
    int score = 0;
    char message[256];

    if (length >= 8) {
        score++;
        strcpy(message, "Strong");
    } else if (length >= 6) {
        score++;
        strcpy(message, "Good");
    } else if (length >= 4) {
        score++;
        strcpy(message, "Fair");
    } else {
        score = 0;
        strcpy(message, "Weak");
    }

    PasswordStrength ps = { score, message };
    return ps.score;
}

int main() {
    char password[PASSWORD_MAX_LENGTH];
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    strength = calculatePasswordStrength(password);

    switch (strength) {
        case 1:
            printf("Your password is: %s\n", password);
            printf("Strength: %s\n", "Weak");
            break;
        case 2:
            printf("Your password is: %s\n", password);
            printf("Strength: %s\n", "Fair");
            break;
        case 3:
            printf("Your password is: %s\n", password);
            printf("Strength: %s\n", "Good");
            break;
        case 4:
            printf("Your password is: %s\n", password);
            printf("Strength: %s\n", "Strong");
            break;
    }

    return 0;
}