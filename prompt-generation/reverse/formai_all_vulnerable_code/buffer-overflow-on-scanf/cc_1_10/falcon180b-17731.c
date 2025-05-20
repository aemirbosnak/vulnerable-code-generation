//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_MAX_LENGTH 32
#define PASSWORD_LOWER_CASE 1
#define PASSWORD_UPPER_CASE 2
#define PASSWORD_NUMBER 4
#define PASSWORD_SPECIAL_CHARACTER 8

int isPasswordValid(char *password) {
    int length = strlen(password);

    if (length < PASSWORD_MIN_LENGTH || length > PASSWORD_MAX_LENGTH) {
        printf("Password length must be between %d and %d characters.\n", PASSWORD_MIN_LENGTH, PASSWORD_MAX_LENGTH);
        return 0;
    }

    int hasLowerCase = 0;
    int hasUpperCase = 0;
    int hasNumber = 0;
    int hasSpecialChar = 0;

    for (int i = 0; i < length; i++) {
        if (isalpha(password[i])) {
            if (isupper(password[i])) {
                hasUpperCase = 1;
            } else {
                hasLowerCase = 1;
            }
        } else if (isdigit(password[i])) {
            hasNumber = 1;
        } else if (!isalnum(password[i])) {
            hasSpecialChar = 1;
        }
    }

    if (!hasLowerCase) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }

    if (!hasUpperCase) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }

    if (!hasNumber) {
        printf("Password must contain at least one number.\n");
        return 0;
    }

    if (!hasSpecialChar) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }

    return 1;
}

int main() {
    char password[PASSWORD_MAX_LENGTH];

    printf("Enter your password: ");
    scanf("%s", password);

    if (isPasswordValid(password)) {
        printf("Password is valid.\n");
    } else {
        printf("Password is not valid.\n");
    }

    return 0;
}