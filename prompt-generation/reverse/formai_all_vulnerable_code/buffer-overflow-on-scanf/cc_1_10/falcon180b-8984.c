//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 32
#define MAX_BLOCK_SIZE 16
#define MAX_ROUNDS 10000

typedef struct {
    char key[MAX_KEY_LENGTH + 1];
    int key_length;
    int rounds;
} encryption_ctx;

void generate_key(encryption_ctx* ctx) {
    char key[MAX_KEY_LENGTH + 1];
    int key_length;

    printf("Enter key length (between 1 and %d): ", MAX_KEY_LENGTH);
    scanf("%d", &key_length);

    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 26 + 'a';
    }

    key[key_length] = '\0';
    strcpy(ctx->key, key);
    ctx->key_length = key_length;
}

void encrypt_block(encryption_ctx* ctx, char* block) {
    int i;
    char key[MAX_KEY_LENGTH + 1];
    strcpy(key, ctx->key);

    for (i = 0; i < ctx->rounds; i++) {
        int j = 0;
        while (j < strlen(block)) {
            if (block[j] >= 'a' && block[j] <= 'z') {
                block[j] = (block[j] - 'a' + ctx->key_length) % 26 + 'a';
            } else if (block[j] >= 'A' && block[j] <= 'Z') {
                block[j] = (block[j] - 'A' + ctx->key_length) % 26 + 'a';
            }
            j++;
        }
    }
}

int main() {
    encryption_ctx ctx;

    printf("Enter key length (between 1 and %d): ", MAX_KEY_LENGTH);
    scanf("%d", &ctx.key_length);

    ctx.key[ctx.key_length] = '\0';
    printf("Enter key: ");
    scanf("%s", ctx.key);

    printf("Enter number of rounds: ");
    scanf("%d", &ctx.rounds);

    char block[MAX_BLOCK_SIZE];
    printf("Enter block to encrypt: ");
    scanf("%s", block);

    encrypt_block(&ctx, block);

    printf("Encrypted block: %s\n", block);

    return 0;
}