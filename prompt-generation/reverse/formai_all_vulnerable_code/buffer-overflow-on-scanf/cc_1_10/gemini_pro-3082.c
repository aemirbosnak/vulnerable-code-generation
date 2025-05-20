//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: enthusiastic
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
int checkPasswordStrength(const char* password);
bool checkLength(const char* password);
bool checkUpperCase(const char* password);
bool checkLowerCase(const char* password);
bool checkDigit(const char* password);
bool checkSymbol(const char* password);
void printStrength(int strength);

// Main function
int main() {
    // Get the password from the user
    char password[101];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the strength of the password
    int strength = checkPasswordStrength(password);

    // Print the strength of the password
    printStrength(strength);

    return 0;
}

// Function to check the strength of a password
int checkPasswordStrength(const char* password) {
    // Check the length of the password
    bool hasLength = checkLength(password);

    // Check if the password contains an uppercase character
    bool hasUpperCase = checkUpperCase(password);

    // Check if the password contains a lowercase character
    bool hasLowerCase = checkLowerCase(password);
    
    // Check if the password contains a digit
    bool hasDigit = checkDigit(password);

    // Check if the password contains a symbol
    bool hasSymbol = checkSymbol(password);

    // Calculate the strength of the password
    int strength = 0;
    if (hasLength) strength += 2;
    if (hasUpperCase) strength += 2;
    if (hasLowerCase) strength += 2;
    if (hasDigit) strength += 2;
    if (hasSymbol) strength += 2;

    return strength;
}

// Function to check the length of a password
bool checkLength(const char* password) {
    return strlen(password) >= 8;
}

// Function to check if a password contains an uppercase character
bool checkUpperCase(const char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            return true;
        }
    }
    return false;
}

// Function to check if a password contains a lowercase character
bool checkLowerCase(const char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            return true;
        }
    }
    return false;
}

// Function to check if a password contains a digit
bool checkDigit(const char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            return true;
        }
    }
    return false;
}

// Function to check if a password contains a symbol
bool checkSymbol(const char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (!((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= '0' && password[i] <= '9'))) {
            return true;
        }
    }
    return false;
}

// Function to print the strength of a password
void printStrength(int strength) {
    switch (strength) {
        case 0:
            printf("Your password is very weak. Please try again.\n");
            break;
        case 2:
            printf("Your password is weak. Please try again.\n");
            break;
        case 4:
            printf("Your password is moderate. Please try again.\n");
            break;
        case 6:
            printf("Your password is strong. Good job!\n");
            break;
        case 8:
            printf("Your password is very strong. Congratulations!\n");
            break;
        default:
            printf("Invalid password strength.\n");
    }
}