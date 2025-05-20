//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 64
#define MIN_PASSWORD_LENGTH 8

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the length of the password
    length = strlen(password);
    if (length < MIN_PASSWORD_LENGTH) {
        printf("Password is too short.\n");
        return 1;
    }

    // Check for uppercase letters
    if (!isupper(password[0])) {
        printf("Password should contain at least one uppercase letter.\n");
        return 1;
    }

    // Check for lowercase letters
    if (!islower(password[0])) {
        printf("Password should contain at least one lowercase letter.\n");
        return 1;
    }

    // Check for digits
    if (!isdigit(password[0])) {
        printf("Password should contain at least one digit.\n");
        return 1;
    }

    // Check for special characters
    if (!strchr("!@#$%^&*()_+-=[]{}\\|;':\"<>,.?/", password[0])) {
        printf("Password should contain at least one special character.\n");
        return 1;
    }

    // All checks passed, password is strong
    printf("Password is strong.\n");
    return 0;
}