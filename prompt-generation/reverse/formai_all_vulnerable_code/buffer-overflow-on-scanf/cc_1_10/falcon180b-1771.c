//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH (16)
#define MAX_BLOCK_LENGTH (1024)

typedef struct {
    int mode;
    int key_length;
    char key[MAX_KEY_LENGTH];
    char iv[MAX_KEY_LENGTH];
} crypt_ctx;

void crypt_encrypt(crypt_ctx *ctx, char *in_buf, char *out_buf) {
    int i, j, n;
    char temp;

    if (ctx->mode == 1) {
        // ECB mode
        for (i = 0; i < strlen(in_buf); i++) {
            temp = in_buf[i];

            for (j = 0; j < ctx->key_length; j++) {
                temp = temp ^ ctx->key[j];
            }

            out_buf[i] = temp;
        }
    } else if (ctx->mode == 2) {
        // CBC mode
        char prev_block[MAX_BLOCK_LENGTH];
        memset(prev_block, 0, MAX_BLOCK_LENGTH);

        for (i = 0; i < strlen(in_buf); i += ctx->key_length) {
            memcpy(prev_block, in_buf + i - ctx->key_length, ctx->key_length);

            for (j = 0; j < ctx->key_length; j++) {
                temp = in_buf[i + j];
                temp = temp ^ prev_block[j];
                out_buf[i + j] = temp;
            }
        }
    } else {
        // Invalid mode
        printf("Invalid mode\n");
        exit(1);
    }
}

void crypt_decrypt(crypt_ctx *ctx, char *in_buf, char *out_buf) {
    crypt_encrypt(ctx, in_buf, out_buf);
}

int main() {
    crypt_ctx ctx;
    char key[MAX_KEY_LENGTH];
    char iv[MAX_KEY_LENGTH];
    char in_buf[MAX_BLOCK_LENGTH];
    char out_buf[MAX_BLOCK_LENGTH];

    printf("Enter the key length (up to %d): ", MAX_KEY_LENGTH - 1);
    scanf("%d", &(ctx.key_length));

    printf("Enter the key: ");
    scanf("%s", key);

    printf("Enter the initialization vector: ");
    scanf("%s", iv);

    printf("Enter the mode (1 for ECB, 2 for CBC): ");
    scanf("%d", &(ctx.mode));

    printf("Enter the message to encrypt: ");
    scanf("%s", in_buf);

    crypt_encrypt(&ctx, in_buf, out_buf);

    printf("Encrypted message: %s\n", out_buf);

    crypt_decrypt(&ctx, out_buf, in_buf);

    printf("Decrypted message: %s\n", in_buf);

    return 0;
}