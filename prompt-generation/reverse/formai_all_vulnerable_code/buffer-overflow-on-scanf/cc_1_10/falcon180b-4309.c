//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 32
#define MAX_MESSAGE_LENGTH 256

// Function to encrypt the message using the key
void encrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char encrypted_message[MAX_MESSAGE_LENGTH];
    int i, j;

    // Add the key to the message
    for (i = 0; i < message_length; i++) {
        encrypted_message[i] = message[i] + key[i % key_length];
    }

    // Encrypt the message
    for (i = 0; i < message_length; i++) {
        encrypted_message[i] = encrypted_message[i] ^ key[i % key_length];
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);
}

// Function to decrypt the message using the key
void decrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_length = strlen(key);
    char decrypted_message[MAX_MESSAGE_LENGTH];
    int i, j;

    // Decrypt the message
    for (i = 0; i < message_length; i++) {
        decrypted_message[i] = message[i] ^ key[i % key_length];
    }

    // Remove the key from the message
    for (i = 0; i < message_length; i++) {
        decrypted_message[i] = decrypted_message[i] - key[i % key_length];
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    int message_length, key_length;

    // Get the message from the user
    printf("Enter the message: ");
    scanf("%s", message);
    message_length = strlen(message);

    // Get the key from the user
    printf("Enter the key: ");
    scanf("%s", key);
    key_length = strlen(key);

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the message
    decrypt(message, key);

    return 0;
}