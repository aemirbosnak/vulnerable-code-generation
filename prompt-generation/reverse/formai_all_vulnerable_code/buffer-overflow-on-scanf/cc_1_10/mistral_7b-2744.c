//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: modular
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32

typedef struct {
    int length;
    int has_digit;
    int has_upper;
    int has_lower;
    int has_special;
} password_strength_t;

int has_digit(const char *password) {
    for (size_t i = 0; password[i]; i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

int has_upper(const char *password) {
    for (size_t i = 0; password[i]; i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

int has_lower(const char *password) {
    for (size_t i = 0; password[i]; i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

int has_special(const char *password) {
    const char *special_chars = "!@#$%^&*()-_=+[]{};:,.<>?";
    for (size_t i = 0; password[i]; i++) {
        if (strchr(special_chars, password[i])) {
            return 1;
        }
    }
    return 0;
}

void check_password_strength(const char *password) {
    password_strength_t strength;
    strength.length = strlen(password);
    strength.has_digit = has_digit(password);
    strength.has_upper = has_upper(password);
    strength.has_lower = has_lower(password);
    strength.has_special = has_special(password);

    printf("Password length: %d\n", strength.length);
    printf("Has digit: %s\n", strength.has_digit ? "Yes" : "No");
    printf("Has upper: %s\n", strength.has_upper ? "Yes" : "No");
    printf("Has lower: %s\n", strength.has_lower ? "Yes" : "No");
    printf("Has special characters: %s\n", strength.has_special ? "Yes" : "No");

    int score = 0;
    if (strength.length >= MIN_PASSWORD_LENGTH) {
        score++;
    }
    if (strength.has_digit) {
        score++;
    }
    if (strength.has_upper) {
        score++;
    }
    if (strength.has_lower) {
        score++;
    }
    if (strength.has_special) {
        score++;
    }

    printf("Password strength score: %d\n", score);
    if (score >= 3) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter a password: ");
    scanf("%s", password);
    check_password_strength(password);
    return 0;
}