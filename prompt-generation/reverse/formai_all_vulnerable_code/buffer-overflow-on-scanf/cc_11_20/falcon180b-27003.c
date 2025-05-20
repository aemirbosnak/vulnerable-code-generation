//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char password[100];
    int length, uppercase = 0, lowercase = 0, digit = 0, special = 0;
    int strength = 0;

    printf("Enter password: ");
    scanf("%s", password);

    length = strlen(password);

    if (length >= 8) {
        strength++;
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercase = 1;
        } else if (islower(password[i])) {
            lowercase = 1;
        } else if (isdigit(password[i])) {
            digit = 1;
        } else if (isalpha(password[i]) == 0) {
            special = 1;
        }
    }

    if (uppercase && lowercase && digit && special) {
        strength += 2;
    } else if (uppercase && lowercase && digit) {
        strength++;
    } else if (uppercase && lowercase) {
        strength++;
    }

    printf("Password strength: ");

    if (strength >= 4) {
        printf("Strong\n");
    } else if (strength == 3) {
        printf("Medium\n");
    } else {
        printf("Weak\n");
    }

    return 0;
}