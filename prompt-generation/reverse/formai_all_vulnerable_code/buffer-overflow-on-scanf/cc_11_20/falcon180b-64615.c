//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: genious
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char password[100];
    int length, i;

    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    if (length < 8) {
        printf("Password is too short.\n");
        return 0;
    }

    int has_uppercase = 0, has_lowercase = 0, has_digit = 0, has_special = 0;

    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
        } else if (islower(password[i])) {
            has_lowercase = 1;
        } else if (isdigit(password[i])) {
            has_digit = 1;
        } else if (!isalnum(password[i])) {
            has_special = 1;
        }
    }

    if (!has_uppercase ||!has_lowercase ||!has_digit ||!has_special) {
        printf("Password must contain at least one uppercase letter, one lowercase letter, one digit, and one special character.\n");
        return 0;
    }

    int score = 0;
    if (length >= 8 && length <= 11) {
        score = 1;
    } else if (length >= 12 && length <= 15) {
        score = 2;
    } else if (length >= 16) {
        score = 3;
    }

    printf("Password strength score: %d\n", score);

    return 0;
}