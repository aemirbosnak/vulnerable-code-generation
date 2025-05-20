//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEY_SIZE 1024

// Function to generate a key
void generate_key(char* key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 256;
    }
}

// Function to encrypt the message using the key
void encrypt(char* message, char* key, int key_size, char* encrypted_message) {
    for (int i = 0; i < strlen(message); i++) {
        encrypted_message[i] = message[i] ^ key[i % key_size];
    }
    encrypted_message[strlen(message)] = '\0';
}

// Function to decrypt the message using the key
void decrypt(char* encrypted_message, char* key, int key_size, char* decrypted_message) {
    for (int i = 0; i < strlen(encrypted_message); i++) {
        decrypted_message[i] = encrypted_message[i] ^ key[i % key_size];
    }
    decrypted_message[strlen(encrypted_message)] = '\0';
}

int main() {
    char message[MAX_KEY_SIZE];
    char key[MAX_KEY_SIZE];
    char encrypted_message[MAX_KEY_SIZE];
    char decrypted_message[MAX_KEY_SIZE];

    // Get message from user
    printf("Enter message to encrypt: ");
    scanf("%s", message);

    // Generate key
    generate_key(key, strlen(message));

    // Encrypt message
    encrypt(message, key, strlen(message), encrypted_message);

    // Print encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt message
    decrypt(encrypted_message, key, strlen(message), decrypted_message);

    // Print decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}