//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main() {
    char password[100];
    int length, i, j;
    char lowercase, uppercase, digit, special;
    int count = 0;
    int flag = 0;

    printf("Enter the password: ");
    scanf("%s", password);

    length = strlen(password);

    for (i = 0; i < length; i++) {
        if (isalpha(password[i])) {
            if (isupper(password[i])) {
                uppercase = 1;
            } else {
                lowercase = 1;
            }
        } else if (isdigit(password[i])) {
            digit = 1;
        } else if (ispunct(password[i])) {
            special = 1;
        } else {
            printf("Invalid character detected!\n");
            exit(0);
        }
    }

    if (length < 8) {
        printf("Password should be at least 8 characters long.\n");
        exit(0);
    }

    if (!lowercase) {
        printf("Password should contain at least one lowercase letter.\n");
        exit(0);
    }

    if (!uppercase) {
        printf("Password should contain at least one uppercase letter.\n");
        exit(0);
    }

    if (!digit) {
        printf("Password should contain at least one digit.\n");
        exit(0);
    }

    if (!special) {
        printf("Password should contain at least one special character.\n");
        exit(0);
    }

    printf("Password strength: Strong\n");

    return 0;
}