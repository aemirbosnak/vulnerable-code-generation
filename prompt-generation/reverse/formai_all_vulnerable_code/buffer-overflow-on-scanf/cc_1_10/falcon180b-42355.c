//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a letter
int isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a number
int isNumber(char c) {
    return c >= '0' && c <= '9';
}

// Function to check if a character is a special character
int isSpecialChar(char c) {
    return c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '&' || c == '*';
}

// Function to check password strength
int checkPasswordStrength(char* password) {
    int length = strlen(password);
    int hasLetters = 0;
    int hasNumbers = 0;
    int hasSpecialChars = 0;

    // Check if password contains at least one letter, one number, and one special character
    for (int i = 0; i < length; i++) {
        if (isLetter(password[i])) {
            hasLetters = 1;
        }
        if (isNumber(password[i])) {
            hasNumbers = 1;
        }
        if (isSpecialChar(password[i])) {
            hasSpecialChars = 1;
        }
    }

    // If password does not contain at least one letter, one number, and one special character, return 0
    if (!hasLetters ||!hasNumbers ||!hasSpecialChars) {
        return 0;
    }

    // Check password length
    if (length < 8) {
        return 1; // Weak password
    } else if (length < 12) {
        return 2; // Moderate password
    } else {
        return 3; // Strong password
    }
}

int main() {
    char password[100];

    // Get password from user
    printf("Enter your password: ");
    scanf("%s", password);

    // Check password strength
    int strength = checkPasswordStrength(password);

    // Print password strength
    if (strength == 0) {
        printf("Password is not strong enough.\n");
    } else if (strength == 1) {
        printf("Password is weak.\n");
    } else if (strength == 2) {
        printf("Password is moderate.\n");
    } else {
        printf("Password is strong.\n");
    }

    return 0;
}