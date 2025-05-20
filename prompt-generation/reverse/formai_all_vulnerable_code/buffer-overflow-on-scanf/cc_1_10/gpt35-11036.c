//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: retro
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if the password contains uppercase letters.
int containsUpperCase(char* password) {
    int len = strlen(password);
    for (int i = 0; i < len; i++) {
        if (isupper(*(password+i))) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains lowercase letters.
int containsLowerCase(char* password) {
    int len = strlen(password);
    for (int i = 0; i < len; i++) {
        if (islower(*(password+i))) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains digits.
int containsDigits(char* password) {
    int len = strlen(password);
    for (int i = 0; i < len; i++) {
        if (isdigit(*(password+i))) {
            return 1;
        }
    }
    return 0;
}

// Function to check if the password contains special characters.
int containsSpecialChar(char* password) {
    int len = strlen(password);
    for (int i = 0; i < len; i++) {
        if (!isalnum(*(password+i))) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // Get the password from the user.
    char password[50];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check for password strength.
    int upper = containsUpperCase(password);
    int lower = containsLowerCase(password);
    int digits = containsDigits(password);
    int specialChar = containsSpecialChar(password);
    int strength = 0;

    if (upper == 1) {
        strength++;
    }

    if (lower == 1) {
        strength++;
    }

    if (digits == 1) {
        strength++;
    }

    if (specialChar == 1) {
        strength++;
    }

    // Determine the strength of the password and display the result.
    switch (strength) {
        case 0:
        case 1:
            printf("Your password is weak.\n");
            break;
        case 2:
            printf("Your password is moderate.\n");
            break;
        case 3:
            printf("Your password is strong.\n");
            break;
        case 4:
            printf("Your password is very strong.\n");
            break;
    }

    return 0;
}