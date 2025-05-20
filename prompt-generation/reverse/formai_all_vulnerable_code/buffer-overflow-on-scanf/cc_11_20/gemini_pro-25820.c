//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: systematic
#include <stdio.h>
#include <string.h>

// Function to check if the password is strong
int isStrongPassword(char *password) {
    int hasUpper = 0;
    int hasLower = 0;
    int hasNumber = 0;
    int hasSpecial = 0;
    int length = strlen(password);

    // Check if the password is at least 8 characters long
    if (length < 8) {
        return 0;
    }

    // Check if the password contains at least one uppercase letter
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUpper = 1;
            break;
        }
    }

    // Check if the password contains at least one lowercase letter
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            hasLower = 1;
            break;
        }
    }

    // Check if the password contains at least one number
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            hasNumber = 1;
            break;
        }
    }

    // Check if the password contains at least one special character
    for (int i = 0; i < length; i++) {
        if (!((password[i] >= 'A' && password[i] <= 'Z') ||
              (password[i] >= 'a' && password[i] <= 'z') ||
              (password[i] >= '0' && password[i] <= '9'))) {
            hasSpecial = 1;
            break;
        }
    }

    // Return 1 if the password is strong, otherwise return 0
    return hasUpper && hasLower && hasNumber && hasSpecial;
}

int main() {
    char password[100];

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check if the password is strong
    if (isStrongPassword(password)) {
        printf("Your password is strong.\n");
    } else {
        printf("Your password is not strong. Please try again.\n");
    }

    return 0;
}