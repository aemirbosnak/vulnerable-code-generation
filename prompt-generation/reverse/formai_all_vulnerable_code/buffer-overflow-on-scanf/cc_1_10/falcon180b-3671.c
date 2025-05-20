//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_MAX_LENGTH 20
#define PASSWORD_SPECIAL_CHARS "!@#$%^&*()"
#define PASSWORD_LOWER_CASE "abcdefghijklmnopqrstuvwxyz"
#define PASSWORD_UPPER_CASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define PASSWORD_NUMBERS "0123456789"

int is_special_char(char c) {
    char *special_chars = PASSWORD_SPECIAL_CHARS;
    while (*special_chars) {
        if (c == *special_chars) {
            return 1;
        }
        special_chars++;
    }
    return 0;
}

int is_lower_case(char c) {
    char *lower_case = PASSWORD_LOWER_CASE;
    while (*lower_case) {
        if (c == *lower_case) {
            return 1;
        }
        lower_case++;
    }
    return 0;
}

int is_upper_case(char c) {
    char *upper_case = PASSWORD_UPPER_CASE;
    while (*upper_case) {
        if (c == *upper_case) {
            return 1;
        }
        upper_case++;
    }
    return 0;
}

int is_number(char c) {
    char *numbers = PASSWORD_NUMBERS;
    while (*numbers) {
        if (c == *numbers) {
            return 1;
        }
        numbers++;
    }
    return 0;
}

int is_valid_password(char *password) {
    int length = strlen(password);
    if (length < PASSWORD_MIN_LENGTH || length > PASSWORD_MAX_LENGTH) {
        return 0;
    }
    int has_special_char = 0;
    int has_lower_case = 0;
    int has_upper_case = 0;
    int has_number = 0;
    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (is_special_char(c)) {
            has_special_char = 1;
        }
        if (is_lower_case(c)) {
            has_lower_case = 1;
        }
        if (is_upper_case(c)) {
            has_upper_case = 1;
        }
        if (is_number(c)) {
            has_number = 1;
        }
    }
    if (!has_special_char ||!has_lower_case ||!has_upper_case ||!has_number) {
        return 0;
    }
    return 1;
}

int main() {
    char password[PASSWORD_MAX_LENGTH];
    printf("Enter a password: ");
    scanf("%s", password);
    if (is_valid_password(password)) {
        printf("Password is valid.\n");
    } else {
        printf("Password is not valid.\n");
    }
    return 0;
}