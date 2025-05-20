//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100

int main(void) {
    char password[MAX_PASSWORD_LENGTH + 1];
    int length, i;

    printf("Enter a password: ");
    scanf("%s", password);
    length = strlen(password);

    if (length < 8 || length > MAX_PASSWORD_LENGTH) {
        printf("Password length must be between 8 and %d characters.\n", MAX_PASSWORD_LENGTH);
        return 1;
    }

    if (!isalpha(password[0])) {
        printf("Password must start with a letter.\n");
        return 1;
    }

    for (i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            printf("Password must contain only letters and numbers.\n");
            return 1;
        }
    }

    if (strspn(password, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == 0) {
        printf("Password must contain at least one uppercase and one lowercase letter.\n");
        return 1;
    }

    if (strspn(password, "0123456789") == 0) {
        printf("Password must contain at least one number.\n");
        return 1;
    }

    if (strspn(password, "!@#$%^&*()_-+={}[]|\:;\"'<>,.?/") == 0) {
        printf("Password must contain at least one special character.\n");
        return 1;
    }

    printf("Password is strong.\n");
    return 0;
}