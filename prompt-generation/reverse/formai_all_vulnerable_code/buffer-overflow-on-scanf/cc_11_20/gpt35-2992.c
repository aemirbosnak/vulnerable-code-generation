//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isLowerCase(char c) {
    return (c >= 'a' && c <= 'z');
}

int isUpperCase(char c) {
    return (c >= 'A' && c <= 'Z');
}

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int isSpecialChar(char c) {
    switch (c) {
        case '!':
        case '@':
        case '#':
        case '$':
        case '%':
        case '^':
        case '&':
        case '*':
        case '(':
        case ')':
        case '-':
        case '_':
        case '+':
        case '=':
        case '{':
        case '}':
        case '[':
        case ']':
        case '\\':
        case '|':
        case ';':
        case ':':
        case '\'':
        case '\"':
        case ',':
        case '<':
        case '.':
        case '>':
        case '/':
        case '?':
            return 1;
        default:
            return 0;
    }
}

int main() {
    char password[50];
    int len, i, lc = 0, uc = 0, digit = 0, sp = 0;

    printf("Enter the password (maximum length is 50): ");
    scanf("%[^\n]", password);

    len = strlen(password);

    if (len < 8 || len > 50) {
        printf("Password should be between 8 and 50 characters long.\n");
        return 0;
    }

    for (i = 0; i < len; i++) {
        if (isLowerCase(password[i])) {
            lc = 1;
        }
        else if (isUpperCase(password[i])) {
            uc = 1;
        }
        else if (isDigit(password[i])) {
            digit = 1;
        }
        else if (isSpecialChar(password[i])) {
            sp = 1;
        }
    }

    if (lc && uc && digit && sp) {
        printf("Strong password!\n");
    }
    else if ((lc && uc && digit) || (lc && uc && sp) || (lc && digit && sp) || (uc && digit && sp)) {
        printf("Moderate password!\n");
    }
    else {
        printf("Weak password!\n");
    }

    return 0;
}