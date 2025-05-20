//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 1024
#define MAX_PLAIN_TEXT_LENGTH 1024

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    char plain_text[MAX_PLAIN_TEXT_LENGTH];
    int plain_text_length;
} CipherContext;

void generate_key(char* key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

void encrypt(CipherContext* ctx) {
    int i = 0, j = 0;
    while (i < ctx->plain_text_length) {
        ctx->plain_text[i] = toupper(ctx->plain_text[i]) - 'A' + ctx->key[j % ctx->key_length];
        i++;
        j++;
    }
}

void decrypt(CipherContext* ctx) {
    int i = 0, j = 0;
    while (i < ctx->plain_text_length) {
        ctx->plain_text[i] = ctx->key[j % ctx->key_length] + 'A' - toupper(ctx->plain_text[i]);
        i++;
        j++;
    }
}

int main() {
    CipherContext ctx;
    ctx.key_length = 0;
    ctx.plain_text_length = 0;

    printf("Enter the key: ");
    scanf("%s", ctx.key);
    ctx.key_length = strlen(ctx.key);

    printf("Enter the plain text: ");
    scanf("%s", ctx.plain_text);
    ctx.plain_text_length = strlen(ctx.plain_text);

    if (ctx.key_length == 0 || ctx.plain_text_length == 0) {
        printf("Error: Key or plain text is empty.\n");
        return 1;
    }

    printf("Encrypting...\n");
    encrypt(&ctx);
    printf("Encrypted text: %s\n", ctx.plain_text);

    printf("Decrypting...\n");
    decrypt(&ctx);
    printf("Decrypted text: %s\n", ctx.plain_text);

    return 0;
}