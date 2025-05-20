//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a secure password
void generateSecurePassword(int length, char *password) {
    const char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Uppercase letters
    const char *lower = "abcdefghijklmnopqrstuvwxyz"; // Lowercase letters
    const char *digits = "0123456789";                 // Digits
    const char *special = "!@#$%^&*()-_=+[]{}|;:,.<>?/"; // Special characters
    const char *allCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[]{}|;:,.<>?/"; // All characters

    // Seed random number generator
    srand((unsigned int)time(NULL));

    // Ensure the password contains at least one character of each type
    password[0] = upper[rand() % strlen(upper)];
    password[1] = lower[rand() % strlen(lower)];
    password[2] = digits[rand() % strlen(digits)];
    password[3] = special[rand() % strlen(special)];

    // Fill in the remaining length of the password with random characters
    for (int i = 4; i < length; i++) {
        password[i] = allCharacters[rand() % strlen(allCharacters)];
    }

    // Shuffle the password to randomize the order
    for (int i = 0; i < length; i++) {
        int j = rand() % length; // swap characters
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    password[length] = '\0'; // Null-terminate the string
}

int main() {
    int passwordLength;

    // Prompt user for the length of the password
    printf("Enter the desired length of the secure password (minimum 8 characters): ");
    scanf("%d", &passwordLength);

    // Validate the password length
    if (passwordLength < 8) {
        printf("Password length should be at least 8 characters. Exiting...\n");
        return 1;
    }

    char *password = malloc((passwordLength + 1) * sizeof(char)); // Allocate memory for password
    if (password == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Generate the secure password
    generateSecurePassword(passwordLength, password);
    
    // Output the generated password
    printf("Generated secure password: %s\n", password);

    // Free allocated memory
    free(password);

    return 0;
}