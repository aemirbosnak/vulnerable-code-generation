//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MSG_LENGTH 1024

// Function to encrypt the input message using a Caesar cipher
void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + shift) % 26) + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + shift) % 26) + 'a';
        }
        message[i] = ch;  // replace the original character
    }
}

// Function to decrypt the input message using a Caesar cipher
void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' - shift + 26) % 26) + 'A'; // +26 to avoid negative values
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' - shift + 26) % 26) + 'a'; // +26 to avoid negative values
        }
        message[i] = ch;  // replace the original character
    }
}

// Function to get the shift value from the user
int getShiftValue() {
    int shift;
    printf("Enter a shift value (1-25): ");
    scanf("%d", &shift);
    
    // Basic validation
    while (shift < 1 || shift > 25) {
        printf("Invalid shift value. Please enter a value between 1 and 25: ");
        scanf("%d", &shift);
    }
    return shift;
}

// Main function
int main() {
    char message[MAX_MSG_LENGTH];
    int shift = 0;
    int choice = 0;

    printf("=== Caesar Cipher Encryption/Decryption ===\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");

    while (1) {
        printf("Choose an option: ");
        scanf("%d", &choice);

        if (choice == 3) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        // Get the shift value before proceeding with encryption/decryption
        shift = getShiftValue();

        // Clear the input buffer
        while (getchar() != '\n');

        // Get the message from the user
        printf("Enter your message (max %d characters): ", MAX_MSG_LENGTH - 1);
        fgets(message, sizeof(message), stdin);
        
        // Remove newline character from fgets input
        message[strcspn(message, "\n")] = '\0';

        if (choice == 1) {
            encrypt(message, shift);
            printf("Encrypted message: %s\n", message);
        } else if (choice == 2) {
            decrypt(message, shift);
            printf("Decrypted message: %s\n", message);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}