//Falcon-180B DATASET v1.0 Category: Encryption ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 64
#define MAX_BLOCK_SIZE 64

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
} encryption_context;

void generate_random_key(char* key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(encryption_context* ctx, char* plaintext, char* ciphertext) {
    int i, j, k;
    for (i = 0, j = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                plaintext[i] = tolower(plaintext[i]);
            }
            ciphertext[j++] = plaintext[i] ^ ctx->key[i % ctx->key_size];
        } else {
            ciphertext[j++] = plaintext[i];
        }
    }
    ciphertext[j] = '\0';
}

int main() {
    encryption_context ctx;
    char plaintext[MAX_BLOCK_SIZE];
    char ciphertext[MAX_BLOCK_SIZE];
    char key[MAX_KEY_SIZE];

    printf("Enter a message to encrypt: ");
    scanf("%s", plaintext);

    printf("Enter a key (up to %d characters): ", MAX_KEY_SIZE - 1);
    scanf("%s", key);

    ctx.key_size = strlen(key);
    generate_random_key(ctx.key, ctx.key_size);

    printf("Encrypted message: %s\n", plaintext);
    encrypt(&ctx, plaintext, ciphertext);
    printf("Encrypted message: %s\n", ciphertext);

    return 0;
}