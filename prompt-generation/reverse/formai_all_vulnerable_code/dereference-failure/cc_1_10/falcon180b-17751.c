//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 1024

int is_lowercase(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_uppercase(char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int is_special_char(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*');
}

int is_password_valid(char* password) {
    int length = strlen(password);
    int has_lowercase = 0;
    int has_uppercase = 0;
    int has_digit = 0;
    int has_special_char = 0;

    for (int i = 0; i < length; i++) {
        char c = password[i];

        if (is_lowercase(c)) {
            has_lowercase = 1;
        } else if (is_uppercase(c)) {
            has_uppercase = 1;
        } else if (is_digit(c)) {
            has_digit = 1;
        } else if (is_special_char(c)) {
            has_special_char = 1;
        }
    }

    return (length >= 8 && has_lowercase && has_uppercase && has_digit && has_special_char);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }

    char* password = argv[1];

    if (strlen(password) > MAX_PASSWORD_LENGTH) {
        printf("Error: Password is too long.\n");
        return 1;
    }

    if (is_password_valid(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}