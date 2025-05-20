//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: careful
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool is_lowercase(char c) {
    return (c >= 'a' && c <= 'z');
}

bool is_uppercase(char c) {
    return (c >= 'A' && c <= 'Z');
}

bool is_digit(char c) {
    return (c >= '0' && c <= '9');
}

bool is_special(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '_' || c == '+' || c == '=' || c == '{' || c == '}' || c == '|' || c == '~' || c == '`' || c == '[' || c == ']' || c == ';' || c == ':' || c == '\'' || c == '"' || c == ',' || c == '.' || c == '/' || c == '<' || c == '>' || c == '?' || c == '{' || c == '}' || c == '|' || c == '\\');
}

int main() {
    char password[100];
    int i, j, count = 0, strength = 0;

    printf("Enter password: ");
    scanf("%s", password);

    for (i = 0; i < strlen(password); i++) {
        if (is_lowercase(password[i]))
            count++;
        if (is_uppercase(password[i]))
            count++;
        if (is_digit(password[i]))
            count++;
        if (is_special(password[i]))
            count++;

        if (count >= 3)
            strength++;
    }

    if (strength >= 5)
        printf("Password strength: Strong\n");
    else if (strength >= 3)
        printf("Password strength: Medium\n");
    else
        printf("Password strength: Weak\n");

    return 0;
}