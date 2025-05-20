#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_KEY_LENGTH 10
#define BLOCK_SIZE 16

typedef struct {
    char key[MAX_KEY_LENGTH];
} EncryptionKey;

void encrypt(char* plaintext, EncryptionKey key) {
    char ciphertext[strlen(plaintext) + 1];

    for (int i = 0; plaintext[i]; i++) {
        ciphertext[i] = (plaintext[i] + key.key[i % MAX_KEY_LENGTH]) % 256;
    }

    // This will cause an integer overflow when the key is too long.
    // The length of the key is not checked or validated.
    printf("Key length: %lu\n", sizeof(key.key) / sizeof(key.key[0]));
}

int main() {
    char plaintext[] = "Secret Message";
    EncryptionKey key;

    printf("Enter key (up to %d characters): ", MAX_KEY_LENGTH);
    fgets(key.key, sizeof(key.key), stdin);

    encrypt(plaintext, key);

    printf("Ciphertext: %s\n", plaintext);

    return 0;
}
