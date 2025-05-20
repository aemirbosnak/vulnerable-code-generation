//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 8

// Function to encrypt the message using the XOR cipher
void encrypt(char* message, char* key) {
    int i, j;
    char result[strlen(message)];

    // Convert message to uppercase
    for(i = 0; message[i]!= '\0'; i++) {
        result[i] = toupper(message[i]);
    }

    // XOR the message with the key
    for(i = 0, j = 0; i < strlen(result); i++, j++) {
        if(j == KEY_LENGTH) {
            j = 0;
        }
        result[i] ^= key[j];
    }

    // Print the encrypted message
    printf("Encrypted message: %s\n", result);
}

// Function to decrypt the message using the XOR cipher
void decrypt(char* message, char* key) {
    int i, j;
    char result[strlen(message)];

    // Convert message to uppercase
    for(i = 0; message[i]!= '\0'; i++) {
        result[i] = toupper(message[i]);
    }

    // XOR the message with the key
    for(i = 0, j = 0; i < strlen(result); i++, j++) {
        if(j == KEY_LENGTH) {
            j = 0;
        }
        result[i] ^= key[j];
    }

    // Print the decrypted message
    printf("Decrypted message: %s\n", result);
}

// Function to generate a random key
void generateKey(char* key) {
    int i;

    // Initialize the key with random characters
    for(i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

int main() {
    char message[100], key[KEY_LENGTH];

    // Get the message from the user
    printf("Enter the message to be encrypted/decrypted: ");
    scanf("%s", message);

    // Generate a random key
    generateKey(key);

    // Encrypt the message
    encrypt(message, key);

    // Decrypt the message
    decrypt(message, key);

    return 0;
}