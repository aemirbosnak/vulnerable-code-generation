//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_LENGTH_MIN 8
#define PASSWORD_LENGTH_MAX 32
#define PASSWORD_SPECIAL_CHARS "!@#$%^&*()_+=-[]{}|;:,.<>?"

int is_special_char(char c) {
    for (int i = 0; i < strlen(PASSWORD_SPECIAL_CHARS); i++) {
        if (PASSWORD_SPECIAL_CHARS[i] == c) {
            return 1;
        }
    }
    return 0;
}

int is_lowercase(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    return 0;
}

int is_uppercase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    }
    return 0;
}

int is_number(char c) {
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

int is_valid_password(char* password) {
    int length = strlen(password);
    if (length < PASSWORD_LENGTH_MIN || length > PASSWORD_LENGTH_MAX) {
        return 0;
    }
    int has_lowercase = 0;
    int has_uppercase = 0;
    int has_number = 0;
    int has_special = 0;
    for (int i = 0; i < length; i++) {
        if (is_lowercase(password[i])) {
            has_lowercase = 1;
        }
        if (is_uppercase(password[i])) {
            has_uppercase = 1;
        }
        if (is_number(password[i])) {
            has_number = 1;
        }
        if (is_special_char(password[i])) {
            has_special = 1;
        }
    }
    if (!has_lowercase ||!has_uppercase ||!has_number ||!has_special) {
        return 0;
    }
    return 1;
}

int main() {
    char password[PASSWORD_LENGTH_MAX];
    printf("Enter a password: ");
    scanf("%s", password);
    if (is_valid_password(password)) {
        printf("Password is strong!\n");
    } else {
        printf("Password is weak!\n");
    }
    return 0;
}