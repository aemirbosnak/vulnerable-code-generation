//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: light-weight
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 100
#define MIN_LENGTH 8

int isPasswordValid(char *password) {
    int length = strlen(password);
    if (length < MIN_LENGTH) {
        printf("Password must be at least %d characters long.\n", MIN_LENGTH);
        return 0;
    }

    int hasUppercase = 0;
    int hasLowercase = 0;
    int hasNumber = 0;
    int hasSpecialChar = 0;

    for (int i = 0; i < length; i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            if (isupper(c)) {
                hasUppercase = 1;
            } else {
                hasLowercase = 1;
            }
        } else if (isdigit(c)) {
            hasNumber = 1;
        } else {
            hasSpecialChar = 1;
        }
    }

    if (!hasUppercase) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }

    if (!hasLowercase) {
        printf("Password must contain at least one lowercase letter.\n");
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

    printf("Password is strong!\n");
    return 1;
}

int main() {
    char password[MAX_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);

    int result = isPasswordValid(password);
    if (result) {
        printf("Password is strong!\n");
    }

    return 0;
}