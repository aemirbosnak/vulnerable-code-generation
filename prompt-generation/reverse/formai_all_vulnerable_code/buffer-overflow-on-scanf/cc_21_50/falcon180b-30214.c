//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: genious
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char password[MAX_LENGTH];
    int length;
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_number = 0;
    int has_special = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    length = strlen(password);

    if (length < 8) {
        printf("Password too short\n");
        return 0;
    }

    if (length > MAX_LENGTH) {
        printf("Password too long\n");
        return 0;
    }

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);

        if (isalpha(c)) {
            if (isupper(c)) {
                has_uppercase = 1;
            } else {
                has_lowercase = 1;
            }
        } else if (isdigit(c)) {
            has_number = 1;
        } else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '+' || c == '=' || c == '{' || c == '}' || c == '[' || c == ']' || c == '|' || c == ';' || c == ':' || c == '"' || c == '\'' || c == ',' || c == '.' || c == '?' || c == '<' || c == '>' || c == '/') {
            has_special = 1;
        }
    }

    if (!has_uppercase ||!has_lowercase ||!has_number ||!has_special) {
        printf("Password is not strong enough\n");
    } else {
        printf("Password is strong\n");
    }

    return 0;
}