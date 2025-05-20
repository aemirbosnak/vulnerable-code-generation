//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: introspective
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8

// Function to check if a character is a digit
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Function to check if a character is a lowercase letter
int is_lowercase(char c) {
    return c >= 'a' && c <= 'z';
}

// Function to check if a character is an uppercase letter
int is_uppercase(char c) {
    return c >= 'A' && c <= 'Z';
}

// Function to check if a character is a special character
int is_special(char c) {
    return strchr("!@#$%^&*()_-+=", c)!= NULL;
}

// Function to check if a password meets the minimum strength requirements
int is_strong_password(char* password) {
    int length = strlen(password);
    int has_digit = 0;
    int has_lowercase = 0;
    int has_uppercase = 0;
    int has_special = 0;

    if (length < MIN_PASSWORD_LENGTH) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (is_digit(password[i])) {
            has_digit = 1;
        }
        else if (is_lowercase(password[i])) {
            has_lowercase = 1;
        }
        else if (is_uppercase(password[i])) {
            has_uppercase = 1;
        }
        else if (is_special(password[i])) {
            has_special = 1;
        }
    }

    if (!has_digit ||!has_lowercase ||!has_uppercase ||!has_special) {
        return 0;
    }

    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    if (is_strong_password(password)) {
        printf("Password is strong!\n");
    }
    else {
        printf("Password is weak!\n");
    }

    return 0;
}