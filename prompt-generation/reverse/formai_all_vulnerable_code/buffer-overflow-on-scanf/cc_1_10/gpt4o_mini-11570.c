//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 128

void generatePassword(char *password, int length, int useUpper, int useLower, int useDigits, int useSpecial) {
    const char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *lower = "abcdefghijklmnopqrstuvwxyz";
    const char *digits = "0123456789";
    const char *special = "!@#$%^&*()-_=+[]{}|;:,.<>?";

    char characterPool[MAX_LENGTH];
    int poolSize = 0;

    if (useUpper) {
        strcpy(characterPool + poolSize, upper);
        poolSize += strlen(upper);
    }
    if (useLower) {
        strcpy(characterPool + poolSize, lower);
        poolSize += strlen(lower);
    }
    if (useDigits) {
        strcpy(characterPool + poolSize, digits);
        poolSize += strlen(digits);
    }
    if (useSpecial) {
        strcpy(characterPool + poolSize, special);
        poolSize += strlen(special);
    }

    if (poolSize == 0) {
        printf("Error: At least one character type must be selected.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length; i++) {
        password[i] = characterPool[rand() % poolSize];
    }
    password[length] = '\0';
}

int main() {
    srand(time(0));

    int length, useUpper, useLower, useDigits, useSpecial;
    
    printf("Welcome to the Secure Password Generator!\n");
    printf("Enter desired password length (1-%d): ", MAX_LENGTH);
    scanf("%d", &length);
    
    if (length < 1 || length > MAX_LENGTH) {
        printf("Invalid length. Please choose between 1 and %d.\n", MAX_LENGTH);
        return EXIT_FAILURE;
    }

    printf("Include uppercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &useUpper);
    printf("Include lowercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &useLower);
    printf("Include digits? (1 for yes, 0 for no): ");
    scanf("%d", &useDigits);
    printf("Include special characters? (1 for yes, 0 for no): ");
    scanf("%d", &useSpecial);

    char password[MAX_LENGTH + 1];
    generatePassword(password, length, useUpper, useLower, useDigits, useSpecial);

    printf("Generated Password: %s\n", password);

    return EXIT_SUCCESS;
}