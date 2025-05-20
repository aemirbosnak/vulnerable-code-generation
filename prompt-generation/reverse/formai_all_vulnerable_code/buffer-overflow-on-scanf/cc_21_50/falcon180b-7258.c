//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 50

int main() {
    char password[MAX_PASSWORD_LENGTH + 1] = "";
    int length = 0;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special_char = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    if (length < 8) {
        printf("Password should be at least 8 characters long.\n");
        return 1;
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_number = 1;
        } else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' ||
                   password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*' ||
                   password[i] == '(' || password[i] == ')' || password[i] == '-' || password[i] == '+' ||
                   password[i] == '=' || password[i] == '{' || password[i] == '}' || password[i] == '[' ||
                   password[i] == ']' || password[i] == '|' || password[i] == ';' || password[i] == ':' ||
                   password[i] == '"' || password[i] == '\'' || password[i] == '<' || password[i] == '>' ||
                   password[i] == ',' || password[i] == '.' || password[i] == '?' || password[i] == '/') {
            has_special_char = 1;
        }
    }

    if (!has_uppercase) {
        printf("Password should contain at least one uppercase letter.\n");
        return 1;
    }

    if (!has_lowercase) {
        printf("Password should contain at least one lowercase letter.\n");
        return 1;
    }

    if (!has_number) {
        printf("Password should contain at least one number.\n");
        return 1;
    }

    if (!has_special_char) {
        printf("Password should contain at least one special character.\n");
        return 1;
    }

    printf("Password is strong.\n");
    return 0;
}