//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 100

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int length, i;

    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);

    if (length < 8 || length > MAX_PASSWORD_LENGTH) {
        printf("Password length must be between 8 and %d characters.\n", MAX_PASSWORD_LENGTH);
        return 1;
    }

    int has_uppercase = 0, has_lowercase = 0, has_digit = 0, has_special = 0;
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_digit = 1;
        } else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*') {
            has_special = 1;
        }
    }

    int score = 0;
    if (has_uppercase) {
        score++;
    }
    if (has_lowercase) {
        score++;
    }
    if (has_digit) {
        score++;
    }
    if (has_special) {
        score++;
    }

    if (score < 3) {
        printf("Password is weak.\n");
    } else if (score == 3) {
        printf("Password is average.\n");
    } else {
        printf("Password is strong.\n");
    }

    return 0;
}