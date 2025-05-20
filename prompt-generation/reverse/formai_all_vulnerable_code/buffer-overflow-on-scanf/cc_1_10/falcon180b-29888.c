//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
    if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '?') {
        return 1;
    }
    return 0;
}

// Function to check if a string is a valid password
int is_valid_password(char* password) {
    int has_letter = 0;
    int has_digit = 0;
    int has_special_char = 0;
    int length = strlen(password);

    if (length < 8) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (is_letter(password[i])) {
            has_letter = 1;
        }
        if (is_digit(password[i])) {
            has_digit = 1;
        }
        if (is_special_char(password[i])) {
            has_special_char = 1;
        }
    }

    if (has_letter && has_digit && has_special_char) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    if (is_valid_password(password)) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is weak.\n");
    }

    return 0;
}