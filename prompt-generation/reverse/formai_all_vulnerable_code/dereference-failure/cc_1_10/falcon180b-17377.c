//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define HASH_SIZE 64
#define BLOCK_SIZE 64
#define ROUNDS 80

typedef struct {
    unsigned char state[64];
    unsigned int hash[5];
    unsigned int hash_size;
    unsigned int index;
} hash_ctx;

void hash_init(hash_ctx *ctx, unsigned int hash_size) {
    ctx->hash_size = hash_size;
    ctx->index = 0;
    memset(ctx->state, 0, sizeof(ctx->state));
    memset(ctx->hash, 0, sizeof(ctx->hash));
}

void hash_update(hash_ctx *ctx, const void *data, size_t len) {
    const unsigned char *buf = data;
    size_t remaining = len;

    while (remaining >= BLOCK_SIZE) {
        SHA256_Update(&ctx->state, buf, BLOCK_SIZE);
        buf += BLOCK_SIZE;
        remaining -= BLOCK_SIZE;
    }

    if (remaining > 0) {
        memset(ctx->state + remaining, 0, BLOCK_SIZE - remaining);
        SHA256_Update(&ctx->state, buf, remaining);
    }
}

void hash_final(hash_ctx *ctx, void *hash) {
    unsigned char padding[BLOCK_SIZE];
    size_t padding_len = BLOCK_SIZE - ctx->index;
    memset(padding, 0x80, padding_len);
    memset(padding + padding_len, 0, BLOCK_SIZE - padding_len - 8);
    SHA256_Update(&ctx->state, padding, BLOCK_SIZE);
    SHA256_Final(ctx->hash, &ctx->state);
    memcpy(hash, ctx->hash, ctx->hash_size);
}

int main() {
    unsigned char message[] = "Hello, world!";
    unsigned char hash[HASH_SIZE];
    hash_ctx ctx;

    hash_init(&ctx, HASH_SIZE);
    hash_update(&ctx, message, strlen(message));
    hash_final(&ctx, hash);

    printf("SHA-256 hash of \"%s\": ", message);
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}