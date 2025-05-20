//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: minimalist
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LENGTH 8

int main() {
    char password[LENGTH + 1];
    int strength = 0;

    printf("Enter a password: ");
    if (scanf("%s", password)!= 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (strlen(password) < LENGTH) {
        printf("Password is too short.\n");
        return 1;
    }

    if (strlen(password) == LENGTH &&!isalpha(password[0])) {
        printf("Password must start with a letter.\n");
        return 1;
    }

    if (strspn(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") < 1) {
        printf("Password must contain at least one uppercase letter.\n");
        return 1;
    }

    if (strspn(password, "abcdefghijklmnopqrstuvwxyz") < 1) {
        printf("Password must contain at least one lowercase letter.\n");
        return 1;
    }

    if (strspn(password, "0123456789") < 1) {
        printf("Password must contain at least one digit.\n");
        return 1;
    }

    if (strspn(password, "!@#$%^&*()_+") < 1) {
        printf("Password must contain at least one special character.\n");
        return 1;
    }

    printf("Password strength: ");
    if (strlen(password) >= 12) {
        printf("Very strong\n");
        strength = 4;
    } else if (strlen(password) >= 8) {
        printf("Strong\n");
        strength = 3;
    } else if (strlen(password) >= 6) {
        printf("Moderate\n");
        strength = 2;
    } else {
        printf("Weak\n");
        strength = 1;
    }

    return 0;
}