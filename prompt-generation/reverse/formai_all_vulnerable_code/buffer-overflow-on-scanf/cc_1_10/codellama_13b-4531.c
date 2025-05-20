//Code Llama-13B DATASET v1.0 Category: Password Strength Checker ; Style: rigorous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PASSWORD_LENGTH 10
#define MIN_LOWERCASE 2
#define MIN_UPPERCASE 2
#define MIN_DIGITS 2
#define MIN_SPECIAL 2

int check_password_strength(char *password) {
    int score = 0;

    // Check for length
    if (strlen(password) < PASSWORD_LENGTH) {
        printf("Password must be at least %d characters long\n", PASSWORD_LENGTH);
        return 0;
    }

    // Check for lowercase letters
    if (strpbrk(password, "abcdefghijklmnopqrstuvwxyz") == NULL) {
        printf("Password must contain at least %d lowercase letters\n", MIN_LOWERCASE);
        return 0;
    }

    // Check for uppercase letters
    if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == NULL) {
        printf("Password must contain at least %d uppercase letters\n", MIN_UPPERCASE);
        return 0;
    }

    // Check for digits
    if (strpbrk(password, "0123456789") == NULL) {
        printf("Password must contain at least %d digits\n", MIN_DIGITS);
        return 0;
    }

    // Check for special characters
    if (strpbrk(password, "!@#$%^&*()_+-=[]{}|;':\"<>,./?") == NULL) {
        printf("Password must contain at least %d special characters\n", MIN_SPECIAL);
        return 0;
    }

    // Check for duplicate characters
    if (strlen(password) != strspn(password, password)) {
        printf("Password must not contain duplicate characters\n");
        return 0;
    }

    return 1;
}

int main() {
    char password[PASSWORD_LENGTH + 1];

    printf("Enter your password: ");
    scanf("%s", password);

    if (check_password_strength(password)) {
        printf("Your password is strong enough\n");
    } else {
        printf("Your password is not strong enough\n");
    }

    return 0;
}