//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MIN_DIGITS 2
#define MIN_UPPER 2
#define MIN_LOWER 2

int is_strong_password(const char *password) {
    size_t len = strlen(password);
    int has_digit = 0, has_upper = 0, has_lower = 0;

    if (len < MIN_LENGTH) {
        return 0;
    }

    for (size_t i = 0; i < len; ++i) {
        if (isdigit(password[i])) {
            has_digit = 1;
        }
        if (isupper(password[i])) {
            has_upper = 1;
        }
        if (islower(password[i])) {
            has_lower = 1;
        }
    }

    if (!has_digit || !has_upper || !has_lower) {
        return 0;
    }

    return 1;
}

int main() {
    char password[100];

    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);

    if (password[strlen(password) - 1] == '\n') {
        password[strlen(password) - 1] = '\0';
    }

    if (is_strong_password(password)) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is not strong enough.\n");
    }

    return 0;
}