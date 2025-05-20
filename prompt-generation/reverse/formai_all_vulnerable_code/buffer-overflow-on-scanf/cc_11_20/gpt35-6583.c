//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[50];
    int i, len;
    int upper, lower, digit, symbol, strength;

    printf("Enter password to be checked: ");
    scanf("%s", password);
    len = strlen(password);

    upper = lower = digit = symbol = 0;

    for (i = 0; i < len; i++) {
        if (isupper(password[i]))
            upper = 1;
        if (islower(password[i]))
            lower = 1;
        if (isdigit(password[i]))
            digit = 1;
        if (!isalnum(password[i]))
            symbol = 1;
    }

    strength = upper + lower + digit + symbol;

    printf("\nPassword Strength Meter\n");
    printf("------------------------\n");

    switch(strength) {
        case 0:
            printf("Password too weak.\n");
            break;
        case 1:
            printf("Weak password.\n");
            break;
        case 2:
            printf("Moderate password.\n");
            break;
        case 3:
            printf("Strong password.\n");
            break;
        case 4:
            printf("Very strong password.\n");
            break;
    }

    return 0;
}