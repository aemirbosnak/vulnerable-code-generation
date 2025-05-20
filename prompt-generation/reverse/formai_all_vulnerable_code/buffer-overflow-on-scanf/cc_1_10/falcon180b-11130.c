//Falcon-180B DATASET v1.0 Category: Encryption ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

unsigned char key[KEY_SIZE] = {0}; // Initialize key with all zeros
unsigned char plaintext[BLOCK_SIZE] = {0}; // Initialize plaintext with all zeros
unsigned char ciphertext[BLOCK_SIZE] = {0}; // Initialize ciphertext with all zeros

void generate_key(unsigned char* key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256; // Generate a random key
    }
}

void encrypt(unsigned char* plaintext, unsigned char* key) {
    int i, j;
    for (i = 0; i < BLOCK_SIZE; i++) {
        plaintext[i] ^= key[i]; // XOR plaintext and key
    }
}

void decrypt(unsigned char* ciphertext, unsigned char* key) {
    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        ciphertext[i] ^= key[i]; // XOR ciphertext and key
    }
}

int main() {
    unsigned char plaintext[BLOCK_SIZE];
    unsigned char ciphertext[BLOCK_SIZE];
    unsigned char key[KEY_SIZE];

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    generate_key(key); // Generate a random key

    encrypt(plaintext, key); // Encrypt plaintext

    printf("Encrypted ciphertext: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%d ", ciphertext[i]);
    }

    decrypt(ciphertext, key); // Decrypt ciphertext

    printf("\nDecrypted plaintext: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%d ", plaintext[i]);
    }

    return 0;
}