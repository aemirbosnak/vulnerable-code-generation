//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 128
#define MIN_LENGTH 8

// Function to display instructions
void displayInstructions() {
    printf("Welcome to the Secure Password Generator!\n");
    printf("Please choose the character sets for your password:\n");
    printf("1. Uppercase Letters (A-Z)\n");
    printf("2. Lowercase Letters (a-z)\n");
    printf("3. Digits (0-9)\n");
    printf("4. Special Characters (!@#$%^&*()-+=<>?)\n");
    printf("You can select multiple character sets for a more secure password.\n");
}

// Function that generates a random password
void generatePassword(char *password, int length, int useUpper, int useLower, int useDigits, int useSpecial) {
    const char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *lower = "abcdefghijklmnopqrstuvwxyz";
    const char *digits = "0123456789";
    const char *special = "!@#$%^&*()-+=<>?";
    char characterPool[MAX_LENGTH];
    int poolIndex = 0;

    if (useUpper) {
        strcpy(&characterPool[poolIndex], upper);
        poolIndex += strlen(upper);
    }
    if (useLower) {
        strcpy(&characterPool[poolIndex], lower);
        poolIndex += strlen(lower);
    }
    if (useDigits) {
        strcpy(&characterPool[poolIndex], digits);
        poolIndex += strlen(digits);
    }
    if (useSpecial) {
        strcpy(&characterPool[poolIndex], special);
        poolIndex += strlen(special);
    }

    // Ensure there is at least one character from each selected type
    int currentLength = 0;

    if (useUpper) {
        password[currentLength++] = upper[rand() % strlen(upper)];
    }
    if (useLower) {
        password[currentLength++] = lower[rand() % strlen(lower)];
    }
    if (useDigits) {
        password[currentLength++] = digits[rand() % strlen(digits)];
    }
    if (useSpecial) {
        password[currentLength++] = special[rand() % strlen(special)];
    }

    // Fill in the rest of the password randomly
    for (; currentLength < length; currentLength++) {
        password[currentLength] = characterPool[rand() % poolIndex];
    }

    // Shuffle the result to avoid predictability
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}

// Main Function
int main() {
    srand(time(NULL));
    char password[MAX_LENGTH + 1];
    int length = 0, useUpper = 0, useLower = 0, useDigits = 0, useSpecial = 0;

    displayInstructions();
    
    // User input for password length
    printf("Enter desired password length (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);
    
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid length! Please rerun the program and try again.\n");
        return 1;
    }
    
    // User choice for character sets
    printf("Include Uppercase Letters? (1 for Yes, 0 for No): ");
    scanf("%d", &useUpper);
    printf("Include Lowercase Letters? (1 for Yes, 0 for No): ");
    scanf("%d", &useLower);
    printf("Include Digits? (1 for Yes, 0 for No): ");
    scanf("%d", &useDigits);
    printf("Include Special Characters? (1 for Yes, 0 for No): ");
    scanf("%d", &useSpecial);

    if (!(useUpper || useLower || useDigits || useSpecial)) {
        printf("At least one character set must be selected!\n");
        return 1;
    }

    // Generate the password
    generatePassword(password, length, useUpper, useLower, useDigits, useSpecial);
    password[length] = '\0';  // Null-terminate the string

    // Output the result
    printf("Generated Password: %s\n", password);
    return 0;
}