//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 64

typedef struct {
    int length;
    int num_upper;
    int num_lower;
    int num_digit;
    int num_special;
} PasswordStrength;

PasswordStrength calculate_password_strength(char *password) {
    PasswordStrength strength = {0};

    strength.length = strlen(password);

    for (int i = 0; i < strength.length; i++) {
        char ch = password[i];
        if (ch >= 'A' && ch <= 'Z') {
            strength.num_upper++;
        } else if (ch >= 'a' && ch <= 'z') {
            strength.num_lower++;
        } else if (ch >= '0' && ch <= '9') {
            strength.num_digit++;
        } else {
            strength.num_special++;
        }
    }

    return strength;
}

int check_password_strength(char *password, PasswordStrength strength) {
    int score = 0;

    if (strength.length >= MIN_LENGTH && strength.length <= MAX_LENGTH) {
        score += 4;
    }

    if (strength.num_upper > 0) {
        score += 2;
    }

    if (strength.num_lower > 0) {
        score += 2;
    }

    if (strength.num_digit > 0) {
        score += 2;
    }

    if (strength.num_special > 0) {
        score += score + strength.num_special;
    }

    return score;
}

int main() {
    char password[MAX_LENGTH + 1];

    printf("Enter a password: ");
    scanf("%s", password);

    PasswordStrength strength = calculate_password_strength(password);
    int score = check_password_strength(password, strength);

    printf("Password strength: %d\n", score);

    if (score < 10) {
        printf("Weak password\n");
    } else if (score >= 10 && score < 15) {
        printf("Medium password\n");
    } else if (score >= 15) {
        printf("Strong password\n");
    }

    return 0;
}