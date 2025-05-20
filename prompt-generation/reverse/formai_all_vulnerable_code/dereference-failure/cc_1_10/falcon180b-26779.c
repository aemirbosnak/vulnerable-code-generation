//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 16
#define ROUNDS 10000

void encipher(unsigned char* state, unsigned char* key) {
    int i, j, k;
    unsigned char temp[BLOCK_SIZE];
    for (i = 0; i < ROUNDS; ++i) {
        for (j = 0; j < BLOCK_SIZE; ++j) {
            temp[j] = state[j] ^ key[i * BLOCK_SIZE + j];
        }
        for (j = 0; j < BLOCK_SIZE; ++j) {
            state[j] = temp[j];
        }
    }
}

void decipher(unsigned char* state, unsigned char* key) {
    encipher(state, key);
}

void generate_key(unsigned char* key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; ++i) {
        key[i] = rand() % 256;
    }
}

int main() {
    unsigned char key[KEY_SIZE];
    generate_key(key);
    printf("Key: ");
    for (int i = 0; i < KEY_SIZE; ++i) {
        printf("%02X ", key[i]);
    }
    printf("\n");

    unsigned char state[BLOCK_SIZE] = {0};
    printf("Plaintext: ");
    fgets(state, BLOCK_SIZE, stdin);

    encipher(state, key);
    printf("Ciphertext: ");
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        printf("%02X ", state[i]);
    }
    printf("\n");

    decipher(state, key);
    printf("Plaintext: ");
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        printf("%c", state[i]);
    }
    printf("\n");

    return 0;
}