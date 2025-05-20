//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key for encryption and decryption
#define KEY "1234567890ABCDEF"

// Function to encrypt a message using a recursive approach
char* encrypt(char* message, int start, int end) {
    // Check if the base case is reached
    if (start >= end) {
        return message;
    }

    // Swap the characters at the start and end positions
    char temp = message[start];
    message[start] = message[end];
    message[end] = temp;

    // Recursively encrypt the remaining substring
    return encrypt(message, start + 1, end - 1);
}

// Function to decrypt a message using a recursive approach
char* decrypt(char* message, int start, int end) {
    // Check if the base case is reached
    if (start >= end) {
        return message;
    }

    // Swap the characters at the start and end positions
    char temp = message[start];
    message[start] = message[end];
    message[end] = temp;

    // Recursively decrypt the remaining substring
    return decrypt(message, start + 1, end - 1);
}

// Main function
int main() {
    // Get the message to be encrypted
    char message[100];
    printf("Enter the message to be encrypted: ");
    gets(message);

    // Encrypt the message using the recursive function
    char* encryptedMessage = encrypt(message, 0, strlen(message) - 1);
    printf("Encrypted message: %s\n", encryptedMessage);

    // Decrypt the encrypted message using the recursive function
    char* decryptedMessage = decrypt(encryptedMessage, 0, strlen(encryptedMessage) - 1);
    printf("Decrypted message: %s\n", decryptedMessage);

    return 0;
}