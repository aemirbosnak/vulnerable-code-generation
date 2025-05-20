//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random password
void generatePassword(int length, int useUpper, int useLower, int useDigits, int useSpecial) {
    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower[] = "abcdefghijklmnopqrstuvwxyz";
    char digits[] = "0123456789";
    char special[] = "!@#$%^&*()_-+=<>?";

    char password[256]; // Buffer to hold the generated password
    int i, j;
    char *charSet = "";

    // Determine the character set based on user preference
    if (useUpper) {
        charSet = strcat(charSet, upper);
    }
    if (useLower) {
        charSet = strcat(charSet, lower);
    }
    if (useDigits) {
        charSet = strcat(charSet, digits);
    }
    if (useSpecial) {
        charSet = strcat(charSet, special);
    }
    
    int setSize = strlen(charSet);

    // Check if at least one character set is chosen
    if (setSize == 0) {
        printf("No character types selected. Unable to generate password.\n");
        return;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate the password
    for (i = 0; i < length; i++) {
        int randIndex = rand() % setSize;
        password[i] = charSet[randIndex];
    }
    password[length] = '\0'; // Null-terminate the string

    printf("Generated Password: %s\n", password);
}

// Main function
int main() {
    int length;
    int useUpper, useLower, useDigits, useSpecial;

    // Welcome message
    printf("===================================\n");
    printf("    Secure Password Generator\n");
    printf("===================================\n");

    // Get user input
    printf("Enter the desired password length (8-256): ");
    scanf("%d", &length);

    // Validate length
    if (length < 8 || length > 256) {
        printf("Password length must be between 8 and 256 characters.\n");
        return 1;
    }

    // Character type selection
    printf("Include Uppercase letters? (1 for Yes, 0 for No): ");
    scanf("%d", &useUpper);
    printf("Include Lowercase letters? (1 for Yes, 0 for No): ");
    scanf("%d", &useLower);
    printf("Include Digits? (1 for Yes, 0 for No): ");
    scanf("%d", &useDigits);
    printf("Include Special Characters? (1 for Yes, 0 for No): ");
    scanf("%d", &useSpecial);
    
    // Call the password generation function
    generatePassword(length, useUpper, useLower, useDigits, useSpecial);

    return 0;
}