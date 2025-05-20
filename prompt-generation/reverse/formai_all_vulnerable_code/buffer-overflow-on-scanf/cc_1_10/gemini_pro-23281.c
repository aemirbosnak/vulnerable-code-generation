//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: mathematical
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int lower;
    int upper;
    int digit;
    int special;
    int length;
} PasswordStrength;

PasswordStrength calculatePasswordStrength(char *password) {
    PasswordStrength strength;
    strength.lower = 0;
    strength.upper = 0;
    strength.digit = 0;
    strength.special = 0;
    strength.length = strlen(password);

    for (int i = 0; i < strength.length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            strength.lower++;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            strength.upper++;
        } else if (password[i] >= '0' && password[i] <= '9') {
            strength.digit++;
        } else {
            strength.special++;
        }
    }

    return strength;
}

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    PasswordStrength strength = calculatePasswordStrength(password);

    int score = 0;
    score += strength.lower * 1;
    score += strength.upper * 3;
    score += strength.digit * 5;
    score += strength.special * 7;
    score += strength.length * 2;

    printf("Your password strength is: %d\n", score);

    return 0;
}