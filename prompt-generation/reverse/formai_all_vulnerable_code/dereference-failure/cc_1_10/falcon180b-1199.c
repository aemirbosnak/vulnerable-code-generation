//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BLOCK_SIZE 8
#define KEY_SIZE 16
#define ROUNDS 10

void encrypt(char *message, char *key) {
    int i, j;
    int message_len = strlen(message);
    int key_len = strlen(key);
    char *expanded_key = malloc(message_len * KEY_SIZE);
    char *cipher_text = malloc(message_len * BLOCK_SIZE);

    for (i = 0; i < message_len; i++) {
        cipher_text[i] = message[i];
    }

    for (i = 0; i < message_len; i++) {
        for (j = 0; j < ROUNDS; j++) {
            cipher_text[i] ^= expanded_key[i * KEY_SIZE + j % key_len];
        }
    }

    printf("Encrypted message: ");
    for (i = 0; i < message_len; i++) {
        printf("%c", cipher_text[i]);
    }
    printf("\n");

    free(cipher_text);
    free(expanded_key);
}

void decrypt(char *cipher_text, char *key) {
    int i, j;
    int message_len = strlen(cipher_text);
    int key_len = strlen(key);
    char *expanded_key = malloc(message_len * KEY_SIZE);
    char *message = malloc(message_len * BLOCK_SIZE);

    for (i = 0; i < message_len; i++) {
        message[i] = cipher_text[i];
    }

    for (i = 0; i < message_len; i++) {
        for (j = 0; j < ROUNDS; j++) {
            message[i] ^= expanded_key[i * KEY_SIZE + j % key_len];
        }
    }

    printf("Decrypted message: ");
    for (i = 0; i < message_len; i++) {
        printf("%c", message[i]);
    }
    printf("\n");

    free(message);
    free(expanded_key);
}

int main() {
    char *message = "Hello, world!";
    char *key = "mysecretkey123";

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}