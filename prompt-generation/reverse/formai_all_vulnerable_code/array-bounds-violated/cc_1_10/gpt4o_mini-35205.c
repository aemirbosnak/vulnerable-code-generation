//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 12  // Define the length of the password
#define NUM_PASSWORDS 5     // Number of passwords to generate

// Function to generate a random character
char generateRandomCharacter() {
    int characterType = rand() % 4;
    switch (characterType) {
        case 0: return '0' + (rand() % 10); // Digits (0-9)
        case 1: return 'a' + (rand() % 26); // Lowercase letters (a-z)
        case 2: return 'A' + (rand() % 26); // Uppercase letters (A-Z)
        case 3: return "!@#$%^&*()_+-=[]{}|;:,.<>?/~"[(rand() % 30)]; // Special characters
    }
    return 0; // Should never reach here
}

// Function to check if the password contains at least one character from each category
int isValidPassword(char* password) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') hasUpper = 1;
        else if (password[i] >= 'a' && password[i] <= 'z') hasLower = 1;
        else if (password[i] >= '0' && password[i] <= '9') hasDigit = 1;
        else hasSpecial = 1; // assuming special character is used
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

// Function to generate a secure password
void generateSecurePassword(char* password) {
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = generateRandomCharacter();
    }
    password[PASSWORD_LENGTH] = '\0'; // Null-terminate the string
}

// Function to generate multiple secure passwords
void generateMultiplePasswords() {
    char password[PASSWORD_LENGTH + 1];
    int validPasswordCount = 0;

    printf("Generated secure passwords:\n");
    
    while(validPasswordCount < NUM_PASSWORDS) {
        generateSecurePassword(password);
        
        if (isValidPassword(password)) {
            printf("%s\n", password);
            validPasswordCount++;
        }
    }
}

int main() {
    srand((unsigned int)time(NULL)); // Seed the random number generator

    generateMultiplePasswords(); // Call the function to generate passwords

    return 0;
}