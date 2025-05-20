//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

// Function to generate a random key
void generate_key(char key[KEY_SIZE]) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

// Function to encrypt the message using key
void encrypt_message(char message[BLOCK_SIZE], char key[KEY_SIZE]) {
    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        message[i] = message[i] + key[i % KEY_SIZE];
        if (message[i] > 'z') {
            message[i] = message[i] - 26;
        }
    }
}

// Function to decrypt the message using key
void decrypt_message(char message[BLOCK_SIZE], char key[KEY_SIZE]) {
    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        message[i] = message[i] - key[i % KEY_SIZE];
        if (message[i] < 'a') {
            message[i] = message[i] + 26;
        }
    }
}

// Function to print the message
void print_message(char message[BLOCK_SIZE]) {
    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        if (message[i] == '\0') {
            printf(" ");
        } else {
            printf("%c", message[i]);
        }
    }
}

int main() {
    char message[BLOCK_SIZE];
    char key[KEY_SIZE];

    // Get the message from user
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);

    // Generate a random key
    generate_key(key);

    // Encrypt the message using key
    encrypt_message(message, key);

    // Print the encrypted message
    printf("Encrypted message: ");
    print_message(message);

    // Decrypt the message using key
    decrypt_message(message, key);

    // Print the decrypted message
    printf("\nDecrypted message: ");
    print_message(message);

    return 0;
}