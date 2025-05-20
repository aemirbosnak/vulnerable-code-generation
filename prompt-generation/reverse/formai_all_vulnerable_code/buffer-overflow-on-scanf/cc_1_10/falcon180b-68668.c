//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8 // Size of the encryption key
#define BLOCK_SIZE 64 // Size of the data block
#define ROUNDS 10 // Number of rounds for the encryption algorithm

typedef struct {
    int key[SIZE]; // Encryption key
    int data[BLOCK_SIZE]; // Data block
} Block;

void generate_key(Block* block) {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        block->key[i] = rand() % 256;
    }
}

void encrypt(Block* block) {
    for (int i = 0; i < ROUNDS; i++) {
        for (int j = 0; j < SIZE; j++) {
            int k = j + block->key[j] % SIZE;
            int temp = block->data[k];
            block->data[k] = block->data[j];
            block->data[j] = temp;
        }
    }
}

void decrypt(Block* block) {
    for (int i = 0; i < ROUNDS; i++) {
        for (int j = 0; j < SIZE; j++) {
            int k = j + block->key[j] % SIZE;
            int temp = block->data[k];
            block->data[k] = block->data[j];
            block->data[j] = temp;
        }
    }
}

int main() {
    Block block;
    generate_key(&block);
    printf("Encryption key: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", block.key[i]);
    }
    printf("\n");

    int plaintext[BLOCK_SIZE];
    printf("Enter plaintext (max %d characters): ", BLOCK_SIZE - 1);
    for (int i = 0; i < BLOCK_SIZE; i++) {
        scanf("%c", &plaintext[i]);
    }

    for (int i = 0; i < BLOCK_SIZE; i++) {
        block.data[i] = plaintext[i];
    }

    encrypt(&block);
    printf("Ciphertext: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%d ", block.data[i]);
    }
    printf("\n");

    decrypt(&block);
    printf("Decrypted plaintext: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%c", block.data[i]);
    }
    printf("\n");

    return 0;
}