//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_LEN 8
#define MAX_LEN 64

typedef enum {
    INVALID_PASSWORD,
    WEAK_PASSWORD,
    MEDIUM_PASSWORD,
    STRONG_PASSWORD
} password_strength_t;

int check_password_length(const char *password) {
    int len = strlen(password);
    if (len < MIN_LEN || len > MAX_LEN) {
        return 0;
    }
    return 1;
}

int check_password_uppercase(const char *password) {
    int i;
    int count = 0;
    for (i = 0; password[i] != '\0'; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            count++;
        }
    }
    if (count == 0) {
        return 0;
    }
    return 1;
}

int check_password_lowercase(const char *password) {
    int i;
    int count = 0;
    for (i = 0; password[i] != '\0'; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            count++;
        }
    }
    if (count == 0) {
        return 0;
    }
    return 1;
}

int check_password_digit(const char *password) {
    int i;
    int count = 0;
    for (i = 0; password[i] != '\0'; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            count++;
        }
    }
    if (count == 0) {
        return 0;
    }
    return 1;
}

int check_password_special_character(const char *password) {
    int i;
    int count = 0;
    for (i = 0; password[i] != '\0'; i++) {
        if (password[i] >= '!' && password[i] <= '/') {
            count++;
        } else if (password[i] >= ':' && password[i] <= '@') {
            count++;
        } else if (password[i] >= '[' && password[i] <= '`') {
            count++;
        } else if (password[i] >= '{' && password[i] <= '~') {
            count++;
        }
    }
    if (count == 0) {
        return 0;
    }
    return 1;
}

password_strength_t check_password_strength(const char *password) {
    if (!check_password_length(password)) {
        return INVALID_PASSWORD;
    } else if (!check_password_uppercase(password)) {
        return WEAK_PASSWORD;
    } else if (!check_password_lowercase(password)) {
        return WEAK_PASSWORD;
    } else if (!check_password_digit(password)) {
        return MEDIUM_PASSWORD;
    } else if (!check_password_special_character(password)) {
        return MEDIUM_PASSWORD;
    } else {
        return STRONG_PASSWORD;
    }
}

int main() {
    char password[MAX_LEN + 1];
    int strength;

    printf("Enter your password: ");
    scanf("%s", password);

    strength = check_password_strength(password);

    switch (strength) {
    case INVALID_PASSWORD:
        printf("Invalid password. Password must be between %d and %d characters long.\n", MIN_LEN, MAX_LEN);
        break;
    case WEAK_PASSWORD:
        printf("Weak password. Password must contain at least one uppercase letter, one lowercase letter, and one digit.\n");
        break;
    case MEDIUM_PASSWORD:
        printf("Medium password. Password must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
        break;
    case STRONG_PASSWORD:
        printf("Strong password. Password contains at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
        break;
    }

    return 0;
}