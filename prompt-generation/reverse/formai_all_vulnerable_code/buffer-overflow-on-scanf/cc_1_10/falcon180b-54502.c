//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_KEY_SIZE 64
#define MAX_BLOCK_SIZE 16

// Function prototypes
void generate_key(char *key);
void encrypt_block(char *block, char *key);
void decrypt_block(char *block, char *key);

int main() {
    srand(time(NULL));
    char key[MAX_KEY_SIZE];
    generate_key(key);
    printf("Encryption key: %s\n", key);

    char plaintext[MAX_BLOCK_SIZE];
    printf("Enter plaintext (up to %d characters): ", MAX_BLOCK_SIZE - 1);
    scanf("%s", plaintext);

    char ciphertext[MAX_BLOCK_SIZE];
    encrypt_block(plaintext, key);
    printf("Ciphertext: %s\n", ciphertext);

    char decrypted_text[MAX_BLOCK_SIZE];
    decrypt_block(ciphertext, key);
    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}

// Generates a random encryption key of length MAX_KEY_SIZE
void generate_key(char *key) {
    for (int i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

// Encrypts a plaintext block using the provided key
void encrypt_block(char *block, char *key) {
    int block_size = strlen(block);
    if (block_size > MAX_BLOCK_SIZE) {
        printf("Error: Plaintext block is too long.\n");
        exit(1);
    }

    for (int i = 0; i < block_size; i++) {
        block[i] = block[i] ^ key[i % MAX_KEY_SIZE];
    }
}

// Decrypts a ciphertext block using the provided key
void decrypt_block(char *block, char *key) {
    int block_size = strlen(block);
    if (block_size > MAX_BLOCK_SIZE) {
        printf("Error: Ciphertext block is too long.\n");
        exit(1);
    }

    for (int i = 0; i < block_size; i++) {
        block[i] = block[i] ^ key[i % MAX_KEY_SIZE];
    }
}