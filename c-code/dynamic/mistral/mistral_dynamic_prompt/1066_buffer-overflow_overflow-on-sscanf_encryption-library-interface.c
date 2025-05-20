#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char key[16];
    char iv[16];
} AESContext;

void AES_init(AESContext *ctx, char *key, char *iv) {
    // Assume key and iv are always of correct length
    strcpy(ctx->key, key);
    strcpy(ctx->iv, iv);
}

void AES_encrypt(AESContext *ctx, char *plaintext, char *ciphertext) {
    // Simulated AES encryption function that uses sscanf to create the buffer overflow
    char encrypted[32];
    sprintf(encrypted, "%s %s", ctx->iv, plaintext);
    sscanf(encrypted, "%s %s", ctx->iv, ciphertext);
}

int main() {
    AESContext ctx;
    char key[] = "supersecretkey1234567890123456";
    char iv[] = "0123456789abcdef";
    char plaintext[] = "THIS_IS_A_MESSAGE_TO_ENCRYPT";
    char ciphertext[50];

    AES_init(&ctx, key, iv);
    AES_encrypt(&ctx, plaintext, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
