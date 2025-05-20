//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define WEAK_PASSWORD "Weak password!\n"
#define AVERAGE_PASSWORD "Average password. Consider adding numbers, uppercase letters, and special characters.\n"
#define STRONG_PASSWORD "Strong password! You're doing great!\n"

void check_password_strength(char *password) {
    int length = strlen(password);
    int has_digit = 0;
    int has_upper = 0;
    int has_lower = 0;
    int has_special = 0;

    for (int i = 0; i < length; i++) {
        char c = password[i];

        // Check if password contains digits
        if (isdigit(c)) {
            has_digit = 1;
            continue;
        }

        // Check if password contains uppercase letters
        if (isupper(c)) {
            has_upper = 1;
            continue;
        }

        // Check if password contains lowercase letters
        if (islower(c)) {
            has_lower = 1;
            continue;
        }

        // Check if password contains special characters
        if (strchr("!@#$%^&*()_+-=[]{}|;:,.<>/?`~", c) != NULL) {
            has_special = 1;
            continue;
        }
    }

    if (length < MIN_LENGTH) {
        printf(WEAK_PASSWORD);
        return;
    }

    if (!has_digit || !has_upper || !has_lower || !has_special) {
        printf(AVERAGE_PASSWORD);
        return;
    }

    printf(STRONG_PASSWORD);
}

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    check_password_strength(password);

    return 0;
}