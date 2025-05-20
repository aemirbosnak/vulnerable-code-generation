//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[50];
    int length, uppercase = 0, lowercase = 0, digit = 0, special = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
            break;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercase = 1;
            break;
        }
    }

    // Check for digits
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digit = 1;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*' || password[i] == '(' || password[i] == ')' || password[i] == '-' || password[i] == '_' || password[i] == '+' || password[i] == '=' || password[i] == '{' || password[i] == '}' || password[i] == '[' || password[i] == ']' || password[i] == '|' || password[i] == '~' || password[i] == '`' || password[i] == ';' || password[i] == ':' || password[i] == '\"' || password[i] == '\'' || password[i] == ',' || password[i] == '.' || password[i] == '?' || password[i] == '/') {
            special = 1;
            break;
        }
    }

    // Check password strength
    if (length >= 8 && uppercase && lowercase && digit && special) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is weak.\n");
    }

    return 0;
}