//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LENGTH 32
#define BLOCK_SIZE 16

void generate_key(char* key) {
    time_t t;
    time(&t);
    srand(t);
    size_t i;
    for (i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char* plaintext, char* key, char* ciphertext) {
    size_t i, j, n;
    n = strlen(plaintext);
    for (i = 0, j = 0; i < n; i += BLOCK_SIZE) {
        char block[BLOCK_SIZE];
        memcpy(block, plaintext + i, BLOCK_SIZE);
        size_t k;
        for (k = 0; k < BLOCK_SIZE; k++) {
            block[k] ^= key[j];
            j = (j + 1) % KEY_LENGTH;
        }
        memcpy(ciphertext + i, block, BLOCK_SIZE);
    }
}

void decrypt(char* ciphertext, char* key, char* plaintext) {
    size_t i, j, n;
    n = strlen(ciphertext);
    for (i = 0, j = 0; i < n; i += BLOCK_SIZE) {
        char block[BLOCK_SIZE];
        memcpy(block, ciphertext + i, BLOCK_SIZE);
        size_t k;
        for (k = 0; k < BLOCK_SIZE; k++) {
            block[k] ^= key[j];
            j = (j + 1) % KEY_LENGTH;
        }
        memcpy(plaintext + i, block, BLOCK_SIZE);
    }
}

int main() {
    char key[KEY_LENGTH];
    char plaintext[100];
    char ciphertext[100];
    generate_key(key);

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    encrypt(plaintext, key, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key, plaintext);

    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}