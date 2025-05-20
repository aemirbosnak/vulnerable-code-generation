//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PASSWORD_LEN 255

typedef struct password_strength_t {
    int score;
    char feedback[MAX_PASSWORD_LEN];
} password_strength_t;

int calculate_password_strength(char *password) {
    int score = 0;
    int password_len = strlen(password);

    // Check for minimum length
    if (password_len < 8) {
        score -= 20;
    }

    // Check for uppercase letter
    if (!strchr(password, 'A')) {
        score -= 10;
    }

    // Check for lowercase letter
    if (!strchr(password, 'a')) {
        score -= 10;
    }

    // Check for number
    if (!strchr(password, '0')) {
        score -= 10;
    }

    // Check for special character
    if (!strchr(password, '$')) {
        score -= 10;
    }

    return score;
}

password_strength_t check_password_strength(char *password) {
    password_strength_t strength;
    strength.score = calculate_password_strength(password);
    snprintf(strength.feedback, MAX_PASSWORD_LEN, "Password strength: %d%%", strength.score);
    return strength;
}

int main() {
    char password[MAX_PASSWORD_LEN];

    printf("Enter your password: ");
    scanf("%s", password);

    password_strength_t strength = check_password_strength(password);

    printf("%s\n", strength.feedback);

    return 0;
}