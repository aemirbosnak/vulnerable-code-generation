//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 50

int isPasswordValid(char *password);

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    if (isPasswordValid(password)) {
        printf("Your password is strong!\n");
    } else {
        printf("Your password is weak.\n");
    }

    return 0;
}

int isPasswordValid(char *password) {
    int hasDigit = 0;
    int hasUpperCase = 0;
    int hasLowerCase = 0;
    int hasSpecialChar = 0;

    int i;
    for (i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            hasDigit = 1;
        } else if (isupper(password[i])) {
            hasUpperCase = 1;
        } else if (islower(password[i])) {
            hasLowerCase = 1;
        } else if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%' || password[i] == '&' || password[i] == '*' || password[i] == '?') {
            hasSpecialChar = 1;
        }
    }

    if (hasDigit && hasUpperCase && hasLowerCase && hasSpecialChar) {
        return 1;
    } else {
        return 0;
    }
}