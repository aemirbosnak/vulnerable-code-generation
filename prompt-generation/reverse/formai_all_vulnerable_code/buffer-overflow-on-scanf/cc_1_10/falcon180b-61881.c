//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

// Function to encrypt the message using recursion
void encrypt(char* message, int key, int length) {
    if (length == 0) {
        return;
    }

    // XOR the current character with the key
    message[0] ^= key;

    // Recursively call the function for the rest of the message
    encrypt(message + 1, key, length - 1);
}

// Function to decrypt the message using recursion
void decrypt(char* message, int key, int length) {
    if (length == 0) {
        return;
    }

    // XOR the current character with the key
    message[0] ^= key;

    // Recursively call the function for the rest of the message
    decrypt(message + 1, key, length - 1);
}

// Function to generate a random key
void generate_key(char* key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 256;
    }
}

int main() {
    // Generate a key
    char key[MAX_KEY_LENGTH];
    generate_key(key, MAX_KEY_LENGTH);

    // Get the message from the user
    char message[MAX_MESSAGE_LENGTH];
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Encrypt the message
    encrypt(message, key[0], strlen(message));

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt(message, key[0], strlen(message));

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}