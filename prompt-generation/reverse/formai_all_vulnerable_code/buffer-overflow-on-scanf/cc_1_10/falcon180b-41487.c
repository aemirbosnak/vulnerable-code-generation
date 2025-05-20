//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8
#define ROUNDS 10

// Function prototypes
void generate_key(unsigned char key[KEY_SIZE]);
void encrypt(unsigned char plaintext[BLOCK_SIZE], unsigned char key[KEY_SIZE], unsigned char ciphertext[BLOCK_SIZE]);
void decrypt(unsigned char ciphertext[BLOCK_SIZE], unsigned char key[KEY_SIZE], unsigned char plaintext[BLOCK_SIZE]);

int main() {
    unsigned char key[KEY_SIZE];
    unsigned char plaintext[BLOCK_SIZE];
    unsigned char ciphertext[BLOCK_SIZE];

    // Generate a random key
    generate_key(key);

    // Encrypt a message
    printf("Enter a message to encrypt (max %d characters): ", BLOCK_SIZE - 1);
    scanf("%s", plaintext);
    encrypt(plaintext, key, ciphertext);
    printf("Encrypted message: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the message
    decrypt(ciphertext, key, plaintext);
    printf("Decrypted message: %s\n", plaintext);

    return 0;
}

void generate_key(unsigned char key[KEY_SIZE]) {
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(unsigned char plaintext[BLOCK_SIZE], unsigned char key[KEY_SIZE], unsigned char ciphertext[BLOCK_SIZE]) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % KEY_SIZE];
    }
}

void decrypt(unsigned char ciphertext[BLOCK_SIZE], unsigned char key[KEY_SIZE], unsigned char plaintext[BLOCK_SIZE]) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % KEY_SIZE];
    }
}