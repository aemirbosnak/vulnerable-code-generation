//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100
#define MIN_PASSWORD_LENGTH 8
#define MIN_LOWER_CASE_COUNT 1
#define MIN_UPPER_CASE_COUNT 1
#define MIN_NUMERIC_COUNT 1
#define MIN_SPECIAL_COUNT 1

int is_lower_case(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_upper_case(char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_numeric(char c) {
    return (c >= '0' && c <= '9');
}

int is_special_char(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '+' || c == '-' || c == '/' || c == '=' || c == '?' || c == '^' || c == '_' || c == '~');
}

int count_lower_case(char* password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (is_lower_case(password[i])) {
            count++;
        }
    }
    return count;
}

int count_upper_case(char* password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (is_upper_case(password[i])) {
            count++;
        }
    }
    return count;
}

int count_numeric(char* password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (is_numeric(password[i])) {
            count++;
        }
    }
    return count;
}

int count_special_chars(char* password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (is_special_char(password[i])) {
            count++;
        }
    }
    return count;
}

int password_strength(char* password) {
    int length = strlen(password);
    if (length < MIN_PASSWORD_LENGTH) {
        return 0;
    }
    int lower_case_count = count_lower_case(password);
    int upper_case_count = count_upper_case(password);
    int numeric_count = count_numeric(password);
    int special_count = count_special_chars(password);
    if (lower_case_count < MIN_LOWER_CASE_COUNT || upper_case_count < MIN_UPPER_CASE_COUNT || numeric_count < MIN_NUMERIC_COUNT || special_count < MIN_SPECIAL_COUNT) {
        return 1;
    }
    return 2;
}

void main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);
    int strength = password_strength(password);
    if (strength == 0) {
        printf("Password is too short.\n");
    } else if (strength == 1) {
        printf("Password is weak.\n");
    } else {
        printf("Password is strong.\n");
    }
}