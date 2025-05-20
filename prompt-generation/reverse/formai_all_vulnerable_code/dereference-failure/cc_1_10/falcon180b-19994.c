//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16 // 128-bit key
#define BLOCK_SIZE 16 // 128-bit block

void generate_key(char *key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char *data, char *key) {
    for (int i = 0; i < strlen(data); i++) {
        data[i] ^= key[i % KEY_SIZE];
    }
}

void decrypt(char *data, char *key) {
    encrypt(data, key);
}

int main() {
    srand(time(NULL));

    char key[KEY_SIZE];
    generate_key(key);

    char data[BLOCK_SIZE];
    for (int i = 0; i < BLOCK_SIZE; i++) {
        data[i] = rand() % 256;
    }

    printf("Plaintext: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02X ", data[i]);
    }
    printf("\n");

    encrypt(data, key);

    printf("Ciphertext: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02X ", data[i]);
    }
    printf("\n");

    decrypt(data, key);

    printf("Decrypted text: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%c", data[i]);
    }
    printf("\n");

    return 0;
}