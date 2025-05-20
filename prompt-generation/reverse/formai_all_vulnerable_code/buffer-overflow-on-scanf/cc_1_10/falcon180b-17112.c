//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASS_LENGTH 100

int is_alpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int is_special(char c) {
    return c == '!' || c == '@' || c == '#' || c == '$' || c == '%' ||
           c == '^' || c == '&' || c == '*' || c == '(' || c == ')' ||
           c == '-' || c == '+' || c == '=' || c == '[' || c == ']' ||
           c == '{' || c == '}' || c == '|' || c == ';' || c == ':' ||
           c == '"' || c == '\'' || c == ',' || c == '.' || c == '<' ||
           c == '>' || c == '?' || c == '/' || c == '~';
}

int is_password_valid(char *password) {
    int length = strlen(password);
    int has_alpha = 0;
    int has_digit = 0;
    int has_special = 0;

    for (int i = 0; i < length; i++) {
        if (is_alpha(password[i])) {
            has_alpha = 1;
        } else if (is_digit(password[i])) {
            has_digit = 1;
        } else if (is_special(password[i])) {
            has_special = 1;
        }
    }

    return has_alpha && has_digit && has_special;
}

int main() {
    char password[MAX_PASS_LENGTH];
    int length;

    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    if (is_password_valid(password)) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is weak.\n");
    }

    return 0;
}