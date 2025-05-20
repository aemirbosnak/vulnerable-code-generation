//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8

int isPasswordValid(char* password);

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    if (isPasswordValid(password)) {
        printf("Your password is strong enough.\n");
    } else {
        printf("Your password is too weak.\n");
    }

    return 0;
}

int isPasswordValid(char* password) {
    int length = strlen(password);
    if (length < MIN_PASSWORD_LENGTH) {
        return 0;
    }

    int hasUppercase = 0;
    int hasLowercase = 0;
    int hasNumber = 0;
    int hasSpecialChar = 0;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            if (isupper(c)) {
                hasUppercase = 1;
            } else {
                hasLowercase = 1;
            }
        } else if (isdigit(c)) {
            hasNumber = 1;
        } else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '_' || c == '+' || c == '=' || c == '{' || c == '}' || c == '[' || c == ']' || c == '|' || c == '\\' || c == ':' || c == ';' || c == '"' || c == '\'' || c == ',') {
            hasSpecialChar = 1;
        }
    }

    if (hasUppercase && hasLowercase && hasNumber && hasSpecialChar) {
        return 1;
    } else {
        return 0;
    }
}