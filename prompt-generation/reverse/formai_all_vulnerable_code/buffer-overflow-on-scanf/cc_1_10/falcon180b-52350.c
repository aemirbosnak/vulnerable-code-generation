//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 100

bool has_uppercase(const char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return true;
        }
    }
    return false;
}

bool has_lowercase(const char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return true;
        }
    }
    return false;
}

bool has_digit(const char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return true;
        }
    }
    return false;
}

bool has_special_char(const char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            return true;
        }
    }
    return false;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    int score = 0;

    if (has_uppercase(password)) {
        score++;
    }

    if (has_lowercase(password)) {
        score++;
    }

    if (has_digit(password)) {
        score++;
    }

    if (has_special_char(password)) {
        score++;
    }

    if (score < 2) {
        printf("Your password is weak.\n");
    } else if (score == 2) {
        printf("Your password is moderate.\n");
    } else {
        printf("Your password is strong.\n");
    }

    return 0;
}