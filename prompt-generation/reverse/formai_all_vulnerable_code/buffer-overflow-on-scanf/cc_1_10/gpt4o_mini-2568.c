//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

// Function to encrypt the text using a simple Caesar cipher
void encrypt(char *input, int shift, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + shift) % 26) + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + shift) % 26) + 'a';
        }
        
        output[i] = ch;
    }
    output[strlen(input)] = '\0'; // Null terminate the string
}

// Function to decrypt the text using a simple Caesar cipher
void decrypt(char *input, int shift, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' - shift + 26) % 26) + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' - shift + 26) % 26) + 'a';
        }

        output[i] = ch;
    }
    output[strlen(input)] = '\0'; // Null terminate the string
}

// Main function to interact with the user
int main() {
    char input[MAX_SIZE], output[MAX_SIZE];
    int choice, shift;

    printf("Welcome to the Simple Caesar Cipher Program!\n");
    printf("You can encrypt or decrypt your messages with peace of mind.\n\n");

    // User choice prompt
    printf("Choose an option:\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &choice);

    // Get the shift value from the user
    printf("Enter the shift value (1 - 25): ");
    scanf("%d", &shift);

    // Validate the shift value
    if (shift < 1 || shift > 25) {
        printf("Invalid shift value! Please enter a number between 1 and 25.\n");
        return 1;
    }

    // Handle the user's choice
    if (choice == 1) {
        // Encrypt
        printf("Enter the message to encrypt: ");
        getchar(); // Clear the newline character from the input buffer
        fgets(input, MAX_SIZE, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove the trailing newline

        encrypt(input, shift, output);
        printf("Encrypted Message: %s\n", output);
    } else if (choice == 2) {
        // Decrypt
        printf("Enter the message to decrypt: ");
        getchar(); // Clear the newline character from the input buffer
        fgets(input, MAX_SIZE, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove the trailing newline

        decrypt(input, shift, output);
        printf("Decrypted Message: %s\n", output);
    } else {
        printf("Invalid choice! Please select option 1 or 2.\n");
    }

    printf("\nThank you for using the Simple Caesar Cipher Program. Spread peace and harmony with encrypted messages!\n");
    return 0;
}