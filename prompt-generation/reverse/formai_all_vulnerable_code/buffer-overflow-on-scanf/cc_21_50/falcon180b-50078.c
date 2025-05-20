//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: systematic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 100

bool isValidPassword(char* password) {
    int length = strlen(password);
    if (length < 8 || length > MAX_PASSWORD_LENGTH) {
        return false;
    }

    bool hasLowercase = false;
    bool hasUppercase = false;
    bool hasNumber = false;
    bool hasSpecial = false;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            if (c >= 'a' && c <= 'z') {
                hasLowercase = true;
            } else if (c >= 'A' && c <= 'Z') {
                hasUppercase = true;
            }
        } else if (isdigit(c)) {
            hasNumber = true;
        } else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' ||
                   c == '^' || c == '&' || c == '*' || c == '(' || c == ')' ||
                   c == '-' || c == '_' || c == '+' || c == '=' || c == '{' ||
                   c == '}' || c == '[' || c == ']' || c == '|' || c == ';' ||
                   c == ':' || c == '"' || c == '\'' || c == ',' || c == '.' ||
                   c == '/' || c == '?' || c == '<' || c == '>') {
            hasSpecial = true;
        }
    }

    if (!hasLowercase ||!hasUppercase ||!hasNumber ||!hasSpecial) {
        return false;
    }

    return true;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);

    if (isValidPassword(password)) {
        printf("Password is strong\n");
    } else {
        printf("Password is weak\n");
    }

    return 0;
}