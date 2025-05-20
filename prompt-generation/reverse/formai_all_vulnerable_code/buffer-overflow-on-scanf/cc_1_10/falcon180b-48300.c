//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 20

int isPasswordValid(char password[MAX_PASSWORD_LENGTH]);
int isPasswordStrong(char password[MAX_PASSWORD_LENGTH]);

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your password: ");
    scanf("%s", password);

    if (isPasswordValid(password)) {
        if (isPasswordStrong(password)) {
            printf("Your password is strong.\n");
        } else {
            printf("Your password is valid but weak.\n");
        }
    } else {
        printf("Invalid password.\n");
    }

    return 0;
}

int isPasswordValid(char password[MAX_PASSWORD_LENGTH]) {
    int length = strlen(password);

    if (length < 8 || length > MAX_PASSWORD_LENGTH) {
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (!isalpha(password[i]) &&!isdigit(password[i])) {
            return 0;
        }
    }

    return 1;
}

int isPasswordStrong(char password[MAX_PASSWORD_LENGTH]) {
    int length = strlen(password);
    int hasUppercase = 0;
    int hasLowercase = 0;
    int hasDigit = 0;
    int hasSpecialChar = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUppercase = 1;
        } else if (islower(password[i])) {
            hasLowercase = 1;
        } else if (isdigit(password[i])) {
            hasDigit = 1;
        } else if (password[i] == '!'|| password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '^' || password[i] == '&' || password[i] == '*') {
            hasSpecialChar = 1;
        }
    }

    if (length >= 8 && hasUppercase && hasLowercase && hasDigit && hasSpecialChar) {
        return 1;
    }

    return 0;
}