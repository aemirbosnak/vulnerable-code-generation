//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 1024

// Function declarations
void encryptText(char *plaintext, int shift, char *ciphertext);
void displayInstructions();

int main() {
    char plaintext[MAX_TEXT_LENGTH];
    char ciphertext[MAX_TEXT_LENGTH];
    int shift;

    // Display instructions to the user
    displayInstructions();

    // Get user input for plaintext
    printf("Enter the text you want to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    
    // Remove newline character if present
    plaintext[strcspn(plaintext, "\n")] = 0;

    // Get user input for shift value
    printf("Enter the shift value (1-25): ");
    if (scanf("%d", &shift) != 1 || shift < 1 || shift > 25) {
        printf("Invalid shift value! Please enter a number between 1 and 25.\n");
        return 1; // Exit if invalid input
    }

    // Call the encryption function
    encryptText(plaintext, shift, ciphertext);

    // Display the encrypted text
    printf("Your encrypted text is:\n%s\n", ciphertext);

    return 0;
}

// Function to encrypt the text
void encryptText(char *plaintext, int shift, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char currentChar = plaintext[i];
        
        if (isalpha(currentChar)) {
            char base = islower(currentChar) ? 'a' : 'A';
            // Apply the shift and wrap around if necessary
            ciphertext[i] = (currentChar - base + shift) % 26 + base;
        } else {
            // Non-alphabetical characters remain unchanged
            ciphertext[i] = currentChar;
        }
    }
    // Null-terminate the string
    ciphertext[i] = '\0';
}

// Function to display instructions
void displayInstructions() {
    printf("Welcome to the C Encryption Program using Caesar Cipher!\n");
    printf("In this program, you will be able to encrypt your text with a custom shift value.\n");
    printf("Simply enter the text you want to encrypt followed by a shift value from 1 to 25.\n");
    printf("Let the adventure of cryptography begin!\n\n");
}