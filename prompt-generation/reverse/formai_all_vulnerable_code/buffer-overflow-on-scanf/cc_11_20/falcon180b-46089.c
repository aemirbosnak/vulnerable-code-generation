//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    int length = strlen(password);
    int uppercase = 0, lowercase = 0, numbers = 0, symbols = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
        } else if (islower(password[i])) {
            lowercase = 1;
        } else if (isdigit(password[i])) {
            numbers = 1;
        } else if (ispunct(password[i])) {
            symbols = 1;
        }
    }

    int score = 0;

    if (length >= 8) {
        score += 1;
    }

    if (uppercase && lowercase) {
        score += 2;
    } else if (uppercase || lowercase) {
        score += 1;
    }

    if (numbers && symbols) {
        score += 2;
    } else if (numbers || symbols) {
        score += 1;
    }

    if (score <= 2) {
        printf("Your password is very weak.\n");
    } else if (score <= 4) {
        printf("Your password is weak.\n");
    } else if (score <= 6) {
        printf("Your password is moderate.\n");
    } else {
        printf("Your password is strong.\n");
    }

    return 0;
}