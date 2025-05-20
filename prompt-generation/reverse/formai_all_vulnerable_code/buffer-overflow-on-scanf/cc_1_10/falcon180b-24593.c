//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: synchronous
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 50

// Function to determine if a character is a letter
bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to determine if a character is a digit
bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Function to determine if a character is a special character
bool isSpecial(char c) {
    return c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '?' || c == '!' || c == '-' || c == '+' || c == '=' || c == '~' || c == '`' || c == '{' || c == '}' || c == '[' || c == ']' || c == '|' || c == ';' || c == ':' || c == '"' || c == '\'' || c == '<' || c == '>' || c == ',' || c == '.' || c == '/' || c == '\\' || c == '^' || c == '_';
}

// Function to check if password contains at least one letter, one digit and one special character
bool isPasswordValid(char* password) {
    int length = strlen(password);
    if (length < 8 || length > MAX_PASSWORD_LENGTH) {
        return false;
    }
    bool hasLetter = false;
    bool hasDigit = false;
    bool hasSpecialCharacter = false;
    for (int i = 0; i < length; i++) {
        if (isLetter(password[i])) {
            hasLetter = true;
        } else if (isDigit(password[i])) {
            hasDigit = true;
        } else if (isSpecial(password[i])) {
            hasSpecialCharacter = true;
        }
    }
    return hasLetter && hasDigit && hasSpecialCharacter;
}

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    printf("Enter password: ");
    scanf("%s", password);
    if (isPasswordValid(password)) {
        printf("Password is valid.\n");
    } else {
        printf("Password is not valid.\n");
    }
    return 0;
}