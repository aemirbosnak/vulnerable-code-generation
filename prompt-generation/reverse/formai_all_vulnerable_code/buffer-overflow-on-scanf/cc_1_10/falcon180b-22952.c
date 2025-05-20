//Falcon-180B DATASET v1.0 Category: Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY "ThisIsMySecretKey"
#define BLOCK_SIZE 16

void encrypt(char *plaintext, char *ciphertext, int mode) {
    int i, j, len;
    char key[BLOCK_SIZE];
    char block[BLOCK_SIZE];

    len = strlen(plaintext);
    strncpy(key, KEY, BLOCK_SIZE);

    for (i = 0; i < len; i += BLOCK_SIZE) {
        strncpy(block, plaintext + i, BLOCK_SIZE);

        for (j = 0; j < BLOCK_SIZE; j++) {
            if (mode == 1) {
                ciphertext[i + j] = block[j] ^ key[j];
            } else if (mode == 2) {
                ciphertext[i + j] = block[j] ^ (key[j] + (int) (i / BLOCK_SIZE));
            } else {
                ciphertext[i + j] = block[j] ^ (key[j] ^ (int) (i / BLOCK_SIZE));
            }
        }
    }
}

void decrypt(char *ciphertext, char *plaintext, int mode) {
    int i, j, len;
    char key[BLOCK_SIZE];
    char block[BLOCK_SIZE];

    len = strlen(ciphertext);
    strncpy(key, KEY, BLOCK_SIZE);

    for (i = 0; i < len; i += BLOCK_SIZE) {
        strncpy(block, ciphertext + i, BLOCK_SIZE);

        for (j = 0; j < BLOCK_SIZE; j++) {
            if (mode == 1) {
                plaintext[i + j] = block[j] ^ key[j];
            } else if (mode == 2) {
                plaintext[i + j] = block[j] ^ (key[j] - (int) (i / BLOCK_SIZE));
            } else {
                plaintext[i + j] = block[j] ^ (key[j] ^ (int) (i / BLOCK_SIZE));
            }
        }
    }
}

int main() {
    char plaintext[100], ciphertext[100];
    int i, mode;

    printf("Enter the plaintext to be encrypted/decrypted: ");
    scanf("%s", plaintext);

    printf("Enter the mode (1: encryption, 2: decryption): ");
    scanf("%d", &mode);

    encrypt(plaintext, ciphertext, mode);
    printf("\nEncrypted/decrypted text: %s\n", ciphertext);

    return 0;
}