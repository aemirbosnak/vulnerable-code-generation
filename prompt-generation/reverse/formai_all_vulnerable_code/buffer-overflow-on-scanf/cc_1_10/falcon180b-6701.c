//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: multivariable
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 100

bool is_lowercase(char c) {
    return (c >= 'a' && c <= 'z');
}

bool is_uppercase(char c) {
    return (c >= 'A' && c <= 'Z');
}

bool is_digit(char c) {
    return (c >= '0' && c <= '9');
}

bool is_special_character(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '+' || c == '=' || c == '{' || c == '}' || c == '[' || c == ']' || c == '|' || c == ';' || c == ':' || c == '"' || c == '\'' || c == '<' || c == '>' || c == ',' || c == '.' || c == '?' || c == '/');
}

bool is_password_strong(char* password) {
    int length = strlen(password);
    int lowercase_count = 0;
    int uppercase_count = 0;
    int digit_count = 0;
    int special_character_count = 0;

    for (int i = 0; i < length; i++) {
        if (is_lowercase(password[i])) {
            lowercase_count++;
        } else if (is_uppercase(password[i])) {
            uppercase_count++;
        } else if (is_digit(password[i])) {
            digit_count++;
        } else if (is_special_character(password[i])) {
            special_character_count++;
        }
    }

    return (lowercase_count > 0 && uppercase_count > 0 && digit_count > 0 && special_character_count > 0);
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