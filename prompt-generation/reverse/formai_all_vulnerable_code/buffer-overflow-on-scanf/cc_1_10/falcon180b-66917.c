//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if the password is strong enough
int isPasswordStrong(char *password) {
    // Check if the password is long enough
    if (strlen(password) < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    // Check if the password contains at least one uppercase letter
    if (!isupper(password[0])) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }

    // Check if the password contains at least one lowercase letter
    if (!islower(password[0])) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }

    // Check if the password contains at least one digit
    if (!isdigit(password[0])) {
        printf("Password must contain at least one digit.\n");
        return 0;
    }

    // Check if the password contains at least one special character
    if (!strchr(password, '!') &&!strchr(password, '@') &&!strchr(password, '#') &&!strchr(password, '$') &&!strchr(password, '%') &&!strchr(password, '^') &&!strchr(password, '&') &&!strchr(password, '*') &&!strchr(password, '(') &&!strchr(password, ')')) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }

    // All checks passed, the password is strong enough
    return 1;
}

int main() {
    char password[100];

    // Prompt the user to enter a password
    printf("Enter a password: ");
    scanf("%s", password);

    // Check if the password is strong enough
    if (isPasswordStrong(password)) {
        printf("Password is strong enough.\n");
    }

    return 0;
}