//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUM_TYPES 4
#define MAX_PASSWORD_LEN 64

enum {
    TYPE_LOWER = 1,
    TYPE_UPPER = 2,
    TYPE_NUMBER = 4,
    TYPE_SPECIAL = 8
};

int is_lower(char c) {
    return (c >= 'a' && c <= 'z');
}

int is_upper(char c) {
    return (c >= 'A' && c <= 'Z');
}

int is_number(char c) {
    return (c >= '0' && c <= '9');
}

int is_special(char c) {
    return (!is_lower(c) &&!is_upper(c) &&!is_number(c));
}

int check_password(char* password) {
    int length = strlen(password);
    if (length < 8 || length > MAX_PASSWORD_LEN) {
        return 0;
    }
    int types_count = 0;
    if (is_lower(password[0])) {
        types_count |= TYPE_LOWER;
    }
    if (is_upper(password[0])) {
        types_count |= TYPE_UPPER;
    }
    if (is_number(password[0])) {
        types_count |= TYPE_NUMBER;
    }
    if (is_special(password[0])) {
        types_count |= TYPE_SPECIAL;
    }
    for (int i = 1; i < length; i++) {
        if (is_lower(password[i])) {
            types_count |= TYPE_LOWER;
        }
        if (is_upper(password[i])) {
            types_count |= TYPE_UPPER;
        }
        if (is_number(password[i])) {
            types_count |= TYPE_NUMBER;
        }
        if (is_special(password[i])) {
            types_count |= TYPE_SPECIAL;
        }
    }
    if (types_count >= NUM_TYPES) {
        return 1;
    }
    return 0;
}

int main() {
    char password[MAX_PASSWORD_LEN + 1];
    printf("Enter password: ");
    scanf("%s", password);
    if (check_password(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }
    return 0;
}