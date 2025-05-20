//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Function to check password strength */
int checkPasswordStrength(char password[])
{
    int len = strlen(password);

    // Initializing variables to check different criteria
    int hasLowercase = 0, hasUppercase = 0, hasDigit = 0, hasSpecialChar = 0;

    // Checking for lowercase letter
    for (int i = 0; i < len; i++) {
        if (islower(password[i])) {
            hasLowercase = 1;
            break;
        }
    }

    // Checking for uppercase letter
    for (int i = 0; i < len; i++) {
        if (isupper(password[i])) {
            hasUppercase = 1;
            break;
        }
    }

    // Checking for digit
    for (int i = 0; i < len; i++) {
        if (isdigit(password[i])) {
            hasDigit = 1;
            break;
        }
    }

    // Checking for special character
    for (int i = 0; i < len; i++) {
        if (!isalnum(password[i])) {
            hasSpecialChar = 1;
            break;
        }
    }

    // Checking password strength based on different criteria
    if (len < 8 || len > 20) {
        return 0; // weak password
    }

    if (!hasLowercase || !hasUppercase || !hasDigit || !hasSpecialChar) {
        return 0; // weak password
    }

    return 1; // strong password
}

int main() {
    char password[50];
    printf("Enter password to check its strength (password length should be between 8 and 20 characters):\n");
    scanf("%s", password);
    if (checkPasswordStrength(password)) {
        printf("Strong password\n");
    } else {
        printf("Weak password\n");
    }
    return 0;
}