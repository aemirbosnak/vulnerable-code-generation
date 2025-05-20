//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PASSWORD_LEN 255

typedef struct PasswordStrength {
    int score;
    char feedback[MAX_PASSWORD_LEN];
} PasswordStrength;

int calculate_password_strength(char *password) {
    int score = 0;
    int length = strlen(password);

    // Consider password length
    if (length >= 8) {
        score++;
    }

    // Consider presence of uppercase letter
    if (strchr(password, 'A') || strchr(password, 'B') || strchr(password, 'C') ||
        strchr(password, 'D') || strchr(password, 'E') || strchr(password, 'F') ||
        strchr(password, 'G') || strchr(password, 'H') || strchr(password, 'I') ||
        strchr(password, 'J') || strchr(password, 'K') || strchr(password, 'L') ||
        strchr(password, 'M') || strchr(password, 'N') || strchr(password, 'O') ||
        strchr(password, 'P') || strchr(password, 'Q') || strchr(password, 'R') ||
        strchr(password, 'S') || strchr(password, 'T') || strchr(password, 'U') ||
        strchr(password, 'V') || strchr(password, 'W') || strchr(password, 'X') ||
        strchr(password, 'Y') || strchr(password, 'Z')) {
        score++;
    }

    // Consider presence of number
    if (strchr(password, '0') || strchr(password, '1') || strchr(password, '2') ||
        strchr(password, '3') || strchr(password, '4') || strchr(password, '5') ||
        strchr(password, '6') || strchr(password, '7') || strchr(password, '8') ||
        strchr(password, '9')) {
        score++;
    }

    // Consider presence of special character
    if (strchr(password, '$') || strchr(password, '%') || strchr(password, '&') ||
        strchr(password, '(') || strchr(password, ')') || strchr(password, '*') ||
        strchr(password, '+') || strchr(password, '-') || strchr(password, '=') ||
        strchr(password, '}') || strchr(password, '~')) {
        score++;
    }

    return score;
}

void generate_password_strength_feedback(PasswordStrength *strength, char *password) {
    strength->score = calculate_password_strength(password);

    switch (strength->score) {
        case 0:
            strcpy(strength->feedback, "Very Weak");
            break;
        case 1:
            strcpy(strength->feedback, "Weak");
            break;
        case 2:
            strcpy(strength->feedback, "Medium");
            break;
        case 3:
            strcpy(strength->feedback, "Strong");
            break;
        case 4:
            strcpy(strength->feedback, "Very Strong");
            break;
    }
}

int main() {
    char password[MAX_PASSWORD_LEN];

    printf("Enter your password: ");
    scanf("%s", password);

    PasswordStrength strength;
    generate_password_strength_feedback(&strength, password);

    printf("Your password strength is: %s\n", strength.feedback);

    return 0;
}