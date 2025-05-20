//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store password strength information
typedef struct {
    int length;              // Length of the password
    int upperCaseCount;     // Number of uppercase characters
    int lowerCaseCount;     // Number of lowercase characters
    int digitCount;          // Number of digits
    int specialCharCount;    // Number of special characters
} PasswordStrength;

// Function to check password strength
PasswordStrength checkPasswordStrength(char *password) {
    PasswordStrength strength;

    // Initialize strength to default values
    strength.length = strlen(password);
    strength.upperCaseCount = 0;
    strength.lowerCaseCount = 0;
    strength.digitCount = 0;
    strength.specialCharCount = 0;

    // Iterate over the password and count the number of each type of character
    for (int i = 0; i < strength.length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            strength.upperCaseCount++;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            strength.lowerCaseCount++;
        } else if (password[i] >= '0' && password[i] <= '9') {
            strength.digitCount++;
        } else {
            strength.specialCharCount++;
        }
    }

    // Return the strength structure
    return strength;
}

// Function to print password strength
void printPasswordStrength(PasswordStrength strength) {
    // Print the length of the password
    printf("Length: %d\n", strength.length);

    // Print the number of uppercase characters
    printf("Uppercase characters: %d\n", strength.upperCaseCount);

    // Print the number of lowercase characters
    printf("Lowercase characters: %d\n", strength.lowerCaseCount);

    // Print the number of digits
    printf("Digits: %d\n", strength.digitCount);

    // Print the number of special characters
    printf("Special characters: %d\n", strength.specialCharCount);

    // Print the strength of the password
    if (strength.length >= 8 && strength.upperCaseCount >= 1 && strength.lowerCaseCount >= 1 && strength.digitCount >= 1 && strength.specialCharCount >= 1) {
        printf("Password strength: Strong\n");
    } else if (strength.length >= 6 && (strength.upperCaseCount >= 1 || strength.lowerCaseCount >= 1) && (strength.digitCount >= 1 || strength.specialCharCount >= 1)) {
        printf("Password strength: Moderate\n");
    } else {
        printf("Password strength: Weak\n");
    }
}

// Main function
int main() {
    // Get the password from the user
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the password strength
    PasswordStrength strength = checkPasswordStrength(password);

    // Print the password strength
    printPasswordStrength(strength);

    return 0;
}