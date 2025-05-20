//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[101];
    int strength = 0;

    printf("Enter a password: ");
    scanf("%s", password);

    int len = strlen(password);
    if (len < 8 || len > 16) {
        printf("Password length must be between 8 and 16 characters.\n");
    } else {
        strength += 4;
    }

    int hasUppercase = 0;
    int hasLowercase = 0;
    int hasDigit = 0;
    int hasSpecialChar = 0;
    for (int i = 0; i < len; i++) {
        if (isupper(password[i])) {
            hasUppercase = 1;
        } else if (islower(password[i])) {
            hasLowercase = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        } else {
            hasSpecialChar = 1;
        }
    }

    if (hasUppercase && hasLowercase && hasDigit) {
        strength += 3;
    }

    if (hasSpecialChar) {
        strength += 1;
    }

    if (strength < 4) {
        printf("Password strength: Weak\n");
    } else if (strength == 4) {
        printf("Password strength: Fair\n");
    } else if (strength == 5) {
        printf("Password strength: Good\n");
    } else {
        printf("Password strength: Strong\n");
    }

    return 0;
}