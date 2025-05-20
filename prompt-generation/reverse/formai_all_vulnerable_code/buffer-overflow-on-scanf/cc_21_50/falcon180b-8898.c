//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 100
#define MIN_LENGTH 8

int main() {
    char password[MAX_LENGTH];
    int length = 0;
    int uppercase = 0, lowercase = 0, numbers = 0, special = 0;
    int strength = 0;
    int i;
    srand(time(NULL));

    printf("Enter a password: ");
    scanf("%s", password);

    length = strlen(password);

    if (length < MIN_LENGTH) {
        printf("Password is too short.\n");
        return 0;
    }

    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
        } else if (islower(password[i])) {
            lowercase = 1;
        } else if (isdigit(password[i])) {
            numbers = 1;
        } else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*') {
            special = 1;
        }
    }

    if (uppercase && lowercase && numbers && special) {
        strength = 4;
    } else if ((uppercase || lowercase) && numbers && special) {
        strength = 3;
    } else if ((uppercase || lowercase) && numbers) {
        strength = 2;
    } else if (uppercase || lowercase || numbers) {
        strength = 1;
    } else {
        strength = 0;
    }

    switch (strength) {
        case 4:
            printf("Password is very strong.\n");
            break;
        case 3:
            printf("Password is strong.\n");
            break;
        case 2:
            printf("Password is moderate.\n");
            break;
        case 1:
            printf("Password is weak.\n");
            break;
        default:
            printf("Password is very weak.\n");
            break;
    }

    return 0;
}