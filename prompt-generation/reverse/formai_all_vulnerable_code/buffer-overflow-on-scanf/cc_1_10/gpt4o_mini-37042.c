//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generatePassword(int length, int useUpper, int useLower, int useDigits, int useSpecial, char *password) {
    const char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *lower = "abcdefghijklmnopqrstuvwxyz";
    const char *digits = "0123456789";
    const char *special = "!@#$%^&*()-_=+[]{};:,.<>?";

    char charSet[256]; // A large enough size to hold our characters
    int index = 0;

    // Include the desired character sets
    if (useUpper) {
        strcpy(&charSet[index], upper);
        index += strlen(upper);
    }
    if (useLower) {
        strcpy(&charSet[index], lower);
        index += strlen(lower);
    }
    if (useDigits) {
        strcpy(&charSet[index], digits);
        index += strlen(digits);
    }
    if (useSpecial) {
        strcpy(&charSet[index], special);
        index += strlen(special);
    }

    if (index == 0) {
        printf("No character types selected. Cannot generate password.\n");
        return;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate the password by picking random characters from the charSet
    for (int i = 0; i < length; i++) {
        password[i] = charSet[rand() % index];
    }
    password[length] = '\0'; // Null-terminate the string
}

int main() {
    int length, useUpper, useLower, useDigits, useSpecial;
    char password[100]; // Buffer for the generated password

    // Grateful message to users
    printf("*************************************\n");
    printf("*       Secure Password Generator    *\n");
    printf("*           By Grateful Developer    *\n");
    printf("*************************************\n\n");

    printf("Welcome to the Secure Password Generator!\n");
    printf("Please select your password criteria:\n");

    // Prompt for password length
    do {
        printf("Enter desired password length (8-128): ");
        scanf("%d", &length);
    } while (length < 8 || length > 128);

    // Prompt to include uppercase letters
    printf("Include uppercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &useUpper);

    // Prompt to include lowercase letters
    printf("Include lowercase letters? (1 for yes, 0 for no): ");
    scanf("%d", &useLower);

    // Prompt to include digits
    printf("Include digits? (1 for yes, 0 for no): ");
    scanf("%d", &useDigits);

    // Prompt to include special characters
    printf("Include special characters? (1 for yes, 0 for no): ");
    scanf("%d", &useSpecial);

    // Generate password
    generatePassword(length, useUpper, useLower, useDigits, useSpecial, password);

    // Output the generated password
    printf("\nYour new secure password is: %s\n", password);
    printf("Thank you for using the Secure Password Generator!\n");
    
    return 0;
}