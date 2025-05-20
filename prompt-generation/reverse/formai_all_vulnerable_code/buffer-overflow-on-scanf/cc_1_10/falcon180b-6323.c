//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: shocked
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100

void checkPasswordStrength(char *password) {
    int length = strlen(password);
    int uppercaseCount = 0;
    int lowercaseCount = 0;
    int digitCount = 0;
    int specialCharCount = 0;
    int totalStrength = 0;

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

    // Check for digits
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digitCount++;
        }
    }

    // Check for special characters
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            specialCharCount++;
        }
    }

    // Calculate total strength
    totalStrength = (uppercaseCount * 4) + (lowercaseCount * 3) + (digitCount * 2) + specialCharCount;

    // Print password strength
    if (totalStrength <= 6) {
        printf("Password is very weak.\n");
    } else if (totalStrength <= 12) {
        printf("Password is weak.\n");
    } else if (totalStrength <= 18) {
        printf("Password is moderate.\n");
    } else if (totalStrength <= 24) {
        printf("Password is strong.\n");
    } else {
        printf("Password is very strong.\n");
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter password: ");
    scanf("%s", password);

    checkPasswordStrength(password);

    return 0;
}