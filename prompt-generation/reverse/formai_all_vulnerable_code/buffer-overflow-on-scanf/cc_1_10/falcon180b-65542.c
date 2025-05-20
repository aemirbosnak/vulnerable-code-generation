//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: calm
#include <stdio.h>
#include <string.h>

#define MAX_KEY_SIZE 32
#define MAX_MESSAGE_SIZE 1024

// Function to generate a random key
void generate_key(char *key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 256;
    }
}

// Function to encrypt a message using the given key
void encrypt(char *message, char *key, int key_size, char *encrypted_message) {
    for (int i = 0; i < strlen(message); i++) {
        encrypted_message[i] = message[i] ^ key[i % key_size];
    }
}

// Function to decrypt an encrypted message using the given key
void decrypt(char *encrypted_message, char *key, int key_size, char *decrypted_message) {
    for (int i = 0; i < strlen(encrypted_message); i++) {
        decrypted_message[i] = encrypted_message[i] ^ key[i % key_size];
    }
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];
    char encrypted_message[MAX_MESSAGE_SIZE];
    char decrypted_message[MAX_MESSAGE_SIZE];

    // Get the message from the user
    printf("Enter a message: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key, strlen(message));

    // Encrypt the message
    encrypt(message, key, strlen(message), encrypted_message);

    // Decrypt the encrypted message
    decrypt(encrypted_message, key, strlen(message), decrypted_message);

    // Print the original and decrypted messages
    printf("Original message: %s\n", message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}