//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: innovative
#include <stdio.h>
#include <string.h>

// Define the minimum password length
#define MIN_PASS_LEN 8

// Declare the password strength levels
enum password_strength {
    WEAK,
    MEDIUM,
    STRONG
};

// Function to check the password strength
enum password_strength check_password_strength(char *password) {
    int len = strlen(password);

    // Check if the password is too short
    if (len < MIN_PASS_LEN) {
        return WEAK;
    }

    // Check if the password contains only lowercase letters
    int has_lowercase = 0;
    for (int i = 0; i < len; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
            break;
        }
    }
    if (!has_lowercase) {
        return WEAK;
    }

    // Check if the password contains only uppercase letters
    int has_uppercase = 0;
    for (int i = 0; i < len; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
            break;
        }
    }
    if (!has_uppercase) {
        return WEAK;
    }

    // Check if the password contains only digits
    int has_digit = 0;
    for (int i = 0; i < len; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
            break;
        }
    }
    if (!has_digit) {
        return WEAK;
    }

    // Check if the password contains any special characters
    int has_special = 0;
    for (int i = 0; i < len; i++) {
        if (!(password[i] >= 'a' && password[i] <= 'z') &&
            !(password[i] >= 'A' && password[i] <= 'Z') &&
            !(password[i] >= '0' && password[i] <= '9')) {
            has_special = 1;
            break;
        }
    }
    if (!has_special) {
        return WEAK;
    }

    // If all the checks pass, the password is strong
    return STRONG;
}

// Main function
int main() {
    // Get the password from the user
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the password strength
    enum password_strength strength = check_password_strength(password);

    // Print the password strength
    switch (strength) {
        case WEAK:
            printf("Your password is weak.\n");
            break;
        case MEDIUM:
            printf("Your password is medium.\n");
            break;
        case STRONG:
            printf("Your password is strong.\n");
            break;
    }

    return 0;
}