//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Function declarations
char generateRandomChar();
int generateRandomNumber(int min, int max);
void generatePassword(int length);

int main() {
    int passwordLength;
    char userChoice;

    // Get length of password from user
    printf("Enter the length of the password (minimum 8 characters): ");
    scanf("%d", &passwordLength);

    // Ensure password length is at least 8
    while (passwordLength < 8) {
        printf("Password length must be at least 8 characters. Please try again.\n");
        printf("Enter the length of the password: ");
        scanf("%d", &passwordLength);
    }

    // Display password requirements to user
    printf("\nYour password must meet the following requirements:\n");
    printf("- At least one uppercase letter\n");
    printf("- At least one lowercase letter\n");
    printf("- At least one digit\n");
    printf("- At least one special character (!@#$%%^&*()_-+={}[]\\|:;\"'<>,.?/)\n");

    // Generate and display password
    printf("\nGenerating password...\n");
    generatePassword(passwordLength);

    return 0;
}

// Function for generating a random character
char generateRandomChar() {
    char randomChar;

    // Generate random number between 1 and 4
    int randNum = generateRandomNumber(1, 4);

    // Generate random character based on type
    switch (randNum) {
        case 1: // Uppercase letter
            randomChar = generateRandomNumber(65, 90);
            break;
        case 2: // Lowercase letter
            randomChar = generateRandomNumber(97, 122);
            break;
        case 3: // Digit
            randomChar = generateRandomNumber(48, 57);
            break;
        case 4: // Special character
            randomChar = generateRandomNumber(33, 47);
            if (randomChar == '\\' || randomChar == '\"' || randomChar == '\'') {
                randomChar++; // Skip over characters that need escaping
            }
            break;
    }

    return randomChar;
}

// Function for generating a random number between min and max (inclusive)
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function for generating a password with the given length
void generatePassword(int length) {
    char password[length + 1];
    int i, numUppercase = 0, numLowercase = 0, numDigit = 0, numSpecial = 0;

    // Seed random number generator
    srand(time(NULL));

    // Generate password
    for (i = 0; i < length; i++) {
        password[i] = generateRandomChar();
        if (isupper(password[i])) {
            numUppercase++;
        } else if (islower(password[i])) {
            numLowercase++;
        } else if (isdigit(password[i])) {
            numDigit++;
        } else {
            numSpecial++;
        }
    }
    password[length] = '\0';

    // Make sure password meets requirements
    while (numUppercase < 1 || numLowercase < 1 || numDigit < 1 || numSpecial < 1) {
        int index = generateRandomNumber(0, length - 1);
        char newChar = generateRandomChar();
        if (isupper(newChar)) {
            numUppercase++;
        } else if (islower(newChar)) {
            numLowercase++;
        } else if (isdigit(newChar)) {
            numDigit++;
        } else {
            numSpecial++;
        }
        password[index] = newChar;
    }

    // Display password
    printf("\nYour secure password is: %s\n", password);
}