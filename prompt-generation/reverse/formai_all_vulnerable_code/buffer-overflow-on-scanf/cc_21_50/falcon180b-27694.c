//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, uppercase = 0, lowercase = 0, digit = 0, special = 0, strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

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

    if (uppercase && lowercase && digit && special) {
        strength = 4;
    } else if (uppercase && lowercase && digit) {
        strength = 3;
    } else if (uppercase && lowercase) {
        strength = 2;
    } else if (uppercase || lowercase || digit) {
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