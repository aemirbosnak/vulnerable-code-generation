//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MIN_LENGTH 8

int main() {
    char password[100];
    int strength;

    printf("Enter your password: ");
    scanf("%s", password);

    strength = check_password_strength(password);

    switch (strength) {
        case 0:
            printf("Your password is weak.\n");
            break;
        case 1:
            printf("Your password is moderate.\n");
            break;
        case 2:
            printf("Your password is strong.\n");
            break;
        case 3:
            printf("Your password is very strong.\n");
            break;
    }

    return 0;
}

int check_password_strength(char *password) {
    int length, uppercase, lowercase, digit, special;

    length = strlen(password);

    if (length < MIN_LENGTH) {
        return 0;
    }

    uppercase = 0;
    lowercase = 0;
    digit = 0;
    special = 0;

    for (int i = 0; i < length; i++) {
        char c = password[i];

        if (c >= 'A' && c <= 'Z') {
            uppercase++;
        } else if (c >= 'a' && c <= 'z') {
            lowercase++;
        } else if (c >= '0' && c <= '9') {
            digit++;
        } else {
            special++;
        }
    }

    if (uppercase == 0 || lowercase == 0 || digit == 0 || special == 0) {
        return 1;
    }

    if (uppercase >= 2 && lowercase >= 2 && digit >= 2 && special >= 2) {
        return 3;
    }

    return 2;
}