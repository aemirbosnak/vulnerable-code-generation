//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function to check if the password is strong enough
bool isStrongPassword(char* password) {
    // Check the length of the password
    if (strlen(password) < 8) {
        printf("Password should be at least 8 characters long.\n");
        return false;
    }

    // Check if the password contains at least one uppercase letter
    bool hasUppercase = false;
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            hasUppercase = true;
            break;
        }
    }
    if (!hasUppercase) {
        printf("Password should contain at least one uppercase letter.\n");
        return false;
    }

    // Check if the password contains at least one lowercase letter
    bool hasLowercase = false;
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            hasLowercase = true;
            break;
        }
    }
    if (!hasLowercase) {
        printf("Password should contain at least one lowercase letter.\n");
        return false;
    }

    // Check if the password contains at least one digit
    bool hasDigit = false;
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            hasDigit = true;
            break;
        }
    }
    if (!hasDigit) {
        printf("Password should contain at least one digit.\n");
        return false;
    }

    // Check if the password contains any special characters
    bool hasSpecialChar = false;
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i])) {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) {
        printf("Password should contain at least one special character.\n");
        return false;
    }

    return true;
}

int main() {
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    if (isStrongPassword(password)) {
        printf("Your password is strong!\n");
    } else {
        printf("Your password is weak.\n");
    }

    return 0;
}