//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is an uppercase letter
int isUpper(char c) {
    return (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a lowercase letter
int isLower(char c) {
    return (c >= 'a' && c <= 'z');
}

// Function to check if a character is a digit
int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

// Function to check if a character is a special character
int isSpecial(char c) {
    return (!isUpper(c) && !isLower(c) && !isDigit(c));
}

// Function to check the strength of a password
int checkPasswordStrength(char* password) {
    int strength = 0;

    // Check the length of the password
    if (strlen(password) < 8) {
        strength += 1;
    } else if (strlen(password) >= 8 && strlen(password) < 12) {
        strength += 2;
    } else if (strlen(password) >= 12) {
        strength += 3;
    }

    // Check the variety of characters in the password
    int upperCount = 0;
    int lowerCount = 0;
    int digitCount = 0;
    int specialCount = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isUpper(password[i])) {
            upperCount++;
        } else if (isLower(password[i])) {
            lowerCount++;
        } else if (isDigit(password[i])) {
            digitCount++;
        } else if (isSpecial(password[i])) {
            specialCount++;
        }
    }
    if (upperCount > 0) {
        strength += 1;
    }
    if (lowerCount > 0) {
        strength += 1;
    }
    if (digitCount > 0) {
        strength += 1;
    }
    if (specialCount > 0) {
        strength += 1;
    }

    // Check the complexity of the password
    int complexity = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] == password[i + 1]) {
            complexity--;
        }
    }
    if (complexity < 0) {
        complexity = 0;
    }
    strength += complexity;

    return strength;
}

// Main function
int main() {
    char password[100];

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check the strength of the password
    int strength = checkPasswordStrength(password);

    // Print the strength of the password
    if (strength < 4) {
        printf("Your password is weak.\n");
    } else if (strength >= 4 && strength < 7) {
        printf("Your password is moderate.\n");
    } else if (strength >= 7) {
        printf("Your password is strong.\n");
    }

    return 0;
}