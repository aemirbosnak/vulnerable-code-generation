//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MIN_LENGTH 8
#define WEAK 0
#define MODERATE 1
#define STRONG 2
#define VERY_STRONG 3

bool has_digit(const char *password) {
    size_t length = strlen(password);
    for (size_t i = 0; i < length; ++i) {
        if (isdigit(password[i])) {
            return true;
        }
    }
    return false;
}

bool has_uppercase(const char *password) {
    size_t length = strlen(password);
    for (size_t i = 0; i < length; ++i) {
        if (isupper(password[i])) {
            return true;
        }
    }
    return false;
}

bool has_lowercase(const char *password) {
    size_t length = strlen(password);
    for (size_t i = 0; i < length; ++i) {
        if (islower(password[i])) {
            return true;
        }
    }
    return false;
}

bool has_special_char(const char *password) {
    size_t length = strlen(password);
    const char *special_chars = "!@#$%^&*()-_+=[]{}|;:,.<>?";
    for (size_t i = 0; i < length; ++i) {
        if (strchr(special_chars, password[i])) {
            return true;
        }
    }
    return false;
}

int password_strength(const char *password) {
    if (strlen(password) < MIN_LENGTH) {
        return WEAK;
    }

    int strength = MODERATE;
    if (has_digit(password)) {
        strength++;
    }
    if (has_uppercase(password)) {
        strength++;
    }
    if (has_lowercase(password)) {
        strength++;
    }
    if (has_special_char(password)) {
        strength++;
    }

    if (strength == 4) {
        strength = VERY_STRONG;
    }

    return strength;
}

int main() {
    char password[128];
    printf("Enter your password: ");
    scanf("%s", password);

    int strength = password_strength(password);
    switch (strength) {
        case WEAK:
            printf("Your password is weak.\n");
            break;
        case MODERATE:
            printf("Your password is moderate.\n");
            break;
        case STRONG:
            printf("Your password is strong.\n");
            break;
        case VERY_STRONG:
            printf("Your password is very strong.\n");
            break;
        default:
            printf("An error occurred.\n");
            break;
    }

    return 0;
}