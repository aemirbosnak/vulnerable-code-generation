//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 32
#define MIN_PASSWORD_LENGTH 8
#define MIN_NUMERIC_CHARS 1
#define MIN_LOWERCASE_CHARS 1
#define MIN_UPPERCASE_CHARS 1
#define MIN_SPECIAL_CHARS 1

int is_numeric(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int is_lowercase(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!islower(str[i])) {
            return 0;
        }
    }
    return 1;
}

int is_uppercase(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isupper(str[i])) {
            return 0;
        }
    }
    return 1;
}

int is_special(char* str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isalpha(str[i]) &&!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int is_valid_password(char* password) {
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        return 0;
    }
    int numeric_chars = is_numeric(password);
    int lowercase_chars = is_lowercase(password);
    int uppercase_chars = is_uppercase(password);
    int special_chars = is_special(password);
    if (numeric_chars < MIN_NUMERIC_CHARS ||
        lowercase_chars < MIN_LOWERCASE_CHARS ||
        uppercase_chars < MIN_UPPERCASE_CHARS ||
        special_chars < MIN_SPECIAL_CHARS) {
        return 0;
    }
    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);
    if (is_valid_password(password)) {
        printf("Your password is strong!\n");
    } else {
        printf("Your password is weak.\n");
    }
    return 0;
}