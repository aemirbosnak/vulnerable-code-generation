//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 32
#define MIN_PASSWORD_LENGTH 8

int is_password_valid(char *password);

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    if (is_password_valid(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak. Please choose a stronger password.\n");
    }

    return 0;
}

int is_password_valid(char *password) {
    int password_length = strlen(password);
    int uppercase_count = 0;
    int lowercase_count = 0;
    int digit_count = 0;
    int special_character_count = 0;

    if (password_length < MIN_PASSWORD_LENGTH) {
        return 0;
    }

    for (int i = 0; i < password_length; i++) {
        if (isupper(password[i])) {
            uppercase_count++;
        } else if (islower(password[i])) {
            lowercase_count++;
        } else if (isdigit(password[i])) {
            digit_count++;
        } else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*' || password[i] == '?' || password[i] == '-' || password[i] == '_' || password[i] == '+' || password[i] == '=' || password[i] == '{' || password[i] == '}' || password[i] == '[' || password[i] == ']' || password[i] == '|' || password[i] == ';' || password[i] == ':' || password[i] == '"' || password[i] == '\'' || password[i] == '<' || password[i] == '>' || password[i] == ',') {
            special_character_count++;
        }
    }

    if (uppercase_count >= 1 && lowercase_count >= 1 && digit_count >= 1 && special_character_count >= 1) {
        return 1;
    } else {
        return 0;
    }
}