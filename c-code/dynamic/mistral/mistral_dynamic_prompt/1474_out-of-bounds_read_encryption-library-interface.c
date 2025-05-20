#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define KEY_SIZE 256
#define BLOCK_SIZE 64

void encrypt(char *plaintext, char *ciphertext, char *key) {
    char iv[BLOCK_SIZE];
    memset(iv, 0, BLOCK_SIZE);

    for (int i = 0; i < KEY_SIZE; ++i) {
        key[i] ^= iv[i % BLOCK_SIZE];
    }

    for (int i = 0; i < strlen(plaintext); ++i) {
        ciphertext[i] = plaintext[i] ^ key[(i - 1 + strlen(plaintext)) % KEY_SIZE];
    }
}

int main() {
    char key[KEY_SIZE];
    char plaintext[1024];
    char ciphertext[1024];

    printf("Enter a secret message to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter a key (min 256 characters): ");
    fgets(key, sizeof(key), stdin);

    encrypt(plaintext, ciphertext, key);

    printf("Encrypted message:\n%s\n", ciphertext);

    return 0;
}
