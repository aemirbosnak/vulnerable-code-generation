//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, i, num = 0, uppercase = 0, lowercase = 0, special = 0;
    int strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    length = strlen(password);

    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            num++;
        }
        else if (isupper(password[i])) {
            uppercase++;
        }
        else if (islower(password[i])) {
            lowercase++;
        }
        else {
            special++;
        }
    }

    if (length >= 8) {
        strength++;
    }

    if (num >= 1) {
        strength++;
    }

    if (uppercase >= 1) {
        strength++;
    }

    if (lowercase >= 1) {
        strength++;
    }

    if (special >= 1) {
        strength++;
    }

    printf("Password Strength: ");

    if (strength == 0) {
        printf("Very Weak\n");
    }
    else if (strength == 1) {
        printf("Weak\n");
    }
    else if (strength == 2) {
        printf("Moderate\n");
    }
    else if (strength == 3) {
        printf("Strong\n");
    }
    else {
        printf("Very Strong\n");
    }

    return 0;
}