//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: accurate
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 20

int is_uppercase(char c) {
    return ((c >= 'A') && (c <= 'Z'));
}

int is_lowercase(char c) {
    return ((c >= 'a') && (c <= 'z'));
}

int is_digit(char c) {
    return ((c >= '0') && (c <= '9'));
}

int is_special_char(char c) {
    return ((c == '!') || (c == '@') || (c == '#') || (c == '$') || (c == '%') || (c == '&') || (c == '*') || (c == '?'));
}

int is_password_strong(char* password) {
    int length = strlen(password);
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special_char = 0;

    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);

        if (is_uppercase(c)) {
            has_uppercase = 1;
        } else if (is_lowercase(c)) {
            has_lowercase = 1;
        } else if (is_digit(c)) {
            has_digit = 1;
        } else if (is_special_char(c)) {
            has_special_char = 1;
        }
    }

    if (has_uppercase && has_lowercase && has_digit && has_special_char) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    if (is_password_strong(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}