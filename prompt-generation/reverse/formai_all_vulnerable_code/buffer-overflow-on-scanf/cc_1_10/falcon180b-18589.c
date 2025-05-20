//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

// Generate a key of size KEY_SIZE
void generate_key(char* key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a'; // Generate a random lowercase letter
    }
    key[KEY_SIZE] = '\0'; // Add null terminator
}

// Encrypt a message using a key
void encrypt(char* message, char* key) {
    int i, j;
    char encrypted_message[strlen(message)];
    for (i = 0, j = 0; i < strlen(message); i++) {
        encrypted_message[j] = message[i] ^ key[i % KEY_SIZE]; // XOR each character with the corresponding key character
        j++;
        if (j % BLOCK_SIZE == 0) {
            encrypted_message[j] = '\0'; // Add null terminator after each block
        }
    }
    encrypted_message[j] = '\0'; // Add final null terminator
    strcpy(message, encrypted_message); // Replace original message with encrypted message
}

// Decrypt a message using a key
void decrypt(char* message, char* key) {
    int i, j;
    char decrypted_message[strlen(message)];
    for (i = 0, j = 0; i < strlen(message); i++) {
        decrypted_message[j] = message[i] ^ key[i % KEY_SIZE]; // XOR each character with the corresponding key character
        j++;
        if (j % BLOCK_SIZE == 0) {
            decrypted_message[j] = '\0'; // Add null terminator after each block
        }
    }
    decrypted_message[j] = '\0'; // Add final null terminator
    strcpy(message, decrypted_message); // Replace original message with decrypted message
}

int main() {
    char message[100], key[KEY_SIZE + 1];
    generate_key(key); // Generate a key
    printf("Enter a message to encrypt: ");
    scanf("%s", message);
    encrypt(message, key); // Encrypt the message
    printf("Encrypted message: %s\n", message);
    decrypt(message, key); // Decrypt the message
    printf("Decrypted message: %s\n", message);
    return 0;
}