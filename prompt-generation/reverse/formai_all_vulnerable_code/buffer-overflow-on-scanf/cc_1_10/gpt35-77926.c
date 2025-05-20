//FormAI DATASET v1.0 Category: Data validation ; Style: thoughtful
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool is_valid_int(const char *str);
bool is_valid_double(const char *str);
bool is_valid_email(const char *str);

int main() {
    char input[256];
    printf("Enter an integer: ");
    scanf("%s", input);
    if (is_valid_int(input)) {
        printf("Valid integer: %s\n", input);
    } else {
        printf("Invalid integer: %s\n", input);
    }

    printf("Enter a double: ");
    scanf("%s", input);
    if (is_valid_double(input)) {
        printf("Valid double: %s\n", input);
    } else {
        printf("Invalid double: %s\n", input);
    }

    printf("Enter an email: ");
    scanf("%s", input);
    if (is_valid_email(input)) {
        printf("Valid email: %s\n", input);
    } else {
        printf("Invalid email: %s\n", input);
    }

    return 0;
}

bool is_valid_int(const char *str) {
    if (*str == '+' || *str == '-') {
        ++str;
    }
    if (!isdigit(*str)) {
        return false;
    }
    ++str;
    while (*str) {
        if (!isdigit(*str)) {
            return false;
        }
        ++str;
    }
    return true;
}

bool is_valid_double(const char *str) {
    if (*str == '+' || *str == '-') {
        ++str;
    }
    if (!isdigit(*str)) {
        return false;
    }
    ++str;
    bool has_decimal = false;
    while (*str) {
        if (*str == '.' && !has_decimal) {
            has_decimal = true;
        } else if (!isdigit(*str)) {
            return false;
        }
        ++str;
    }
    return true;
}

bool is_valid_email(const char *str) {
    bool has_at = false;
    while (*str) {
        if (*str == '@') {
            if (has_at) {
                return false;
            } else {
                has_at = true;
            }
        } else if (!isalnum(*str) && *str != '.' && *str != '-' && *str != '_') {
            return false;
        }
        ++str;
    }
    return has_at;
}