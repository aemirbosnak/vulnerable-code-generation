//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: detailed
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32

int is_upper(char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int is_special(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '+' || c == '=' || c == '{' || c == '}' || c == '[' || c == ']' || c == ';' || c == ':' || c == '\"' || c == '\'' || c == ',');
}

int is_valid_password(char *password) {
    int length = strlen(password);
    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        return 0;
    }
    int has_upper = 0;
    int has_lower = 0;
    int has_digit = 0;
    int has_special = 0;
    for (int i = 0; i < length; i++) {
        char c = password[i];
        if (is_upper(c)) {
            has_upper = 1;
        }
        else if (is_lower(c)) {
            has_lower = 1;
        }
        else if (is_digit(c)) {
            has_digit = 1;
        }
        else if (is_special(c)) {
            has_special = 1;
        }
    }
    if (!has_upper ||!has_lower ||!has_digit ||!has_special) {
        return 0;
    }
    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);
    if (is_valid_password(password)) {
        printf("Password is strong.\n");
    }
    else {
        printf("Password is weak.\n");
    }
    return 0;
}