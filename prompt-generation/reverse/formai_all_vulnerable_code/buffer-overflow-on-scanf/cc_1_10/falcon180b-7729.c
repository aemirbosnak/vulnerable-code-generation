//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 256
#define MAX_PLAIN_TEXT_SIZE 1024
#define MAX_CIPHER_TEXT_SIZE (MAX_PLAIN_TEXT_SIZE + 1)

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
    int mode;
} encryption_context_t;

void generate_key(char* key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

int main() {
    encryption_context_t ctx;
    ctx.key_size = 0;
    ctx.mode = 0;

    char plain_text[MAX_PLAIN_TEXT_SIZE];
    printf("Enter plain text: ");
    fgets(plain_text, MAX_PLAIN_TEXT_SIZE, stdin);
    int plain_text_size = strlen(plain_text);

    printf("Enter encryption key: ");
    scanf("%s", ctx.key);
    ctx.key_size = strlen(ctx.key);

    int cipher_text_size = plain_text_size + ctx.key_size % plain_text_size;
    char cipher_text[MAX_CIPHER_TEXT_SIZE];

    if (ctx.mode == 0) {
        printf("Encrypting...\n");
        for (int i = 0; i < plain_text_size; i++) {
            cipher_text[i] = plain_text[i] ^ ctx.key[i % ctx.key_size];
        }
        for (int i = plain_text_size; i < cipher_text_size; i++) {
            cipher_text[i] = ctx.key[(i - plain_text_size) % ctx.key_size];
        }
    } else {
        printf("Decrypting...\n");
        for (int i = 0; i < plain_text_size; i++) {
            cipher_text[i] = plain_text[i] ^ ctx.key[i % ctx.key_size];
        }
        for (int i = plain_text_size; i < cipher_text_size; i++) {
            cipher_text[i] = ctx.key[(i - plain_text_size) % ctx.key_size];
        }
    }

    printf("Cipher text: %s\n", cipher_text);

    return 0;
}