//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD_LENGTH 100

// Function to check if the password is strong
int checkPasswordStrength(char* password) {
    int strength = 0;

    // Check the length of the password
    if (strlen(password) >= 8) {
        strength++;
    }

    // Check if the password contains at least one uppercase letter
    if (strpbrk(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ")) {
        strength++;
    }

    // Check if the password contains at least one lowercase letter
    if (strpbrk(password, "abcdefghijklmnopqrstuvwxyz")) {
        strength++;
    }

    // Check if the password contains at least one digit
    if (strpbrk(password, "0123456789")) {
        strength++;
    }

    // Check if the password contains at least one special character
    if (strpbrk(password, "!@#$%^&*()_+")) {
        strength++;
    }

    // Return the strength of the password
    return strength;
}

// Function to generate a random password
char* generateRandomPassword() {
    char* password = malloc(PASSWORD_LENGTH);

    // Generate a random password
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = rand() % 94 + 33;
    }

    // Terminate the password string with a null character
    password[PASSWORD_LENGTH - 1] = '\0';

    // Return the password
    return password;
}

// Function to get a password from the user
char* getPassword() {
    char* password = malloc(PASSWORD_LENGTH);

    // Get the password from the user
    printf("Enter a password: ");
    scanf("%s", password);

    // Return the password
    return password;
}

// Function to print the strength of the password
void printPasswordStrength(int strength) {
    switch (strength) {
        case 0:
            printf("Your password is very weak. Please try again.\n");
            break;
        case 1:
            printf("Your password is weak. Please try again.\n");
            break;
        case 2:
            printf("Your password is moderately strong.\n");
            break;
        case 3:
            printf("Your password is strong.\n");
            break;
        case 4:
            printf("Your password is very strong.\n");
            break;
        case 5:
            printf("Your password is extremely strong.\n");
            break;
    }
}

int main() {
    // Get a password from the user
    char* password = getPassword();

    // Check the strength of the password
    int strength = checkPasswordStrength(password);

    // Print the strength of the password
    printf("Your password strength is ");
    printPasswordStrength(strength);

    return 0;
}