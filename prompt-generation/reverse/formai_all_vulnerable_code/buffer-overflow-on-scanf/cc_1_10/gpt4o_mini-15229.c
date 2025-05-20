//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 128

// Function prototypes
void generatePassword(int length, char *password);
int isValidLength(int length);
void printPassword(char *password);

int main() {
    char password[MAX_PASSWORD_LENGTH + 1]; // +1 for the null terminator
    int length;

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Ask user for password length
    printf("Enter desired password length (8-128): ");
    scanf("%d", &length);

    // Validate length
    if (!isValidLength(length)) {
        printf("Invalid length! Please choose a length between 8 and 128.\n");
        return 1;
    }
    
    // Generate password
    generatePassword(length, password);
    
    // Print password
    printPassword(password);

    return 0;
}

// Function to generate a secure password of specified length
void generatePassword(int length, char *password) {
    const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digits[] = "0123456789";
    const char symbols[] = "!@#$%^&*()-_=+[]{}|;:,.<>?";

    // Ensure at least one character from each category is included
    password[0] = lowercase[rand() % strlen(lowercase)];
    password[1] = uppercase[rand() % strlen(uppercase)];
    password[2] = digits[rand() % strlen(digits)];
    password[3] = symbols[rand() % strlen(symbols)];

    // Fill the rest of the password with a mix of characters
    const char all_chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{}|;:,.<>?";
    for (int i = 4; i < length; i++) {
        password[i] = all_chars[rand() % strlen(all_chars)];
    }

    // Shuffle the password
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    
    // Null terminate the string
    password[length] = '\0';
}

// Function to validate the password length
int isValidLength(int length) {
    return length >= 8 && length <= MAX_PASSWORD_LENGTH;
}

// Function to print the generated password
void printPassword(char *password) {
    printf("Generated Password: %s\n", password);
}