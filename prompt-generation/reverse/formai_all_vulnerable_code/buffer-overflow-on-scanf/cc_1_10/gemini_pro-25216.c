//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: enthusiastic
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

// Declare the password strength levels
enum PasswordStrength {
    VERY_WEAK,
    WEAK,
    MEDIUM,
    STRONG,
    VERY_STRONG
};

// Define the minimum password length
#define MIN_PASSWORD_LENGTH 8

// Define the maximum password length
#define MAX_PASSWORD_LENGTH 32

// Function to check if the password is valid
bool isPasswordValid(char password[]) {
    // Check if the password is empty
    if (strlen(password) == 0) {
        return false;
    }

    // Check if the password is too short
    if (strlen(password) < MIN_PASSWORD_LENGTH) {
        return false;
    }

    // Check if the password is too long
    if (strlen(password) > MAX_PASSWORD_LENGTH) {
        return false;
    }

    // Check if the password contains any spaces
    if (strchr(password, ' ') != NULL) {
        return false;
    }

    return true;
}

// Function to check the strength of the password
enum PasswordStrength checkPasswordStrength(char password[]) {
    // Calculate the number of lowercase letters in the password
    int numLowercase = 0;

    // Calculate the number of uppercase letters in the password
    int numUppercase = 0;

    // Calculate the number of digits in the password
    int numDigits = 0;

    // Calculate the number of special characters in the password
    int numSpecial = 0;

    // Iterate over the password and count the number of each type of character
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            numLowercase++;
        } else if (isupper(password[i])) {
            numUppercase++;
        } else if (isdigit(password[i])) {
            numDigits++;
        } else {
            numSpecial++;
        }
    }

    // Check if the password is very weak
    if (numLowercase == 0 && numUppercase == 0 && numDigits == 0 && numSpecial == 0) {
        return VERY_WEAK;
    }

    // Check if the password is weak
    if (numLowercase == 0 || numUppercase == 0 || numDigits == 0 || numSpecial == 0) {
        return WEAK;
    }

    // Check if the password is medium
    if (numLowercase >= 2 && numUppercase >= 2 && numDigits >= 2 && numSpecial >= 2) {
        return MEDIUM;
    }

    // Check if the password is strong
    if (numLowercase >= 3 && numUppercase >= 3 && numDigits >= 3 && numSpecial >= 3) {
        return STRONG;
    }

    // The password is very strong
    return VERY_STRONG;
}

// Function to get the password from the user
void getPassword(char password[]) {
    // Prompt the user to enter their password
    printf("Enter your password: ");

    // Read the password from the user
    scanf("%s", password);
}

// Function to print the password strength
void printPasswordStrength(enum PasswordStrength strength) {
    // Print the password strength
    switch (strength) {
        case VERY_WEAK:
            printf("Your password is very weak.\n");
            break;
        case WEAK:
            printf("Your password is weak.\n");
            break;
        case MEDIUM:
            printf("Your password is medium.\n");
            break;
        case STRONG:
            printf("Your password is strong.\n");
            break;
        case VERY_STRONG:
            printf("Your password is very strong.\n");
            break;
    }
}

// Main function
int main() {
    // Declare the password variable
    char password[MAX_PASSWORD_LENGTH + 1];

    // Get the password from the user
    getPassword(password);

    // Check if the password is valid
    if (!isPasswordValid(password)) {
        printf("Your password is invalid.\n");
        return 1;
    }

    // Check the strength of the password
    enum PasswordStrength strength = checkPasswordStrength(password);

    // Print the password strength
    printPasswordStrength(strength);

    return 0;
}