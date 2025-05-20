//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: calm
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MIN_LENGTH 8
#define PASSWORD_SIZE 50

const char *weak_passwords[] = {"password", "123456", "123456789", "111111", "123123", "qwerty", "letmein", "admin", "welcome", "monkey"};

bool is_digit(char c) {
    return isdigit(c);
}

bool is_uppercase(char c) {
    return isupper(c);
}

bool is_lowercase(char c) {
    return islower(c);
}

bool has_special_char(char c) {
    return (!isalnum(c) && c != ' ') || (isalnum(c) && strchr("!@#$%^&*()_+-=[]{}|;:,.<>?", c) != NULL);
}

int main() {
    char password[PASSWORD_SIZE];
    int length = 0;
    int has_digit = 0, has_upper = 0, has_lower = 0, has_special = 0;
    int num_weak_passwords = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for (int i = 0; password[i] != '\0'; ++i) {
        if (is_digit(password[i])) {
            has_digit = 1;
        }
        if (is_uppercase(password[i])) {
            has_upper = 1;
        }
        if (is_lowercase(password[i])) {
            has_lower = 1;
        }
        if (has_special_char(password[i])) {
            has_special = 1;
        }
    }

    if (length < MIN_LENGTH) {
        printf("Password is too short.\n");
        return 1;
    }

    if (!has_digit) {
        printf("Password must contain at least one digit.\n");
        return 1;
    }

    if (!has_upper) {
        printf("Password must contain at least one uppercase letter.\n");
        return 1;
    }

    if (!has_lower) {
        printf("Password must contain at least one lowercase letter.\n");
        return 1;
    }

    if (!has_special) {
        printf("Password must contain at least one special character.\n");
        return 1;
    }

    for (int i = 0; weak_passwords[i] != NULL; ++i) {
        if (strcmp(password, weak_passwords[i]) == 0) {
            printf("Password is weak.\n");
            num_weak_passwords++;
        }
    }

    if (num_weak_passwords > 0) {
        printf("There are %d weak passwords in your password.\n", num_weak_passwords);
        return 1;
    }

    printf("Password is strong.\n");
    return 0;
}