//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 100

// Function to check password strength
int checkPasswordStrength(char *password) {
    int length = strlen(password);
    int hasUppercase = 0;
    int hasLowercase = 0;
    int hasNumber = 0;
    int hasSpecialChar = 0;

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            hasUppercase = 1;
            break;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            hasLowercase = 1;
            break;
        }
    }

    // Check for numbers
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            hasNumber = 1;
            break;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            hasSpecialChar = 1;
            break;
        }
    }

    // Calculate password strength
    int strength = 0;
    if (length >= 8) {
        strength++;
    }
    if (hasUppercase) {
        strength++;
    }
    if (hasLowercase) {
        strength++;
    }
    if (hasNumber) {
        strength++;
    }
    if (hasSpecialChar) {
        strength++;
    }

    return strength;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int strength;

    // Get password from user
    printf("Enter your password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    // Remove newline character from password
    int length = strlen(password);
    password[length - 1] = '\0';

    // Check password strength
    strength = checkPasswordStrength(password);

    // Print password strength
    switch (strength) {
        case 0:
            printf("Weak\n");
            break;
        case 1:
            printf("Fair\n");
            break;
        case 2:
            printf("Good\n");
            break;
        case 3:
            printf("Strong\n");
            break;
        case 4:
            printf("Very strong\n");
            break;
        default:
            printf("Invalid strength\n");
            break;
    }

    return 0;
}