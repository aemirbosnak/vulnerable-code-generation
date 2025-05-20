//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 32

// Function to check if a character is a letter
int isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a digit
int isDigit(char c) {
    return c >= '0' && c <= '9';
}

// Function to check if a character is a special character
int isSpecial(char c) {
    return strchr("!@#$%^&*()_+-=[]{}\\|;':\",.<>/?", c)!= NULL;
}

// Function to check the strength of a password
int checkPasswordStrength(char *password) {
    int length = strlen(password);
    int hasLetter = 0, hasDigit = 0, hasSpecial = 0;

    // Check for letter
    for (int i = 0; i < length; i++) {
        if (isLetter(password[i])) {
            hasLetter = 1;
            break;
        }
    }

    // Check for digit
    for (int i = 0; i < length; i++) {
        if (isDigit(password[i])) {
            hasDigit = 1;
            break;
        }
    }

    // Check for special character
    for (int i = 0; i < length; i++) {
        if (isSpecial(password[i])) {
            hasSpecial = 1;
            break;
        }
    }

    // Determine password strength
    if (length < 8) {
        return 1; // Weak
    } else if (length >= 8 && length < 12) {
        if (hasLetter && hasDigit) {
            return 2; // Medium
        } else {
            return 1; // Weak
        }
    } else if (length >= 12 && hasLetter && hasDigit && hasSpecial) {
        return 3; // Strong
    } else {
        return 2; // Medium
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);

    int strength = checkPasswordStrength(password);

    switch (strength) {
        case 1:
            printf("Weak\n");
            break;
        case 2:
            printf("Medium\n");
            break;
        case 3:
            printf("Strong\n");
            break;
    }

    return 0;
}