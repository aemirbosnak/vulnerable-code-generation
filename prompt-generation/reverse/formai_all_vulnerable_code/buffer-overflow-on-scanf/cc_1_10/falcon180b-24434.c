//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 64

// Function to generate a random key
void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

// Function to encrypt a message using the key
void encrypt(char *message, char *key, char *ciphertext) {
    int i, j, n;
    char plaintext[BLOCK_SIZE];
    char buffer[BLOCK_SIZE];
    strncpy(plaintext, message, BLOCK_SIZE);
    n = strlen(plaintext);
    for (i = 0; i < n; i++) {
        buffer[i] = plaintext[i] ^ key[i % KEY_SIZE];
    }
    strncpy(ciphertext, buffer, BLOCK_SIZE);
}

// Function to decrypt a message using the key
void decrypt(char *ciphertext, char *key, char *message) {
    int i, j, n;
    char plaintext[BLOCK_SIZE];
    char buffer[BLOCK_SIZE];
    strncpy(buffer, ciphertext, BLOCK_SIZE);
    n = strlen(buffer);
    for (i = 0; i < n; i++) {
        plaintext[i] = buffer[i] ^ key[i % KEY_SIZE];
    }
    strncpy(message, plaintext, BLOCK_SIZE);
}

// Function to display the key
void display_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        printf("%02X", key[i]);
    }
    printf("\n");
}

// Function to display the message
void display_message(char *message) {
    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        printf("%c", message[i]);
    }
    printf("\n");
}

int main() {
    char key[KEY_SIZE];
    char message[BLOCK_SIZE];
    char ciphertext[BLOCK_SIZE];

    // Generate a random key
    generate_key(key);

    // Display the key
    printf("Key: ");
    display_key(key);

    // Prompt the user for a message
    printf("Enter a message: ");
    scanf("%s", message);

    // Encrypt the message
    encrypt(message, key, ciphertext);

    // Display the encrypted message
    printf("Encrypted message: ");
    display_message(ciphertext);

    // Decrypt the message
    decrypt(ciphertext, key, message);

    // Display the decrypted message
    printf("Decrypted message: ");
    display_message(message);

    return 0;
}