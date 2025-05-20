//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;
    int uppercase_count = 0;
    int lowercase_count = 0;
    int digit_count = 0;
    int special_char_count = 0;
    int total_strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    if (length < 8) {
        printf("Password is too short. Must be at least 8 characters.\n");
        return 1;
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase_count++;
        } else if (islower(password[i])) {
            lowercase_count++;
        } else if (isdigit(password[i])) {
            digit_count++;
        } else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*') {
            special_char_count++;
        }
    }

    if (uppercase_count > 0) {
        total_strength += 1;
    }
    if (lowercase_count > 0) {
        total_strength += 2;
    }
    if (digit_count > 0) {
        total_strength += 3;
    }
    if (special_char_count > 0) {
        total_strength += 4;
    }

    if (total_strength >= 4) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak. Please add more complexity.\n");
    }

    return 0;
}