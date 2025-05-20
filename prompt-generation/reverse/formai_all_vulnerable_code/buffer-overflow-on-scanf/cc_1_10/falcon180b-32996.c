//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 256
#define MAX_MESSAGE_SIZE 1024

// Function to generate a random key of given size
void generate_key(char* key, int size) {
    for (int i = 0; i < size; i++) {
        key[i] = rand() % 256;
    }
}

// Function to encrypt a message using a key
void encrypt(char* message, char* key, char* encrypted_message) {
    int message_size = strlen(message);
    int key_size = strlen(key);
    int encrypted_message_size = message_size + 1;

    for (int i = 0; i < message_size; i++) {
        encrypted_message[i] = message[i] ^ key[i % key_size];
    }

    encrypted_message[message_size] = '\0';
}

// Function to decrypt an encrypted message using a key
void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int encrypted_message_size = strlen(encrypted_message);
    int key_size = strlen(key);
    int decrypted_message_size = encrypted_message_size - 1;

    for (int i = 0; i < encrypted_message_size; i++) {
        decrypted_message[i] = encrypted_message[i] ^ key[i % key_size];
    }

    decrypted_message[decrypted_message_size] = '\0';
}

int main() {
    char key[MAX_KEY_SIZE];
    char message[MAX_MESSAGE_SIZE];
    char encrypted_message[MAX_MESSAGE_SIZE];
    char decrypted_message[MAX_MESSAGE_SIZE];

    // Generate a random key
    generate_key(key, strlen(key));

    // Get a message from the user
    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    // Encrypt the message using the key
    encrypt(message, key, encrypted_message);

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // Decrypt the encrypted message using the key
    decrypt(encrypted_message, key, decrypted_message);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}