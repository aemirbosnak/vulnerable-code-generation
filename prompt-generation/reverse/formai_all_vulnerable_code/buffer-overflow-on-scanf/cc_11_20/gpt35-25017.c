//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: artistic
#include <stdio.h>
#include <string.h>

// function to check if password is strong
int isStrongPassword(char* password) {
    int length = strlen(password);
    int hasUppercase = 0, hasLowercase = 0, hasDigit = 0, hasSpecialChar = 0;

    // check for password length
    if (length < 8) {
        return 0;
    }

    // check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUppercase = 1;
        }
    }

    // check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            hasLowercase = 1;
        }
    }

    // check for digits
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
        }
    }

    // check for special characters
    for (int i = 0; i < length; i++) {
        if ((password[i] >= '!' && password[i] <= '/') ||
            (password[i] >= ':' && password[i] <= '@') ||
            (password[i] >= '[' && password[i] <= '`') ||
            (password[i] >= '{' && password[i] <= '~')) {
            hasSpecialChar = 1;
        }
    }

    // check if all conditions are satisfied
    if (hasUppercase && hasLowercase && hasDigit && hasSpecialChar) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[20];

    printf("Enter your password: ");
    scanf("%s", password);

    if (isStrongPassword(password)) {
        printf("Your password is strong!");
    } else {
        printf("Your password is weak! Please make sure it meets the following conditions:\n");
        printf(" - At least 8 characters long\n");
        printf(" - Contains at least one uppercase letter\n");
        printf(" - Contains at least one lowercase letter\n");
        printf(" - Contains at least one digit\n");
        printf(" - Contains at least one special character\n");
    }

    return 0;
}