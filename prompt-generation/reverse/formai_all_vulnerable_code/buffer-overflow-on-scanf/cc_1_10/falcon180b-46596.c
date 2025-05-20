//Falcon-180B DATASET v1.0 Category: Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 256

// Function to generate a random key
void generate_key(char *key, int key_size) {
    int i;
    for (i = 0; i < key_size; i++) {
        key[i] = rand() % 256;
    }
}

// Function to encrypt the message using the key
void encrypt(char *message, char *key, int key_size) {
    int i, j;
    for (i = 0; i < strlen(message); i++) {
        message[i] ^= key[i % key_size];
    }
}

// Function to decrypt the message using the key
void decrypt(char *message, char *key, int key_size) {
    int i, j;
    for (i = 0; i < strlen(message); i++) {
        message[i] ^= key[i % key_size];
    }
}

int main() {
    char message[MAX_KEY_SIZE];
    char key[MAX_KEY_SIZE];

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key, strlen(message));

    // Encrypt the message using the key
    encrypt(message, key, strlen(message));

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message using the key
    decrypt(message, key, strlen(message));

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}