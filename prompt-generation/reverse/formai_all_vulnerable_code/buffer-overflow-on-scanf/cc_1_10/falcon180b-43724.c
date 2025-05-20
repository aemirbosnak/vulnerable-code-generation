//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: protected
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 50

int isPasswordValid(char *password) {
    int length = strlen(password);
    int hasUppercase = 0;
    int hasLowercase = 0;
    int hasNumber = 0;
    int hasSpecialChar = 0;

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUppercase = 1;
        } else if (islower(password[i])) {
            hasLowercase = 1;
        } else if (isdigit(password[i])) {
            hasNumber = 1;
        } else if (!isalnum(password[i])) {
            hasSpecialChar = 1;
        }
    }

    if (length < 8) {
        return 0;
    }

    if (!hasUppercase) {
        return 0;
    }

    if (!hasLowercase) {
        return 0;
    }

    if (!hasNumber) {
        return 0;
    }

    if (!hasSpecialChar) {
        return 0;
    }

    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter password: ");
    scanf("%s", password);

    if (isPasswordValid(password)) {
        printf("Password is valid.\n");
    } else {
        printf("Password is not valid.\n");
    }

    return 0;
}