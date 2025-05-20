//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_LENGTH 12
#define MAX_LENGTH 20
#define NUM_SPECIAL_CHARS 12

// Function prototypes
void generatePassword(char *password, int length);
void addRandomCharacter(char *password, int *index, const char *chars);
void addRandomSpecialCharacter(char *password, int *index);
void addRandomDigit(char *password, int *index);
void addRandomUppercase(char *password, int *index);
void addRandomLowercase(char *password, int *index);
int isValidLength(int length);
void shuffle(char *password, int length);
void printPassword(const char *password);

const char *lowercase = "abcdefghijklmnopqrstuvwxyz";
const char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *digits = "0123456789";
const char *specialChars = "!@#$%^&*()-_=+[]{}|;:',.<>?/";

// Main function
int main() {
    srand((unsigned int)time(NULL));
    int passwordLength;

    // User input for password length
    printf("Welcome to the Secure Password Generator!\n");
    printf("Please enter the desired password length (%d to %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &passwordLength);

    // Validate the user input
    if (!isValidLength(passwordLength)) {
        fprintf(stderr, "Error: Password length must be between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        return EXIT_FAILURE;
    }

    char password[MAX_LENGTH + 1];
    generatePassword(password, passwordLength); // Generate the password
    password[passwordLength] = '\0'; // Null-terminate the password string

    // Print the generated password
    printPassword(password);
    return EXIT_SUCCESS;
}

// Function to check if the password length is valid
int isValidLength(int length) {
    return length >= MIN_LENGTH && length <= MAX_LENGTH;
}

// Function to generate the password
void generatePassword(char *password, int length) {
    int index = 0;

    // Ensure at least one character of each type is included
    addRandomLowercase(password, &index);
    addRandomUppercase(password, &index);
    addRandomDigit(password, &index);
    addRandomSpecialCharacter(password, &index);

    // Fill the rest of the password with random characters
    while (index < length) {
        int randomChoice = rand() % 4; // Random choice among four character types

        switch (randomChoice) {
            case 0: addRandomLowercase(password, &index); break;
            case 1: addRandomUppercase(password, &index); break;
            case 2: addRandomDigit(password, &index); break;
            case 3: addRandomSpecialCharacter(password, &index); break;
        }
    }

    // Shuffle the password to prevent predictable order
    shuffle(password, length);
}

// Function to shuffle characters in the password
void shuffle(char *password, int length) {
    for (int i = 0; i < length; i++) {
        int j = rand() % length; // Random index for shuffling
        // Swap characters
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}

// Function to add a random lowercase character
void addRandomLowercase(char *password, int *index) {
    password[(*index)++] = lowercase[rand() % strlen(lowercase)];
}

// Function to add a random uppercase character
void addRandomUppercase(char *password, int *index) {
    password[(*index)++] = uppercase[rand() % strlen(uppercase)];
}

// Function to add a random digit
void addRandomDigit(char *password, int *index) {
    password[(*index)++] = digits[rand() % strlen(digits)];
}

// Function to add a random special character
void addRandomSpecialCharacter(char *password, int *index) {
    password[(*index)++] = specialChars[rand() % strlen(specialChars)];
}

// Function to print the generated password
void printPassword(const char *password) {
    printf("Generated Secure Password: %s\n", password);
}