//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 64
#define MAX_INPUT_LENGTH 1024
#define MAX_OUTPUT_LENGTH 1024

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    char input[MAX_INPUT_LENGTH];
    int input_length;
    char output[MAX_OUTPUT_LENGTH];
    int output_length;
} EncryptionContext;

void generate_key(EncryptionContext* ctx, int key_length) {
    char* chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;:,.<>?";
    for (int i = 0; i < key_length; i++) {
        ctx->key[i] = chars[rand() % strlen(chars)];
    }
    ctx->key_length = key_length;
}

void encrypt(EncryptionContext* ctx) {
    for (int i = 0; i < ctx->input_length; i++) {
        ctx->output[i] = ctx->input[i] ^ ctx->key[i % ctx->key_length];
    }
    ctx->output_length = ctx->input_length;
}

void decrypt(EncryptionContext* ctx) {
    for (int i = 0; i < ctx->output_length; i++) {
        ctx->input[i] = ctx->output[i] ^ ctx->key[i % ctx->key_length];
    }
    ctx->input_length = ctx->output_length;
}

int main() {
    EncryptionContext ctx;
    printf("Enter a key: ");
    scanf("%s", ctx.key);
    ctx.key_length = strlen(ctx.key);

    printf("Enter input text: ");
    scanf("%s", ctx.input);
    ctx.input_length = strlen(ctx.input);

    generate_key(&ctx, ctx.key_length);

    printf("Encrypting...\n");
    encrypt(&ctx);

    printf("Encrypted text: ");
    for (int i = 0; i < ctx.output_length; i++) {
        printf("%c", ctx.output[i]);
    }
    printf("\n");

    printf("Decrypting...\n");
    decrypt(&ctx);

    printf("Decrypted text: ");
    for (int i = 0; i < ctx.input_length; i++) {
        printf("%c", ctx.input[i]);
    }
    printf("\n");

    return 0;
}