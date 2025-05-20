//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "Cyberpunk"
#define BLOCK_SIZE 16
#define ROUNDS 8
#define MASK 0x0f

// Function prototypes
void encrypt(char *text, int length);
void decrypt(char *text, int length);

int main() {
    char *message = "Hello, world!";
    int message_length = strlen(message);

    encrypt(message, message_length);

    printf("Encrypted message: %s\n", message);

    decrypt(message, message_length);

    printf("Decrypted message: %s\n", message);

    return 0;
}

// Encryption function
void encrypt(char *text, int length) {
    char *key = KEY;
    int key_length = strlen(key);
    int i, j, k;

    for (i = 0; i < length; i += BLOCK_SIZE) {
        for (j = 0; j < BLOCK_SIZE && i + j < length; j++) {
            text[i + j] ^= key[j % key_length];
        }

        for (k = 0; k < ROUNDS; k++) {
            text[i + k] = (text[i + k] >> 1) | ((text[i + k] & 1) << 3);
        }
    }
}

// Decryption function
void decrypt(char *text, int length) {
    char *key = KEY;
    int key_length = strlen(key);
    int i, j, k;

    for (i = 0; i < length; i += BLOCK_SIZE) {
        for (j = 0; j < BLOCK_SIZE && i + j < length; j++) {
            text[i + j] ^= key[j % key_length];
        }

        for (k = 0; k < ROUNDS; k++) {
            text[i + k] = (text[i + k] << 1) | ((text[i + k] >> 3) & 1);
        }
    }
}