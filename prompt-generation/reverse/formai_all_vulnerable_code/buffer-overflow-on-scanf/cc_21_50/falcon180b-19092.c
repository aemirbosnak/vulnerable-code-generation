//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: modular
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, i;
    int hasUppercase = 0, hasLowercase = 0, hasDigit = 0, hasSpecialChar = 0;

    // Get password from user
    printf("Enter password: ");
    scanf("%s", password);

    // Check for minimum length
    length = strlen(password);
    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    // Check for uppercase letter
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUppercase = 1;
        }
    }

    // Check for lowercase letter
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            hasLowercase = 1;
        }
    }

    // Check for digit
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            hasDigit = 1;
        }
    }

    // Check for special characters
    for (i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            hasSpecialChar = 1;
        }
    }

    // Determine password strength
    if (hasUppercase && hasLowercase && hasDigit && hasSpecialChar) {
        printf("Password is strong.\n");
    } else if ((hasUppercase || hasLowercase) && hasDigit && hasSpecialChar) {
        printf("Password is medium.\n");
    } else if ((hasUppercase || hasLowercase) && hasDigit) {
        printf("Password is weak.\n");
    } else if (hasUppercase && hasLowercase) {
        printf("Password is very weak.\n");
    } else {
        printf("Password is extremely weak.\n");
    }

    return 0;
}