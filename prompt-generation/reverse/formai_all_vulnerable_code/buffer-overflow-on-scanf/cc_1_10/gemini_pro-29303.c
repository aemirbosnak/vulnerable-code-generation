//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a message using a Caesar cipher
char *encrypt(char *message, int key) {
    // Allocate memory for the encrypted message
    char *encryptedMessage = malloc(strlen(message) + 1);

    // Encrypt the message by shifting each character by the specified key
    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            // Encrypt lowercase letters
            encryptedMessage[i] = ((message[i] - 'a' + key) % 26) + 'a';
        } else if (message[i] >= 'A' && message[i] <= 'Z') {
            // Encrypt uppercase letters
            encryptedMessage[i] = ((message[i] - 'A' + key) % 26) + 'A';
        } else {
            // Non-alphabetic characters are not encrypted
            encryptedMessage[i] = message[i];
        }
    }

    // Add the null terminator to the end of the encrypted message
    encryptedMessage[strlen(message)] = '\0';

    // Return the encrypted message
    return encryptedMessage;
}

// Function to decrypt a message using a Caesar cipher
char *decrypt(char *encryptedMessage, int key) {
    // Allocate memory for the decrypted message
    char *decryptedMessage = malloc(strlen(encryptedMessage) + 1);

    // Decrypt the message by shifting each character by the negative of the specified key
    for (int i = 0; i < strlen(encryptedMessage); i++) {
        if (encryptedMessage[i] >= 'a' && encryptedMessage[i] <= 'z') {
            // Decrypt lowercase letters
            decryptedMessage[i] = ((encryptedMessage[i] - 'a' - key) % 26) + 'a';
        } else if (encryptedMessage[i] >= 'A' && encryptedMessage[i] <= 'Z') {
            // Decrypt uppercase letters
            decryptedMessage[i] = ((encryptedMessage[i] - 'A' - key) % 26) + 'A';
        } else {
            // Non-alphabetic characters are not decrypted
            decryptedMessage[i] = encryptedMessage[i];
        }
    }

    // Add the null terminator to the end of the decrypted message
    decryptedMessage[strlen(encryptedMessage)] = '\0';

    // Return the decrypted message
    return decryptedMessage;
}

int main() {
    // Declare variables to store the message, key, encrypted message, and decrypted message
    char message[100];
    int key;
    char *encryptedMessage;
    char *decryptedMessage;

    // Get the message from the user
    printf("Enter the message to be encrypted: ");
    fgets(message, 100, stdin);

    // Get the key from the user
    printf("Enter the encryption key (0-25): ");
    scanf("%d", &key);

    // Encrypt the message using the Caesar cipher
    encryptedMessage = encrypt(message, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", encryptedMessage);

    // Decrypt the encrypted message using the Caesar cipher
    decryptedMessage = decrypt(encryptedMessage, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decryptedMessage);

    // Free the allocated memory
    free(encryptedMessage);
    free(decryptedMessage);

    return 0;
}