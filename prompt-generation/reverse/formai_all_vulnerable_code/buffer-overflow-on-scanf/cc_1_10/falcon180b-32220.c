//Falcon-180B DATASET v1.0 Category: Encryption ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_TEXT_SIZE 256

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
    char text[MAX_TEXT_SIZE];
    int text_size;
} EncryptionContext;

void generate_key(char* key, int key_size) {
    char alphanumeric[62] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int i;

    for (i = 0; i < key_size; i++) {
        key[i] = alphanumeric[rand() % 62];
    }

    key[key_size] = '\0';
}

void encrypt(EncryptionContext* ctx) {
    int i, j;

    for (i = 0, j = 0; i < ctx->text_size; i++) {
        if (isalpha(ctx->text[i])) {
            ctx->text[i] = (ctx->text[i] - 'A' + ctx->key[j]) % 26 + 'A';
            j = (j + 1) % ctx->key_size;
        } else {
            ctx->text[i] = ctx->text[i];
        }
    }
}

void decrypt(EncryptionContext* ctx) {
    int i, j;

    for (i = 0, j = 0; i < ctx->text_size; i++) {
        if (isalpha(ctx->text[i])) {
            ctx->text[i] = (ctx->text[i] - ctx->key[j] + 26) % 26 + 'A';
            j = (j + 1) % ctx->key_size;
        } else {
            ctx->text[i] = ctx->text[i];
        }
    }
}

int main() {
    EncryptionContext ctx;
    char key[MAX_KEY_SIZE];
    char text[MAX_TEXT_SIZE];

    printf("Enter the key (up to %d characters): ", MAX_KEY_SIZE - 1);
    scanf("%s", key);

    ctx.key_size = strlen(key);
    generate_key(ctx.key, ctx.key_size);

    printf("Enter the text to encrypt (up to %d characters): ", MAX_TEXT_SIZE - 1);
    scanf("%s", text);

    ctx.text_size = strlen(text);
    strcpy(ctx.text, text);

    encrypt(&ctx);

    printf("Encrypted text: %s\n", ctx.text);

    decrypt(&ctx);

    printf("Decrypted text: %s\n", ctx.text);

    return 0;
}