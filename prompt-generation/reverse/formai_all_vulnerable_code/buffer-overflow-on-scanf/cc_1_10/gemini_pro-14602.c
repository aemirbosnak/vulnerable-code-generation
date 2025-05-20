//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the password is strong
int checkPasswordStrength(char *password) {
    int strength = 0;

    // Check if the password is at least 8 characters long
    if (strlen(password) >= 8) {
        strength++;
    }

    // Check if the password contains at least one uppercase character
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            strength++;
            break;
        }
    }

    // Check if the password contains at least one lowercase character
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            strength++;
            break;
        }
    }

    // Check if the password contains at least one digit
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            strength++;
            break;
        }
    }

    // Check if the password contains at least one special character
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] == '!' || password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
            strength++;
            break;
        }
    }

    // Return the strength of the password
    return strength;
}

// Function to generate a random password
char *generatePassword() {
    // Array of possible characters for the password
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%";

    // Allocate memory for the password
    char *password = malloc(9);

    // Generate a random password
    for (int i = 0; i < 8; i++) {
        password[i] = characters[rand() % (sizeof(characters) - 1)];
    }

    // Add a null terminator to the end of the password
    password[8] = '\0';

    // Return the password
    return password;
}

// Main function
int main() {
    // Get the password from the user
    char password[100];
    printf("Enter a password: ");
    scanf("%s", password);

    // Check the strength of the password
    int strength = checkPasswordStrength(password);

    // Print the strength of the password
    printf("The strength of the password is %d\n", strength);

    // If the password is not strong, generate a new password
    if (strength < 4) {
        printf("The password is not strong enough. Generating a new password...\n");
        char *newPassword = generatePassword();
        printf("New password: %s\n", newPassword);
    }

    return 0;
}