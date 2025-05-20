//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the text using a simple Caesar cipher method
void encrypt(char *message, int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        }
    }
}

// Function to decrypt the text using a simple Caesar cipher method
void decrypt(char *message, int key) {
    for (int i = 0; message[i] != '\0'; ++i) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' - key + 26) % 26) + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' - key + 26) % 26) + 'A';
        }
    }
}

// Function to get user input for the message
void getUserInput(char *message, int max_length) {
    printf("Enter your message (max %d characters): ", max_length - 1);
    fgets(message, max_length, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character
}

// Function to get user input for the encryption key
int getEncryptionKey() {
    int key;
    printf("Enter the encryption key (1-25): ");
    scanf("%d", &key);
    return (key % 26); // Ensure key is within 0-25
}

// Main function to run the encryption and decryption workflow
int main() {
    const int max_length = 256;
    char message[max_length];
    int key;

    // Get message and key from user
    getUserInput(message, max_length);
    key = getEncryptionKey();

    // Create a copy of the original message for decryption
    char encrypted_message[max_length];
    strcpy(encrypted_message, message);

    // Encrypt the message
    encrypt(encrypted_message, key);
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the message
    decrypt(encrypted_message, key);
    printf("Decrypted message: %s\n", encrypted_message);

    return 0;
}