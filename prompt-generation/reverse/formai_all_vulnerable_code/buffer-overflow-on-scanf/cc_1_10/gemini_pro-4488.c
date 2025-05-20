//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 128

int check_length(const char *password) {
    int length = strlen(password);
    if (length < MIN_LENGTH) {
        printf("Password too short, must be at least %d characters long.\n", MIN_LENGTH);
        return 0;
    } else if (length > MAX_LENGTH) {
        printf("Password too long, must be at most %d characters long.\n", MAX_LENGTH);
        return 0;
    }
    return 1;
}

int check_uppercase(const char *password) {
    int count = 0;
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            count++;
        }
    }
    if (count == 0) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }
    return 1;
}

int check_lowercase(const char *password) {
    int count = 0;
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            count++;
        }
    }
    if (count == 0) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }
    return 1;
}

int check_digit(const char *password) {
    int count = 0;
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            count++;
        }
    }
    if (count == 0) {
        printf("Password must contain at least one digit.\n");
        return 0;
    }
    return 1;
}

int check_symbol(const char *password) {
    int count = 0;
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        if (ispunct(password[i])) {
            count++;
        }
    }
    if (count == 0) {
        printf("Password must contain at least one symbol.\n");
        return 0;
    }
    return 1;
}

int check_strength(const char *password) {
    int score = 0;
    int length = strlen(password);
    if (length >= 8) {
        score++;
    }
    if (length >= 12) {
        score++;
    }
    if (length >= 16) {
        score++;
    }
    if (check_uppercase(password)) {
        score++;
    }
    if (check_lowercase(password)) {
        score++;
    }
    if (check_digit(password)) {
        score++;
    }
    if (check_symbol(password)) {
        score++;
    }
    return score;
}

int main() {
    char password[MAX_LENGTH + 1];
    printf("Enter password: ");
    scanf("%s", password);

    if (!check_length(password)) {
        return 1;
    }
    if (!check_uppercase(password)) {
        return 1;
    }
    if (!check_lowercase(password)) {
        return 1;
    }
    if (!check_digit(password)) {
        return 1;
    }
    if (!check_symbol(password)) {
        return 1;
    }

    int score = check_strength(password);
    printf("Password strength: %d\n", score);

    return 0;
}