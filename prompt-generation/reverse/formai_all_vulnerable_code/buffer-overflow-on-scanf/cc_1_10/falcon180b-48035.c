//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to generate a random key
void generate_key(char* key) {
    for (int i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'a';
    }
}

// Function to encrypt the message
void encrypt(char* message, char* key) {
    for (int i = 0; i < strlen(message); i++) {
        message[i] = message[i] + key[i % strlen(key)];
    }
}

// Function to decrypt the message
void decrypt(char* message, char* key) {
    for (int i = 0; i < strlen(message); i++) {
        message[i] = message[i] - key[i % strlen(key)];
    }
}

int main() {
    char message[MAX_SIZE];
    char key[MAX_SIZE];

    // Get message from user
    printf("Enter message to encrypt: ");
    scanf("%s", message);

    // Generate random key
    generate_key(key);

    // Encrypt message
    encrypt(message, key);

    // Print encrypted message
    printf("Encrypted message: %s\n", message);

    // Decrypt message
    decrypt(message, key);

    // Print decrypted message
    printf("Decrypted message: %s\n", message);

    return 0;
}