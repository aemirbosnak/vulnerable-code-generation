//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define encryption and decryption functions
void encrypt(unsigned char* message, int length, unsigned char* key);
void decrypt(unsigned char* message, int length, unsigned char* key);

// Define the key
unsigned char key[] = "mysecretkey";

// Main function
int main() {

    // Get the message from the user
    char message[100];
    printf("Enter the message to encrypt: ");
    gets(message);

    // Encrypt the message
    int length = strlen(message);
    encrypt((unsigned char*)message, length, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt the message
    decrypt((unsigned char*)message, length, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}

// Encryption function
void encrypt(unsigned char* message, int length, unsigned char* key) {

    // XOR each character of the message with the corresponding character of the key
    for (int i = 0; i < length; i++) {

        message[i] ^= key[i % strlen(key)];
    }
}

// Decryption function
void decrypt(unsigned char* message, int length, unsigned char* key) {

    // XOR each character of the message with the corresponding character of the key
    for (int i = 0; i < length; i++) {

        message[i] ^= key[i % strlen(key)];
    }
}