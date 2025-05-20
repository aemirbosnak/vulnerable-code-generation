//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 100

int main() {
    char password[MAX_LEN];
    int length, i;
    int uppercase = 0, lowercase = 0, number = 0, special = 0;
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
        } else if (islower(password[i])) {
            lowercase = 1;
        } else if (isdigit(password[i])) {
            number = 1;
        } else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*') {
            special = 1;
        }
    }

    if (length < 8) {
        printf("Password is too short.\n");
        return 0;
    }

    if (uppercase && lowercase && number && special) {
        strength = 4;
        printf("Password is very strong.\n");
    } else if (uppercase && lowercase && (number || special)) {
        strength = 3;
        printf("Password is strong.\n");
    } else if (uppercase && lowercase || number && special) {
        strength = 2;
        printf("Password is moderate.\n");
    } else if (uppercase || lowercase || number || special) {
        strength = 1;
        printf("Password is weak.\n");
    } else {
        strength = 0;
        printf("Password is very weak.\n");
    }

    return 0;
}