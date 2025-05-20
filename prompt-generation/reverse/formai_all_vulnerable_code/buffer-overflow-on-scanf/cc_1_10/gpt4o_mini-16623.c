//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 128

void generatePassword(int length, int useUppercase, int useLowercase, int useDigits, int useSpecialChars, char* password) {
    const char* uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char* lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    const char* digitChars = "0123456789";
    const char* specialChars = "!@#$%^&*()-_=+[]{}|;:,.<>?";
    
    char charPool[MAX_PASSWORD_LENGTH];
    int poolIndex = 0;

    if (useUppercase) {
        strcpy(charPool + poolIndex, uppercaseChars);
        poolIndex += strlen(uppercaseChars);
    }
    if (useLowercase) {
        strcpy(charPool + poolIndex, lowercaseChars);
        poolIndex += strlen(lowercaseChars);
    }
    if (useDigits) {
        strcpy(charPool + poolIndex, digitChars);
        poolIndex += strlen(digitChars);
    }
    if (useSpecialChars) {
        strcpy(charPool + poolIndex, specialChars);
        poolIndex += strlen(specialChars);
    }

    if (poolIndex == 0) {
        fprintf(stderr, "Error: At least one character type must be selected.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length; i++) {
        password[i] = charPool[rand() % poolIndex];
    }
    password[length] = '\0'; // Null terminate the string
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    int length;
    int useUppercase, useLowercase, useDigits, useSpecialChars;
    char password[MAX_PASSWORD_LENGTH + 1];

    printf("Secure Password Generator\n");
    printf("==========================\n");

    // Get password length
    printf("Enter desired password length (1 to %d): ", MAX_PASSWORD_LENGTH);
    scanf("%d", &length);
    if (length < 1 || length > MAX_PASSWORD_LENGTH) {
        fprintf(stderr, "Error: Password length must be between 1 and %d.\n", MAX_PASSWORD_LENGTH);
        return EXIT_FAILURE;
    }

    // Get password composition criteria
    printf("Include uppercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &useUppercase);
    printf("Include lowercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &useLowercase);
    printf("Include digits? (1 for yes, 0 for no): ");
    scanf("%d", &useDigits);
    printf("Include special characters? (1 for yes, 0 for no): ");
    scanf("%d", &useSpecialChars);

    // Generate password
    generatePassword(length, useUppercase, useLowercase, useDigits, useSpecialChars, password);

    printf("Generated Password: %s\n", password);

    return EXIT_SUCCESS;
}