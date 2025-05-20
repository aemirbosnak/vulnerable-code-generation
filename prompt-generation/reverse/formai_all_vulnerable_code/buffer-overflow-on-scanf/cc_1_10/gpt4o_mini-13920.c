//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, int key) {
    for (int i = 0; message[i] != '\0'; i++) {
        // Shift only alphabetic characters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' + key) % 26) + 'A';
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' + key) % 26) + 'a';
        }
    }
}

void decrypt(char *message, int key) {
    for (int i = 0; message[i] != '\0'; i++) {
        // Shift only alphabetic characters
        if (message[i] >= 'A' && message[i] <= 'Z') {
            message[i] = ((message[i] - 'A' - key + 26) % 26) + 'A'; // +26 to ensure non-negative
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            message[i] = ((message[i] - 'a' - key + 26) % 26) + 'a'; // +26 to ensure non-negative
        }
    }
}

int main() {
    char message[256];
    int key;

    printf("Welcome to the Simple Caesar Cipher Program!\n");

    // User input - message
    printf("Enter a message to encrypt (max 255 characters): ");
    fgets(message, sizeof(message), stdin);
    
    // Remove the newline character
    size_t len = strlen(message);
    if (len > 0 && message[len - 1] == '\n') {
        message[len - 1] = '\0';
    }

    // User input - key
    printf("Enter an encryption key (0-25): ");
    scanf("%d", &key);
    
    // Normalize the key to be within 0-25
    key = key % 26;
    if (key < 0) key += 26;

    // Encrypt the message
    char *encryptedMessage = strdup(message); // Create a copy for encryption
    encrypt(encryptedMessage, key);
    printf("Encrypted message: %s\n", encryptedMessage);

    // Decrypt the message
    char *decryptedMessage = strdup(encryptedMessage); // Create a copy for decryption
    decrypt(decryptedMessage, key);
    printf("Decrypted message: %s\n", decryptedMessage);

    // Clean up allocated memory
    free(encryptedMessage);
    free(decryptedMessage);

    return 0;
}