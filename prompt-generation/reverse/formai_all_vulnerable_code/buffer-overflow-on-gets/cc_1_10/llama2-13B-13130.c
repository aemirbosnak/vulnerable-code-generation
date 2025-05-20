//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

// Define a struct to hold the encryption parameters
struct encryption_params {
    char key[KEY_SIZE];
    int key_index;
};

// Function to generate a random key
void generate_key(struct encryption_params *params) {
    params->key[0] = 'A' + (rand() % 26);
    for (int i = 1; i < KEY_SIZE; i++) {
        params->key[i] = 'A' + (rand() % 26);
    }
    params->key_index = 0;
}

// Function to encrypt a block of text
void encrypt_block(struct encryption_params *params, char *plaintext, char *ciphertext) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        // XOR the plaintext character with the corresponding key character
        ciphertext[i] = plaintext[i] ^ params->key[params->key_index];
        params->key_index++;
        if (params->key_index == KEY_SIZE) {
            params->key_index = 0;
        }
    }
}

// Function to decrypt a block of text
void decrypt_block(struct encryption_params *params, char *ciphertext, char *plaintext) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        // XOR the ciphertext character with the corresponding key character
        plaintext[i] = ciphertext[i] ^ params->key[params->key_index];
        params->key_index++;
        if (params->key_index == KEY_SIZE) {
            params->key_index = 0;
        }
    }
}

int main() {
    // Create a struct to hold the encryption parameters
    struct encryption_params params;

    // Generate a random key
    generate_key(&params);

    // Create an array to hold the plaintext message
    char plaintext[50];
    gets(plaintext);

    // Create an array to hold the ciphertext message
    char ciphertext[50];

    // Encrypt the plaintext message
    encrypt_block(&params, plaintext, ciphertext);

    // Print the ciphertext message
    printf("Ciphertext: ");
    for (int i = 0; i < strlen(ciphertext); i++) {
        printf("%c", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the ciphertext message
    decrypt_block(&params, ciphertext, plaintext);

    // Print the plaintext message
    printf("Plaintext: ");
    for (int i = 0; i < strlen(plaintext); i++) {
        printf("%c", plaintext[i]);
    }
    printf("\n");

    return 0;
}