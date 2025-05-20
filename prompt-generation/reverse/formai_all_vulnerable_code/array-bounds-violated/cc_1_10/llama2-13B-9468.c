//LLAMA2-13B DATASET v1.0 Category: Modern Encryption ; Style: dynamic
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 24

typedef struct {
    uint8_t key[KEY_SIZE];
    uint8_t iv[BLOCK_SIZE];
} context;

void init_context(context *ctx) {
    for (int i = 0; i < KEY_SIZE; i++) {
        ctx->key[i] = (uint8_t)rand();
    }
    for (int i = 0; i < BLOCK_SIZE; i++) {
        ctx->iv[i] = (uint8_t)rand();
    }
}

void encrypt(context *ctx, uint8_t *plaintext, uint8_t *ciphertext) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        uint8_t temp = plaintext[i] + ctx->iv[i];
        ciphertext[i] = temp % 256;
    }
}

void decrypt(context *ctx, uint8_t *ciphertext, uint8_t *plaintext) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        uint8_t temp = ciphertext[i] - ctx->iv[i];
        plaintext[i] = temp % 256;
    }
}

int main() {
    context ctx;
    uint8_t plaintext[] = "Hello, world!";
    uint8_t ciphertext[BLOCK_SIZE];

    init_context(&ctx);
    encrypt(&ctx, plaintext, ciphertext);
    decrypt(&ctx, ciphertext, plaintext);

    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", plaintext[i]);
    }
    printf("\n");

    return 0;
}