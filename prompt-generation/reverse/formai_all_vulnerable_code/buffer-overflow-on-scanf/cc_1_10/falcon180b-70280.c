//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_MESSAGE_SIZE 1024

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
    char message[MAX_MESSAGE_SIZE];
    int message_size;
} encryption_context;

void generate_key(char *key, int key_size) {
    srand(time(NULL));
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

void encrypt_message(encryption_context *ctx) {
    for (int i = 0; i < ctx->message_size; i++) {
        ctx->message[i] = ctx->message[i] + ctx->key[i % ctx->key_size];
        if (ctx->message[i] > 'z') {
            ctx->message[i] = ctx->message[i] - 26;
        } else if (ctx->message[i] < 'a') {
            ctx->message[i] = ctx->message[i] + 26;
        }
    }
}

void decrypt_message(encryption_context *ctx) {
    for (int i = 0; i < ctx->message_size; i++) {
        ctx->message[i] = ctx->message[i] - ctx->key[i % ctx->key_size];
        if (ctx->message[i] > 'z') {
            ctx->message[i] = ctx->message[i] - 26;
        } else if (ctx->message[i] < 'a') {
            ctx->message[i] = ctx->message[i] + 26;
        }
    }
}

int main() {
    encryption_context ctx;
    printf("Enter message to encrypt: ");
    fgets(ctx.message, MAX_MESSAGE_SIZE, stdin);
    ctx.message_size = strlen(ctx.message);

    printf("Enter key size (between 1 and %d): ", MAX_KEY_SIZE);
    scanf("%d", &ctx.key_size);
    ctx.key_size = ctx.key_size > MAX_KEY_SIZE? MAX_KEY_SIZE : ctx.key_size;

    generate_key(ctx.key, ctx.key_size);

    encrypt_message(&ctx);

    printf("Encrypted message: %s\n", ctx.message);

    decrypt_message(&ctx);

    printf("Decrypted message: %s\n", ctx.message);

    return 0;
}