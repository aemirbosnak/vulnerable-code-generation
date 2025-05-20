//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 50

int main() {
    char password[MAX_PASSWORD_LENGTH + 1];
    int length, i;

    // Get password from user
    printf("Enter a password: ");
    scanf("%s", password);

    // Check password length
    length = strlen(password);
    if (length < 8) {
        printf("Password is too short. Passwords should be at least 8 characters long.\n");
        return 1;
    }

    // Check for uppercase letters
    if (!strspn(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ")) {
        printf("Password should contain at least one uppercase letter.\n");
        return 1;
    }

    // Check for lowercase letters
    if (!strspn(password, "abcdefghijklmnopqrstuvwxyz")) {
        printf("Password should contain at least one lowercase letter.\n");
        return 1;
    }

    // Check for digits
    if (!strspn(password, "0123456789")) {
        printf("Password should contain at least one digit.\n");
        return 1;
    }

    // Check for special characters
    if (!strspn(password, "!@#$%^&*()_+")) {
        printf("Password should contain at least one special character.\n");
        return 1;
    }

    // Check for consecutive characters
    for (i = 0; i < length - 2; i++) {
        if (password[i] == password[i+1] && password[i+1] == password[i+2]) {
            printf("Password should not contain consecutive characters.\n");
            return 1;
        }
    }

    // Check for repeated characters
    for (i = 0; i < length - 1; i++) {
        if (password[i] == password[i+1]) {
            printf("Password should not contain repeated characters.\n");
            return 1;
        }
    }

    // Password is strong
    printf("Password is strong.\n");
    return 0;
}