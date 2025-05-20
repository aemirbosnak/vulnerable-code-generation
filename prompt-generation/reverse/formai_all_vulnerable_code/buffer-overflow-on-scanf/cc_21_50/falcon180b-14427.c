//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: excited
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, i, upper = 0, lower = 0, digit = 0, special = 0, strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            upper = 1;
        } else if (islower(password[i])) {
            lower = 1;
        } else if (isdigit(password[i])) {
            digit = 1;
        } else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*') {
            special = 1;
        }
    }

    if (length < 8) {
        printf("Password is too short.\n");
    } else if (length >= 8 && length < 12) {
        if (upper && lower && digit) {
            printf("Password is strong.\n");
            strength = 3;
        } else if (upper && lower) {
            printf("Password is medium.\n");
            strength = 2;
        } else if (upper || lower || digit) {
            printf("Password is weak.\n");
            strength = 1;
        } else {
            printf("Password is very weak.\n");
            strength = 0;
        }
    } else if (length >= 12) {
        if (upper && lower && digit && special) {
            printf("Password is very strong.\n");
            strength = 4;
        } else if (upper && lower && digit) {
            printf("Password is strong.\n");
            strength = 3;
        } else if (upper && lower) {
            printf("Password is medium.\n");
            strength = 2;
        } else if (upper || lower || digit) {
            printf("Password is weak.\n");
            strength = 1;
        } else {
            printf("Password is very weak.\n");
            strength = 0;
        }
    }

    return 0;
}