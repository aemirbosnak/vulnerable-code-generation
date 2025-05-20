//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: scientific
#include <stdio.h>
#include <string.h>

// Function to check if the character is a digit
int isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Function to check if the character is a lowercase letter
int isLowerCase(char c) {
    return c >= 'a' && c <= 'z';
}

// Function to check if the character is an uppercase letter
int isUpperCase(char c) {
    return c >= 'A' && c <= 'Z';
}

// Function to check if the character is a special character
int isSpecialChar(char c) {
    return (c >= '!' && c <= '/') || (c >= ':' && c <= '@')
        || (c >= '[' && c <= '`') || (c >= '{' && c <= '~');
}

// Function to check if the password is strong or not
int isPasswordStrong(char *password) {
    int length = strlen(password);
    int i, hasDigit = 0, hasLowerCase = 0, hasUpperCase = 0, hasSpecialChar = 0;
    
    // Check the password length
    if (length < 8) {
        return 0;
    }
    
    // Check if the password has at least one digit, lowercase letter,
    // uppercase letter, and special character
    for (i = 0; i < length; i++) {
        if (isDigit(password[i])) {
            hasDigit = 1;
        } else if (isLowerCase(password[i])) {
            hasLowerCase = 1;
        } else if (isUpperCase(password[i])) {
            hasUpperCase = 1;
        } else if (isSpecialChar(password[i])) {
            hasSpecialChar = 1;
        }
    }
    
    // Check if the password meets the strength requirements
    if (hasDigit && hasLowerCase && hasUpperCase && hasSpecialChar) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[100];
    int strength;
    
    printf("Enter the password to check its strength: ");
    scanf("%s", password);
    
    strength = isPasswordStrong(password);
    
    if (strength) {
        printf("The password is strong.\n");
    } else {
        printf("The password is weak.\n");
    }
    
    return 0;
}