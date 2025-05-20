//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 100
#define MIN_LENGTH 8
#define MIN_LOWER 1
#define MIN_UPPER 1
#define MIN_DIGIT 1
#define MIN_SPECIAL 1

int is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_upper(char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int is_special(char c) {
    return (!isalnum(c));
}

int has_lower(char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (is_lower(str[i])) {
            return 1;
        }
    }
    return 0;
}

int has_upper(char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (is_upper(str[i])) {
            return 1;
        }
    }
    return 0;
}

int has_digit(char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (is_digit(str[i])) {
            return 1;
        }
    }
    return 0;
}

int has_special(char* str) {
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (is_special(str[i])) {
            return 1;
        }
    }
    return 0;
}

int meets_requirements(char* str) {
    return (has_lower(str) && has_upper(str) && has_digit(str) && has_special(str));
}

int main() {
    char password[MAX_LENGTH];
    int length, i;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    if (length < MIN_LENGTH) {
        printf("Password must be at least %d characters long.\n", MIN_LENGTH);
        return 1;
    }

    if (!meets_requirements(password)) {
        printf("Password must contain at least one lowercase letter, one uppercase letter, one digit, and one special character.\n");
        return 1;
    }

    printf("Your password is strong enough.\n");
    return 0;
}