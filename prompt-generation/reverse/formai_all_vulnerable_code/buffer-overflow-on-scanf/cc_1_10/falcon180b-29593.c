//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 100

bool is_upper_case(char c) {
    return (c >= 'A' && c <= 'Z');
}

bool is_lower_case(char c) {
    return (c >= 'a' && c <= 'z');
}

bool is_digit(char c) {
    return (c >= '0' && c <= '9');
}

bool is_special_char(char c) {
    return (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*' || c == '?' || c == '-' || c == '+');
}

int main() {
    char password[MAX_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);

    int length = strlen(password);
    if (length < 8) {
        printf("Password is too short.\n");
        return 1;
    }

    bool has_upper_case = false;
    bool has_lower_case = false;
    bool has_digit = false;
    bool has_special_char = false;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (is_upper_case(c)) {
            has_upper_case = true;
        } else if (is_lower_case(c)) {
            has_lower_case = true;
        } else if (is_digit(c)) {
            has_digit = true;
        } else if (is_special_char(c)) {
            has_special_char = true;
        }
    }

    if (!has_upper_case ||!has_lower_case ||!has_digit ||!has_special_char) {
        printf("Password must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
        return 1;
    }

    printf("Password is strong enough.\n");
    return 0;
}