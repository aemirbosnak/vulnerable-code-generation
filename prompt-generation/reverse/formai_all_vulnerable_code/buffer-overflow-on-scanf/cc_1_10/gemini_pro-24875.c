//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the password strength levels
typedef enum {
    WEAK,
    MEDIUM,
    STRONG,
    VERY_STRONG
} PasswordStrength;

// Define the password requirements
typedef struct {
    int minLength;
    int minUpperCase;
    int minLowerCase;
    int minDigits;
    int minSpecialChars;
} PasswordRequirements;

// Function to check if a character is a digit
int isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Function to check if a character is a lower case letter
int isLowerCase(char c) {
    return c >= 'a' && c <= 'z';
}

// Function to check if a character is an upper case letter
int isUpperCase(char c) {
    return c >= 'A' && c <= 'Z';
}

// Function to check if a character is a special character
int isSpecialChar(char c) {
    return !isDigit(c) && !isLowerCase(c) && !isUpperCase(c);
}

// Function to check the strength of a password
PasswordStrength checkPasswordStrength(char *password, PasswordRequirements requirements) {
    int length = strlen(password);
    int upperCase = 0;
    int lowerCase = 0;
    int digits = 0;
    int specialChars = 0;

    // Check if the password meets the minimum length requirement
    if (length < requirements.minLength) {
        return WEAK;
    }

    // Count the number of upper case, lower case, digits, and special characters in the password
    for (int i = 0; i < length; i++) {
        if (isUpperCase(password[i])) {
            upperCase++;
        } else if (isLowerCase(password[i])) {
            lowerCase++;
        } else if (isDigit(password[i])) {
            digits++;
        } else if (isSpecialChar(password[i])) {
            specialChars++;
        }
    }

    // Check if the password meets the minimum requirements for upper case letters, lower case letters, digits, and special characters
    if (upperCase < requirements.minUpperCase || lowerCase < requirements.minLowerCase || digits < requirements.minDigits || specialChars < requirements.minSpecialChars) {
        return WEAK;
    }

    // If the password meets all of the requirements, return the appropriate strength level
    if (upperCase >= 2 * requirements.minUpperCase && lowerCase >= 2 * requirements.minLowerCase && digits >= 2 * requirements.minDigits && specialChars >= 2 * requirements.minSpecialChars) {
        return VERY_STRONG;
    } else if (upperCase >= requirements.minUpperCase && lowerCase >= requirements.minLowerCase && digits >= requirements.minDigits && specialChars >= requirements.minSpecialChars) {
        return STRONG;
    } else {
        return MEDIUM;
    }
}

// Main function
int main() {
    // Define the password requirements
    PasswordRequirements requirements = {
        .minLength = 8,
        .minUpperCase = 1,
        .minLowerCase = 1,
        .minDigits = 1,
        .minSpecialChars = 1
    };

    // Get the password from the user
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the strength of the password
    PasswordStrength strength = checkPasswordStrength(password, requirements);

    // Print the password strength
    switch (strength) {
        case WEAK:
            printf("Your password is weak.\n");
            break;
        case MEDIUM:
            printf("Your password is medium strength.\n");
            break;
        case STRONG:
            printf("Your password is strong.\n");
            break;
        case VERY_STRONG:
            printf("Your password is very strong.\n");
            break;
    }

    return 0;
}