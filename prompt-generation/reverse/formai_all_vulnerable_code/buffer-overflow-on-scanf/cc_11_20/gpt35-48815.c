//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check password
void checkPasswordStrength(char* password) {
    int len = strlen(password);
    int hasDigit = 0, hasUpper = 0, hasLower = 0, hasSpecial = 0;
    // Check if password has minimum length of 8 characters
    if (len >= 8) {
        for (int i = 0; i < len; i++) {
            // Check if password has at least one digit
            if (isdigit(password[i])) {
                hasDigit = 1;
            }
            // Check if password has at least one uppercase letter
            if (isupper(password[i])) {
                hasUpper = 1;
            }
            // Check if password has at least one lowercase letter
            if (islower(password[i])) {
                hasLower = 1;
            }
            // Check if password has at least one special character
            if (!(isalnum(password[i]))) {
                hasSpecial = 1;
            }
        }
        // Display the password strength based on criteria
        if (hasDigit && hasUpper && hasLower && hasSpecial) {
            printf("Password is very strong.\n");
        }
        else if ((hasDigit && hasUpper && hasLower) || (hasDigit && hasLower && hasSpecial) || (hasLower && hasUpper && hasSpecial)) {
            printf("Password is strong enough.\n");
        }
        else if ((hasDigit && (hasLower || hasUpper)) || (hasSpecial && (hasLower || hasUpper))) {
            printf("Password is acceptable.\n");
        }
        else {
            printf("Password is weak.\n");
        }
    }
    else {
        printf("Password must have at least 8 characters.\n");
    }
}

int main() {
    char password[256];
    // Get the password from user
    printf("Enter password: ");
    scanf("%s", password);
    checkPasswordStrength(password);
    return 0;
}