//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the password strength levels
enum PasswordStrength {
    WEAK,
    MEDIUM,
    STRONG
};

// Declare the password strength checker function
enum PasswordStrength checkPasswordStrength(char *password);

int main() {
    // Get the password from the user
    char password[101];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the password strength
    enum PasswordStrength strength = checkPasswordStrength(password);

    // Print the password strength
    switch (strength) {
        case WEAK:
            printf("Your password is weak. Please choose a stronger password.\n");
            break;
        case MEDIUM:
            printf("Your password is medium strength. It could be stronger.\n");
            break;
        case STRONG:
            printf("Your password is strong. Good job!\n");
            break;
    }

    return 0;
}

// Define the password strength checker function
enum PasswordStrength checkPasswordStrength(char *password) {
    // Check the password length
    if (strlen(password) < 8) {
        return WEAK;
    }

    // Check the password for uppercase letters
    int hasUppercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUppercase = 1;
            break;
        }
    }

    // Check the password for lowercase letters
    int hasLowercase = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            hasLowercase = 1;
            break;
        }
    }

    // Check the password for digits
    int hasDigit = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
            break;
        }
    }

    // Check the password for special characters
    int hasSpecialCharacter = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
            hasSpecialCharacter = 1;
            break;
        }
    }

    // Check if all the conditions are met
    if (hasUppercase && hasLowercase && hasDigit && hasSpecialCharacter) {
        return STRONG;
    }

    // Check if some of the conditions are met
    else if (hasUppercase && hasLowercase && hasDigit) {
        return MEDIUM;
    }

    // Otherwise, the password is weak
    else {
        return WEAK;
    }
}