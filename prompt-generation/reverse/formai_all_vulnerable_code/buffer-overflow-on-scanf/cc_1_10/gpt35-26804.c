//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: brave
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * This program checks the strength of a C password based on the following criteria:
 * - At least one uppercase letter
 * - At least one lowercase letter
 * - At least one digit
 * - At least one special character
 * - Minimum length of 8 characters
 */

// Function declaration
int countUpperCase(char *password);
int countLowerCase(char *password);
int countDigits(char *password);
int countSpecialCharacters(char *password);

int main() {
    char password[100];

    printf("Enter your C password: \n");
    scanf("%s", password);

    // Password length check
    if (strlen(password) < 8) {
        printf("Weak password! Password length should be at least 8 characters.\n");
        return 0;
    }

    // Count uppercase letters
    int numUpper = countUpperCase(password);
    if (numUpper == 0) {
        printf("Weak password! Password must contain at least one uppercase letter.\n");
        return 0;
    }

    // Count lowercase letters
    int numLower = countLowerCase(password);
    if (numLower == 0) {
        printf("Weak password! Password must contain at least one lowercase letter.\n");
        return 0;
    }

    // Count digits
    int numDigits = countDigits(password);
    if (numDigits == 0) {
        printf("Weak password! Password must contain at least one digit.\n");
        return 0;
    }

    // Count special characters
    int numSpecial = countSpecialCharacters(password);
    if (numSpecial == 0) {
        printf("Weak password! Password must contain at least one special character.\n");
        return 0;
    }

    // Password is strong if it passes all checks
    printf("Strong password! Your C password is secure.\n");

    return 0;
}

// Function definition to count the number of uppercase letters in password
int countUpperCase(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            count++;
        }
    }
    return count;
}

// Function definition to count the number of lowercase letters in password
int countLowerCase(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            count++;
        }
    }
    return count;
}

// Function definition to count the number of digits in password
int countDigits(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            count++;
        }
    }
    return count;
}

// Function definition to count the number of special characters in password
int countSpecialCharacters(char *password) {
    int count = 0;
    for (int i = 0; i < strlen(password); i++) {
        if (!isalnum(password[i]) && !isspace(password[i])) {
            count++;
        }
    }
    return count;
}