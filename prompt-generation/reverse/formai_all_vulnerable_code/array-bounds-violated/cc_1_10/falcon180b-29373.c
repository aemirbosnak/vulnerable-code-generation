//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8
#define ROUNDS 10

void generate_key(unsigned char *key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(unsigned char *key, unsigned char *input, unsigned char *output) {
    int i, j;
    unsigned char state[KEY_SIZE];
    for (i = 0; i < KEY_SIZE; i++) {
        state[i] = key[i];
    }
    for (i = 0; i < ROUNDS; i++) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            output[j] = input[j] ^ state[i * BLOCK_SIZE + j];
        }
    }
}

void decrypt(unsigned char *key, unsigned char *input, unsigned char *output) {
    int i, j;
    unsigned char state[KEY_SIZE];
    for (i = 0; i < KEY_SIZE; i++) {
        state[i] = key[i];
    }
    for (i = 0; i < ROUNDS; i++) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            output[j] = input[j] ^ state[i * BLOCK_SIZE + j];
            state[i * BLOCK_SIZE + j] = input[j];
        }
    }
}

int main() {
    unsigned char key[KEY_SIZE];
    generate_key(key);
    unsigned char input[BLOCK_SIZE];
    unsigned char output[BLOCK_SIZE];
    printf("Enter input: ");
    scanf("%s", input);
    encrypt(key, input, output);
    printf("Encrypted output: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02X ", output[i]);
    }
    printf("\n");
    decrypt(key, output, input);
    printf("Decrypted input: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%c", input[i]);
    }
    printf("\n");
    return 0;
}