//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD_MIN_LENGTH 8
#define PASSWORD_MAX_LENGTH 32

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
    return!isLetter(c) &&!isNumber(c);
}

// Function to check password strength
int checkPasswordStrength(char* password) {
    int length = strlen(password);

    // Check if password length is within bounds
    if (length < PASSWORD_MIN_LENGTH || length > PASSWORD_MAX_LENGTH) {
        return 0;
    }

    int hasLetter = 0;
    int hasNumber = 0;
    int hasSpecialChar = 0;

    // Check for required characters
    for (int i = 0; i < length; i++) {
        if (isLetter(password[i])) {
            hasLetter = 1;
        } else if (isNumber(password[i])) {
            hasNumber = 1;
        } else if (isSpecialChar(password[i])) {
            hasSpecialChar = 1;
        }
    }

    // Check for additional characters
    if (hasLetter && hasNumber && hasSpecialChar) {
        return 3;
    } else if (hasLetter && hasNumber) {
        return 2;
    } else if (hasLetter || hasNumber) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[PASSWORD_MAX_LENGTH];

    // Get password from user
    printf("Enter password: ");
    scanf("%s", password);

    // Check password strength
    int strength = checkPasswordStrength(password);

    switch (strength) {
        case 0:
            printf("Password is too short or too long.\n");
            break;
        case 1:
            printf("Password is weak.\n");
            break;
        case 2:
            printf("Password is moderate.\n");
            break;
        case 3:
            printf("Password is strong.\n");
            break;
    }

    return 0;
}