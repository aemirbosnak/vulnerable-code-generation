//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: real-life
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MIN_LENGTH 8
#define WEAK_PASSWORDS_COUNT 10

const char *weak_passwords[WEAK_PASSWORDS_COUNT] = {
    "password",
    "123456",
    "12345678",
    "qwerty",
    "letmein",
    "123456789",
    "111111",
    "123123",
    "admin",
    "welcome"
};

int password_strength(const char *password) {
    size_t length = strlen(password);
    int strength = 0;
    int has_digit = 0;
    int has_upper = 0;
    int has_lower = 0;

    for (size_t i = 0; password[i]; i++) {
        if (isdigit(password[i])) {
            has_digit = 1;
        }
        if (isupper(password[i])) {
            has_upper = 1;
        }
        if (islower(password[i])) {
            has_lower = 1;
        }

        if (length >= MIN_LENGTH && (has_digit && has_upper && has_lower)) {
            strength = 3; // Strong
            break;
        }
    }

    if (length < MIN_LENGTH) {
        strength = 1; // Weak
    }

    for (size_t i = 0; i < WEAK_PASSWORDS_COUNT; i++) {
        if (strcmp(password, weak_passwords[i]) == 0) {
            strength = 1; // Weak
            break;
        }
    }

    return strength;
}

int main() {
    char password[100];
    int strength;

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);

    // Remove newline character from the input
    size_t newline_index = strlen(password) - 1;
    if (newline_index > 0 && password[newline_index] == '\n') {
        password[newline_index] = '\0';
    }

    strength = password_strength(password);

    switch (strength) {
        case 0:
            printf("Invalid password.\n");
            break;
        case 1:
            printf("Weak password.\n");
            break;
        case 2:
            printf("Medium password.\n");
            break;
        case 3:
            printf("Strong password.\n");
            break;
    }

    return 0;
}