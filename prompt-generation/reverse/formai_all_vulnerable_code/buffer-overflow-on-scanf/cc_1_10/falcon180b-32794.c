//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: brave
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_LENGTH 16
#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_MAX_LENGTH 20

#define PASSWORD_LOWER_CASE 1
#define PASSWORD_UPPER_CASE 2
#define PASSWORD_NUMBERS 4
#define PASSWORD_SPECIAL_CHARACTERS 8

int main() {
    char password[PASSWORD_LENGTH];
    int passwordLength;
    int passwordStrength = 0;

    printf("Enter password: ");
    scanf("%s", password);
    passwordLength = strlen(password);

    if (passwordLength < PASSWORD_MIN_LENGTH) {
        printf("Password should be at least %d characters long.\n", PASSWORD_MIN_LENGTH);
        return 1;
    }

    if (passwordLength > PASSWORD_MAX_LENGTH) {
        printf("Password should not exceed %d characters.\n", PASSWORD_MAX_LENGTH);
        return 1;
    }

    if (isalpha(password[0])) {
        passwordStrength |= PASSWORD_LOWER_CASE;
    }

    for (int i = 0; i < passwordLength; i++) {
        if (isupper(password[i])) {
            passwordStrength |= PASSWORD_UPPER_CASE;
        }

        if (isdigit(password[i])) {
            passwordStrength |= PASSWORD_NUMBERS;
        }

        if (!isalnum(password[i])) {
            passwordStrength |= PASSWORD_SPECIAL_CHARACTERS;
        }
    }

    if (passwordStrength == 0) {
        printf("Password is too weak.\n");
        return 1;
    }

    printf("Password is strong.\n");
    return 0;
}