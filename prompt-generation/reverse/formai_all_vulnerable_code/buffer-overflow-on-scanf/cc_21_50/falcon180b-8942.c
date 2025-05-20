//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char password[100];
    int length, i, upper, lower, digit, special;

    printf("Enter a password: ");
    scanf("%s", password);

    length = strlen(password);

    upper = lower = digit = special = 0;

    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upper++;
        } else if (islower(password[i])) {
            lower++;
        } else if (isdigit(password[i])) {
            digit++;
        } else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*' || password[i] == '?') {
            special++;
        }
    }

    if (length < 8) {
        printf("Password is too short.\n");
    } else if (upper == 0 || lower == 0 || digit == 0) {
        printf("Password must contain at least one uppercase letter, one lowercase letter, and one digit.\n");
    } else if (special == 0) {
        printf("Password must contain at least one special character.\n");
    } else {
        int complexity = 0;

        if (length >= 12) {
            complexity++;
        }

        if (upper >= 2) {
            complexity++;
        }

        if (lower >= 2) {
            complexity++;
        }

        if (digit >= 2) {
            complexity++;
        }

        if (special >= 2) {
            complexity++;
        }

        if (complexity == 0) {
            printf("Password is weak.\n");
        } else if (complexity == 1) {
            printf("Password is average.\n");
        } else {
            printf("Password is strong.\n");
        }
    }

    return 0;
}