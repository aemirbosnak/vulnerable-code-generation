//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

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

int main() {
    unsigned char key[KEY_SIZE];
    unsigned char plaintext[BLOCK_SIZE];
    unsigned char ciphertext[BLOCK_SIZE];

    generate_key(key);

    printf("Enter plaintext (8 bytes): ");
    scanf("%8s", (char*)plaintext);

    encrypt(plaintext, key, ciphertext);

    printf("Ciphertext: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", ciphertext[i]);
    }
    printf("\n");

    decrypt(ciphertext, key, plaintext);

    printf("Decrypted plaintext: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%c", plaintext[i]);
    }
    printf("\n");

    return 0;
}