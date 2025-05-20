//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 100

// Function to check password strength
int checkPasswordStrength(char *password) {
    int length = strlen(password);
    int uppercaseCount = 0;
    int lowercaseCount = 0;
    int numberCount = 0;
    int specialCharCount = 0;

    // Check for uppercase letters
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            uppercaseCount++;
        }
    }

    // Check for lowercase letters
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            lowercaseCount++;
        }
    }

    // Check for numbers
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            numberCount++;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            specialCharCount++;
        }
    }

    // Determine password strength based on criteria
    int strength = 0;
    if (length >= 8) {
        strength++;
    }
    if (uppercaseCount > 0) {
        strength++;
    }
    if (lowercaseCount > 0) {
        strength++;
    }
    if (numberCount > 0) {
        strength++;
    }
    if (specialCharCount > 0) {
        strength++;
    }

    return strength;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    // Get password from user
    printf("Enter password: ");
    scanf("%s", password);

    // Check password strength and print result
    int strength = checkPasswordStrength(password);
    if (strength == 0) {
        printf("Weak password\n");
    } else if (strength == 1) {
        printf("Fair password\n");
    } else if (strength == 2) {
        printf("Good password\n");
    } else {
        printf("Strong password\n");
    }

    return 0;
}