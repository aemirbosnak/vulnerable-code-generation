//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: genious
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 100

bool isPasswordValid(char* password) {
    int length = strlen(password);
    if (length < 8 || length > MAX_PASSWORD_LENGTH) {
        return false;
    }

    int hasDigit = false;
    int hasUppercase = false;
    int hasLowercase = false;
    int hasSpecialCharacter = false;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (isdigit(c)) {
            hasDigit = true;
        } else if (isupper(c)) {
            hasUppercase = true;
        } else if (islower(c)) {
            hasLowercase = true;
        } else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '-' || c == '+' || c == '=' || c == '?' || c == '|' || c == '~' || c == '`' || c == '{' || c == '}' || c == '[' || c == ']' || c == ';' || c == ':' || c == '"' || c == '\'' || c == ','|| c == '.' || c == '<' || c == '>' || c == '/' || c == '? ') {
            hasSpecialCharacter = true;
        }
    }

    if (!hasDigit ||!hasUppercase ||!hasLowercase ||!hasSpecialCharacter) {
        return false;
    }

    return true;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    if (isPasswordValid(password)) {
        printf("Password is strong!\n");
    } else {
        printf("Password is weak!\n");
    }

    return 0;
}