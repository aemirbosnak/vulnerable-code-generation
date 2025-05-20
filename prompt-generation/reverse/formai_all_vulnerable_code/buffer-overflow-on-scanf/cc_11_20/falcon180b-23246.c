//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: active
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char password[100];
    int length, i;
    printf("Enter the password: ");
    scanf("%s", password);
    length = strlen(password);

    int uppercase = 0, lowercase = 0, digit = 0, special = 0;

    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
        }
        else if (islower(password[i])) {
            lowercase = 1;
        }
        else if (isdigit(password[i])) {
            digit = 1;
        }
        else if (isalpha(password[i]) == 0) {
            special = 1;
        }
    }

    int score = 0;

    if (length >= 8) {
        score += 1;
    }

    if (uppercase && lowercase) {
        score += 1;
    }

    if (uppercase || lowercase || digit) {
        score += 1;
    }

    if (special) {
        score += 1;
    }

    if (score <= 2) {
        printf("Weak password\n");
    }
    else if (score <= 4) {
        printf("Moderate password\n");
    }
    else {
        printf("Strong password\n");
    }

    return 0;
}