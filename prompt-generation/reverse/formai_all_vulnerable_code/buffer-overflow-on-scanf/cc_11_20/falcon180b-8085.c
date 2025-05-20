//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100

// Function to check if a character is a letter
int is_letter(char c) {
    if (isalpha(c)) {
        return 1;
    }
    return 0;
}

// Function to check if a character is a digit
int is_digit(char c) {
    if (isdigit(c)) {
        return 1;
    }
    return 0;
}

// Function to check if a character is a special character
int is_special_char(char c) {
    if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '?' || c == '-' || c == '_' || c == '+' || c == '=' || c == '~' || c == '^' || c == '|' || c == '{' || c == '}' || c == '[' || c == ']' || c == ';' || c == ':' || c == '"' || c == '\'' || c == ',' || c == '.' || c == '/' || c == '\\' || c == '<' || c == '>') {
        return 1;
    }
    return 0;
}

// Function to check the strength of a password
int check_password_strength(char *password) {
    int length = strlen(password);
    int has_letter = 0;
    int has_digit = 0;
    int has_special_char = 0;
    int has_uppercase = 0;
    int has_lowercase = 0;

    for (int i = 0; i < length; i++) {
        char c = password[i];
        if (is_letter(c)) {
            has_letter = 1;
        }
        if (is_digit(c)) {
            has_digit = 1;
        }
        if (is_special_char(c)) {
            has_special_char = 1;
        }
        if (isupper(c)) {
            has_uppercase = 1;
        }
        if (islower(c)) {
            has_lowercase = 1;
        }
    }

    if (length < 8) {
        return 1; // Weak
    } else if (length >= 8 && length < 12 && has_letter && has_digit && has_special_char) {
        return 2; // Medium
    } else if (length >= 12 && has_letter && has_digit && has_special_char && has_uppercase && has_lowercase) {
        return 3; // Strong
    } else {
        return 0; // Unknown
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter a password: ");
    scanf("%s", password);

    int strength = check_password_strength(password);

    switch (strength) {
        case 1:
            printf("Weak\n");
            break;
        case 2:
            printf("Medium\n");
            break;
        case 3:
            printf("Strong\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }

    return 0;
}