//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LENGTH 8
#define UPPER 1
#define LOWER 2
#define NUMBER 4
#define SPECIAL 8

int is_valid_password(char *password);

int main() {
    char password[LENGTH + 1];

    printf("Enter your password: ");
    scanf("%s", password);

    if (is_valid_password(password)) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is weak.\n");
    }

    return 0;
}

int is_valid_password(char *password) {
    int upper = 0, lower = 0, number = 0, special = 0;
    int valid_chars = 0;

    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            upper = 1;
        } else if (islower(password[i])) {
            lower = 1;
        } else if (isdigit(password[i])) {
            number = 1;
        } else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*') {
            special = 1;
        }

        valid_chars++;
    }

    if (valid_chars < LENGTH) {
        return 0;
    }

    if (upper && lower && number && special) {
        return 1;
    }

    return 0;
}