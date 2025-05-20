//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 50 // Maximum length of password
#define MIN_LENGTH 8 // Minimum length of password
#define NUM_LOWER 26 // Number of lowercase letters
#define NUM_UPPER 26 // Number of uppercase letters
#define NUM_DIGITS 10 // Number of digits
#define NUM_SPECIAL 12 // Number of special characters

int check_password(char password[MAX_LENGTH]) {
    int has_lowercase = 0, has_uppercase = 0, has_digit = 0, has_special = 0;
    int length = strlen(password);

    if (length < MIN_LENGTH) {
        printf("Password is too short.\n");
        return 0;
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }

    // Check for digits
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_digit = 1;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*' || password[i] == '(' || password[i] == ')' || password[i] == '-' || password[i] == '_' || password[i] == '+' || password[i] == '=' || password[i] == '{' || password[i] == '}' || password[i] == '[' || password[i] == ']' || password[i] == '|' || password[i] == '\\' || password[i] == ';' || password[i] == ':' || password[i] == '"' || password[i] == '\'' || password[i] == ',') {
            has_special = 1;
            break;
        }
    }

    // Check if password meets all requirements
    if (has_lowercase && has_uppercase && has_digit && has_special) {
        printf("Password is strong.\n");
        return 1;
    } else {
        printf("Password is weak.\n");
        return 0;
    }
}

int main() {
    char password[MAX_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);

    int result = check_password(password);
    return result;
}