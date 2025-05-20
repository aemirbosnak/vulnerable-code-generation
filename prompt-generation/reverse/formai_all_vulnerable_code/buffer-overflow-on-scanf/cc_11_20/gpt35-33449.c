//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: ephemeral
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int uppercase = 0, lowercase = 0, digit = 0, special = 0;
int strength = 0, length = 0, checker = 0;

int main() {
    char password[25];

    printf("Please enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
        } else if (islower(password[i])) {
            lowercase = 1;
        } else if (isdigit(password[i])) {
            digit = 1;
        } else {
            special = 1;
        }
    }

    if (length < 8 || length > 25) {
        strength = 0;
    } else if (uppercase == 0) {
        strength = 1;
    } else if (lowercase == 0) {
        strength = 2;
    } else if (digit == 0) {
        strength = 3;
    } else if (special == 0) {
        strength = 4;
    } else {
        strength = 5;
    }

    switch(strength) {
        case 0:
            printf("\nYour password needs to be between 8 and 25 characters long!\n");
            break;
        case 1:
            printf("\nYour password needs uppercase letters!\n");
            break;
        case 2:
            printf("\nYour password needs lowercase letters!\n");
            break;
        case 3:
            printf("\nYour password needs at least one number!\n");
            break;
        case 4:
            printf("\nYour password needs at least one special character!\n");
            break;
        case 5:
            printf("\nYour password is strong enough!\n");
            checker = 1;
            break;
    }

    // let's lock the door if the password is strong enough
    if (checker == 1) {
        printf("\nDoor locked. You may proceed!\n");
    } else {
        printf("\nPassword not strong enough. Door remains unlocked!\n");
    }

    return 0;
}