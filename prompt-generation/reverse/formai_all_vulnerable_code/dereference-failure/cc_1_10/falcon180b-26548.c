//Falcon-180B DATASET v1.0 Category: Encryption ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 16
#define MAX_BLOCK_SIZE 16

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
    char iv[MAX_BLOCK_SIZE];
    int iv_size;
} encryption_context;

void set_key(encryption_context *ctx, char *key, int key_size) {
    strncpy(ctx->key, key, MAX_KEY_SIZE);
    ctx->key_size = key_size;
}

void set_iv(encryption_context *ctx, char *iv, int iv_size) {
    strncpy(ctx->iv, iv, MAX_BLOCK_SIZE);
    ctx->iv_size = iv_size;
}

void encrypt(encryption_context *ctx, char *plaintext, char *ciphertext) {
    int i, j;
    char key_expanded[MAX_KEY_SIZE + 1];
    for (i = 0, j = 0; i < ctx->key_size; i++) {
        key_expanded[i] = ctx->key[i];
        j++;
        if (j == ctx->key_size) {
            j = 0;
        }
    }
    key_expanded[ctx->key_size] = '\0';
    int key_index = 0;
    for (i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ key_expanded[key_index];
        key_index = (key_index + 1) % ctx->key_size;
    }
}

void decrypt(encryption_context *ctx, char *ciphertext, char *plaintext) {
    int i, j;
    char key_expanded[MAX_KEY_SIZE + 1];
    for (i = 0, j = 0; i < ctx->key_size; i++) {
        key_expanded[i] = ctx->key[i];
        j++;
        if (j == ctx->key_size) {
            j = 0;
        }
    }
    key_expanded[ctx->key_size] = '\0';
    int key_index = 0;
    for (i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = ciphertext[i] ^ key_expanded[key_index];
        key_index = (key_index + 1) % ctx->key_size;
    }
}

int main() {
    char key[] = "mysecretkey";
    int key_size = strlen(key);
    char iv[] = "1234567890123456";
    int iv_size = strlen(iv);
    encryption_context ctx;
    set_key(&ctx, key, key_size);
    set_iv(&ctx, iv, iv_size);
    char plaintext[] = "This is a secret message.";
    char ciphertext[MAX_BLOCK_SIZE];
    encrypt(&ctx, plaintext, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    char decrypted_text[MAX_BLOCK_SIZE];
    decrypt(&ctx, ciphertext, decrypted_text);
    printf("Decrypted text: %s\n", decrypted_text);
    return 0;
}