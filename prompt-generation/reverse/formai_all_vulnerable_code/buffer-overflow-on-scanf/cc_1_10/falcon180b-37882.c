//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: creative
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define PASSWORD_LENGTH 8

bool contains_uppercase(const char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return true;
        }
    }
    return false;
}

bool contains_lowercase(const char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return true;
        }
    }
    return false;
}

bool contains_digit(const char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return true;
        }
    }
    return false;
}

bool contains_special_char(const char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            return true;
        }
    }
    return false;
}

int main() {
    char password[PASSWORD_LENGTH + 1] = "";
    int strength = 0;

    printf("Enter password: ");
    scanf("%s", password);

    if (strlen(password) < PASSWORD_LENGTH) {
        printf("Password must be at least %d characters long.\n", PASSWORD_LENGTH);
        return 1;
    }

    if (contains_uppercase(password)) {
        strength++;
    }

    if (contains_lowercase(password)) {
        strength++;
    }

    if (contains_digit(password)) {
        strength++;
    }

    if (contains_special_char(password)) {
        strength++;
    }

    switch (strength) {
        case 0:
            printf("Password is very weak.\n");
            break;
        case 1:
            printf("Password is weak.\n");
            break;
        case 2:
            printf("Password is moderate.\n");
            break;
        case 3:
            printf("Password is strong.\n");
            break;
        case 4:
            printf("Password is very strong.\n");
            break;
    }

    return 0;
}