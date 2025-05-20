//Falcon-180B DATASET v1.0 Category: Encryption ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LEN 16
#define BLOCK_LEN 8

// Function to generate a key
void generate_key(unsigned char* key) {
    for(int i = 0; i < KEY_LEN; i++) {
        key[i] = rand() % 256;
    }
}

// Function to encrypt a message
void encrypt(unsigned char* message, int message_len, unsigned char* key) {
    int i, j;
    unsigned char cipher_text[message_len];

    // Initialize the cipher_text array
    for(i = 0; i < message_len; i++) {
        cipher_text[i] = 0;
    }

    // Encrypt the message
    for(i = 0; i < message_len; i += BLOCK_LEN) {
        for(j = 0; j < BLOCK_LEN && i + j < message_len; j++) {
            cipher_text[i + j] = message[i + j] ^ key[j % KEY_LEN];
        }
    }

    // Copy the cipher_text to the message buffer
    for(i = 0; i < message_len; i++) {
        message[i] = cipher_text[i];
    }
}

// Function to decrypt a message
void decrypt(unsigned char* message, int message_len, unsigned char* key) {
    int i, j;
    unsigned char plain_text[message_len];

    // Initialize the plain_text array
    for(i = 0; i < message_len; i++) {
        plain_text[i] = 0;
    }

    // Decrypt the message
    for(i = 0; i < message_len; i += BLOCK_LEN) {
        for(j = 0; j < BLOCK_LEN && i + j < message_len; j++) {
            plain_text[i + j] = message[i + j] ^ key[j % KEY_LEN];
        }
    }

    // Copy the plain_text to the message buffer
    for(i = 0; i < message_len; i++) {
        message[i] = plain_text[i];
    }
}

int main() {
    unsigned char message[100];
    unsigned char key[KEY_LEN];

    // Generate a key
    generate_key(key);

    // Get a message from the user
    printf("Enter a message: ");
    scanf("%s", message);

    // Encrypt the message
    encrypt(message, strlen(message), key);

    // Print the encrypted message
    printf("Encrypted message: ");
    for(int i = 0; i < strlen(message); i++) {
        printf("%02x", message[i]);
    }
    printf("\n");

    // Decrypt the message
    decrypt(message, strlen(message), key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}