//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number
int randomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate random uppercase letter
char randomUppercase() {
    return (char) randomNumber(65, 90);
}

// Function to generate random lowercase letter
char randomLowercase() {
    return (char) randomNumber(97, 122);
}

// Function to generate random digit
char randomDigit() {
    return (char) randomNumber(48, 57);
}

// Function to generate random symbol
char randomSymbol() {
    int symbols[] = {33, 35, 36, 37, 38, 40, 41, 42, 43, 45, 46, 47, 58, 59, 60, 61, 62, 63, 64, 91, 92, 93, 94, 95, 123, 124, 125, 126};
    int index = randomNumber(0, 28);
    return (char) symbols[index];
}

// Function to generate secure random password
void generatePassword(int length) {
    srand(time(NULL)); // Seed for random number generator

    // Initialize password string
    char password[length+1];

    // Generate one uppercase letter
    password[0] = randomUppercase();

    // Generate one lowercase letter
    password[1] = randomLowercase();

    // Generate one digit
    password[2] = randomDigit();

    // Generate one symbol
    password[3] = randomSymbol();

    // Generate remaining characters
    for (int i = 4; i < length; i++) {
        int randomCategory = randomNumber(1, 4);
        char randomChar;
        switch (randomCategory) {
            case 1: // Uppercase letter
                randomChar = randomUppercase();
                break;
            case 2: // Lowercase letter
                randomChar = randomLowercase();
                break;
            case 3: // Digit
                randomChar = randomDigit();
                break;
            case 4: // Symbol
                randomChar = randomSymbol();
                break;
        }
        password[i] = randomChar;
    }

    // Add null terminator to end of string
    password[length] = '\0';

    // Print generated password
    printf("Your secure password: %s\n", password);
}

int main() {
    int length;
    printf("Enter length of password (minimum 8 characters): ");
    scanf("%d", &length);
    if (length < 8) {
        printf("Error: Password length must be at least 8 characters.\n");
    } else {
        generatePassword(length);
    }
    return 0;
}