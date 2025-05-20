//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: romantic
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Function to check if the given password is strong enough
int isStrongPassword(char *password) {
    int length = strlen(password);
    int hasDigit = 0, hasUpperCase = 0, hasLowerCase = 0, hasSpecialChar = 0;

    // Check for digit
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            hasDigit = 1;
            break;
        }
    }

    // Check for uppercase letter
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUpperCase = 1;
            break;
        }
    }

    // Check for lowercase letter
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            hasLowerCase = 1;
            break;
        }
    }

    // Check for special character
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            hasSpecialChar = 1;
            break;
        }
    }

    // Check if password meets all criteria
    if (length >= 8 && hasDigit && hasUpperCase && hasLowerCase && hasSpecialChar) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[100];

    // Get password from user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check if password is strong enough
    if (isStrongPassword(password)) {
        printf("Your password is strong enough.\n");
    } else {
        printf("Your password is not strong enough.\n");
    }

    return 0;
}