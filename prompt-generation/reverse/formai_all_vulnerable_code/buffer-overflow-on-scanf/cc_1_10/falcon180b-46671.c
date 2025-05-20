//Falcon-180B DATASET v1.0 Category: Encryption ; Style: protected
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_KEY_SIZE 32
#define MAX_PLAIN_TEXT_SIZE 1024
#define MAX_CIPHER_TEXT_SIZE (MAX_PLAIN_TEXT_SIZE + 1)

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
    char plain_text[MAX_PLAIN_TEXT_SIZE];
    char cipher_text[MAX_CIPHER_TEXT_SIZE];
} encryption_context;

void init_key(encryption_context* ctx, const char* key) {
    int i;
    for (i = 0; i < strlen(key); i++) {
        ctx->key[i] = tolower(key[i]);
    }
    ctx->key_size = strlen(key);
}

void encrypt(encryption_context* ctx) {
    int i, j;
    for (i = 0, j = 0; i < ctx->key_size; i++) {
        ctx->cipher_text[j++] = ctx->key[i];
    }
    ctx->cipher_text[j] = '\0';
    for (i = 0; i < strlen(ctx->plain_text); i++) {
        ctx->cipher_text[i + ctx->key_size] = ctx->plain_text[i];
    }
}

void decrypt(encryption_context* ctx) {
    int i, j;
    for (i = 0, j = 0; i < ctx->key_size; i++) {
        ctx->plain_text[i] = ctx->key[i];
    }
    ctx->plain_text[i] = '\0';
    for (i = 0; i < strlen(ctx->cipher_text); i++) {
        ctx->plain_text[i + ctx->key_size] = ctx->cipher_text[i];
    }
}

int main() {
    encryption_context ctx;
    char key[MAX_KEY_SIZE];
    char plain_text[MAX_PLAIN_TEXT_SIZE];
    char cipher_text[MAX_CIPHER_TEXT_SIZE];

    printf("Enter key: ");
    scanf("%s", key);

    init_key(&ctx, key);

    printf("Enter plain text: ");
    scanf("%s", plain_text);

    encrypt(&ctx);

    printf("Encrypted text: %s\n", ctx.cipher_text);

    decrypt(&ctx);

    printf("Decrypted text: %s\n", ctx.plain_text);

    return 0;
}