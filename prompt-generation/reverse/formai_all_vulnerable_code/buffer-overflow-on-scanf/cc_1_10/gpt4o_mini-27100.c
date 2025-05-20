//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to display the program header
void displayHeader() {
    printf("*****************************************\n");
    printf("*         Welcome to the Secure        *\n");
    printf("*         Password Generator!           *\n");
    printf("*****************************************\n");
    printf("\n");
}

// Function to generate a random character from a given set
char getRandomCharacter(const char *characterSet) {
    int index = rand() % strlen(characterSet);
    return characterSet[index];
}

// Function to generate a secure password
void generatePassword(int length, int useUppercase, int useLowercase, int useDigits, int useSpecial) {
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char digits[] = "0123456789";
    char special[] = "!@#$%^&*()-_=+[]{}|;:,.<>?/";
    
    char password[length + 1]; // +1 for the null terminator
    char characterSet[256]; // A temporary array to hold the chosen character set
    int characterSetSize = 0;
    
    // Building the character set based on user's choices
    if (useUppercase) {
        strcat(characterSet, uppercase);
        characterSetSize += strlen(uppercase);
    }
    if (useLowercase) {
        strcat(characterSet, lowercase);
        characterSetSize += strlen(lowercase);
    }
    if (useDigits) {
        strcat(characterSet, digits);
        characterSetSize += strlen(digits);
    }
    if (useSpecial) {
        strcat(characterSet, special);
        characterSetSize += strlen(special);
    }

    // Ensure at least one character set is selected
    if (characterSetSize == 0) {
        printf("Error: At least one character type must be selected!\n");
        return;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate the password
    for (int i = 0; i < length; i++) {
        password[i] = getRandomCharacter(characterSet);
    }
    password[length] = '\0'; // Null terminate the password

    // Display the generated password
    printf("Your generated password is: %s\n", password);
}

int main() {
    int length;
    int useUppercase, useLowercase, useDigits, useSpecial;

    // Display header
    displayHeader();

    // User input for password criteria
    printf("Enter desired password length (8-64): ");
    scanf("%d", &length);
    if (length < 8 || length > 64) {
        printf("Error: Password length must be between 8 and 64.\n");
        return 1;
    }

    printf("Include uppercase letters? (1 for Yes, 0 for No): ");
    scanf("%d", &useUppercase);
    printf("Include lowercase letters? (1 for Yes, 0 for No): ");
    scanf("%d", &useLowercase);
    printf("Include digits? (1 for Yes, 0 for No): ");
    scanf("%d", &useDigits);
    printf("Include special characters? (1 for Yes, 0 for No): ");
    scanf("%d", &useSpecial);

    // Generate and display the password
    generatePassword(length, useUppercase, useLowercase, useDigits, useSpecial);

    return 0;
}