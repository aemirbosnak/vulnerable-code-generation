//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: careful
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char password[101];
    int strength = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    int len = strlen(password);
    if (len < 8) {
        strength += 1;
    } else if (len >= 8 && len <= 12) {
        strength += 2;
    } else if (len > 12) {
        strength += 3;
    }

    int hasUpper = 0;
    int hasLower = 0;
    int hasDigit = 0;
    int hasSymbol = 0;

    for (int i = 0; i < len; i++) {
        if (isupper(password[i])) {
            hasUpper = 1;
        } else if (islower(password[i])) {
            hasLower = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        } else {
            hasSymbol = 1;
        }
    }

    if (hasUpper) {
        strength += 1;
    }
    if (hasLower) {
        strength += 1;
    }
    if (hasDigit) {
        strength += 1;
    }
    if (hasSymbol) {
        strength += 1;
    }

    if (strength >= 4) {
        printf("Your password is strong.\n");
    } else if (strength == 3) {
        printf("Your password is moderately strong.\n");
    } else if (strength == 2) {
        printf("Your password is weak.\n");
    } else {
        printf("Your password is very weak.\n");
    }

    return 0;
}