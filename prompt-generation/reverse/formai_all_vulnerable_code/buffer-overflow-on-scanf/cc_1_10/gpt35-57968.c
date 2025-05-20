//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// Function to generate a random number between minimum and maximum values
int generateRandomNumber(int minimum, int maximum) {
    return rand() % (maximum - minimum + 1) + minimum;
}

// Function to generate a random uppercase letter
char generateRandomUppercaseLetter() {
    return generateRandomNumber('A', 'Z');
}

// Function to generate a random lowercase letter
char generateRandomLowercaseLetter() {
    return generateRandomNumber('a', 'z');
}

// Function to generate a random digit
char generateRandomDigit() {
    return generateRandomNumber('0', '9');
}

// Function to generate a random special character
char generateRandomSpecialCharacter() {
    char specialCharacters[] = "!@#$%^&*()_+{}[]<>,.?/|~";
    return specialCharacters[generateRandomNumber(0, sizeof(specialCharacters)-1)];
}

// Function to generate a secure password with given length
void generateSecurePassword(int length) {
    int i;
    char password[length+1];
    password[length] = '\0'; // Set the last character to '\0' to indicate end of string

    srand(time(NULL)); // Seed the random number generator

    for(i=0; i<length; i++) {
        int type = generateRandomNumber(1, 4); // Generate a random number between 1 and 4 to select the character type
        switch(type) {
            case 1:
                password[i] = generateRandomUppercaseLetter();
                break;
            case 2:
                password[i] = generateRandomLowercaseLetter();
                break;
            case 3:
                password[i] = generateRandomDigit();
                break;
            case 4:
                password[i] = generateRandomSpecialCharacter();
                break;
        }
    }

    printf("Your secure password is: %s\n", password);
}

int main() {
    int length;

    printf("Welcome to the Secure Password Generator\n");
    printf("Please enter the desired length of your password: ");
    scanf("%d", &length);

    if(length < 8 || length > 32) {
        printf("Error: Password length must be between 8 and 32 characters\n");
    } else {
        generateSecurePassword(length);
    }

    return 0;
}