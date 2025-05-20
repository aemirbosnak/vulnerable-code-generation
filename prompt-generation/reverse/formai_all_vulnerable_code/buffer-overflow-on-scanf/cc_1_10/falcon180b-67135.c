//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 32

bool is_lowercase(char c) {
    return (c >= 'a' && c <= 'z');
}

bool is_uppercase(char c) {
    return (c >= 'A' && c <= 'Z');
}

bool is_digit(char c) {
    return (c >= '0' && c <= '9');
}

bool is_special_character(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*');
}

int count_lowercase(char* password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (is_lowercase(password[i])) {
            count++;
        }
    }
    return count;
}

int count_uppercase(char* password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (is_uppercase(password[i])) {
            count++;
        }
    }
    return count;
}

int count_digits(char* password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (is_digit(password[i])) {
            count++;
        }
    }
    return count;
}

int count_special_characters(char* password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (is_special_character(password[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    int lowercase_count = count_lowercase(password);
    int uppercase_count = count_uppercase(password);
    int digit_count = count_digits(password);
    int special_character_count = count_special_characters(password);

    if (lowercase_count > 0 && uppercase_count > 0 && digit_count > 0 && special_character_count > 0) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is weak.\n");
    }

    return 0;
}