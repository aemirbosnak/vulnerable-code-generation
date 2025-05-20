//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: detailed
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 1024 // Maximum length of password

int is_alpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int is_special_char(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '?');
}

int is_valid_password(char *password) {
    int length = strlen(password);
    int has_alpha = 0;
    int has_digit = 0;
    int has_special_char = 0;

    // Check if password has at least one uppercase letter
    if (!is_alpha(password[0])) {
        has_alpha = 1;
    }

    // Check if password has at least one lowercase letter
    for (int i = 1; i < length; i++) {
        if (!is_alpha(password[i])) {
            has_alpha = 1;
            break;
        }
    }

    // Check if password has at least one digit
    for (int i = 0; i < length; i++) {
        if (is_digit(password[i])) {
            has_digit = 1;
            break;
        }
    }

    // Check if password has at least one special character
    for (int i = 0; i < length; i++) {
        if (is_special_char(password[i])) {
            has_special_char = 1;
            break;
        }
    }

    // Check if password meets all criteria
    if (has_alpha && has_digit && has_special_char) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int length;

    printf("Enter password: ");
    fgets(password, MAX_PASSWORD_LENGTH + 1, stdin);
    length = strlen(password);

    // Remove newline character from input
    password[length - 1] = '\0';

    if (is_valid_password(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}