//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8
#define ROUNDS 10000

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j, k;
    char state[KEY_SIZE + 1];
    strcpy(state, plaintext);

    for (i = 0; i < ROUNDS; i++) {
        for (j = 0; j < KEY_SIZE; j++) {
            k = state[j] ^ key[j];
            if (k < 32) {
                k += 32;
            }
            state[j] = k;
        }
    }

    strcpy(ciphertext, state);
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i, j, k;
    char state[KEY_SIZE + 1];
    strcpy(state, ciphertext);

    for (i = 0; i < ROUNDS; i++) {
        for (j = 0; j < KEY_SIZE; j++) {
            k = state[j] ^ key[j];
            if (k < 32) {
                k += 32;
            }
            state[j] = k;
        }
    }

    strcpy(plaintext, state);
}

int main() {
    char plaintext[1000], key[KEY_SIZE + 1], ciphertext[1000];
    int i, rounds;

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    generate_key(key);

    printf("Enter the number of rounds for encryption: ");
    scanf("%d", &rounds);

    encrypt(plaintext, key, ciphertext);

    printf("Encrypted text: %s\n", ciphertext);

    decrypt(ciphertext, key, plaintext);

    printf("Decrypted text: %s\n", plaintext);

    return 0;
}