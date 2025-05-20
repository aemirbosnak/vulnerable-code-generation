//Falcon-180B DATASET v1.0 Category: Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100
#define MAX_INPUT_LENGTH 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char input[MAX_INPUT_LENGTH];
    char output[MAX_INPUT_LENGTH + 1];
} EncryptionContext;

void generate_key(EncryptionContext* ctx) {
    for (int i = 0; i < MAX_KEY_LENGTH; i++) {
        ctx->key[i] = rand() % 26 + 'a';
    }
    ctx->key[MAX_KEY_LENGTH - 1] = '\0';
}

void encrypt(EncryptionContext* ctx) {
    int input_length = strlen(ctx->input);
    int key_length = strlen(ctx->key);

    for (int i = 0; i < input_length; i++) {
        char input_char = toupper(ctx->input[i]);
        char key_char = toupper(ctx->key[i % key_length]);

        if (isalpha(input_char)) {
            ctx->output[i] = (input_char + key_char - 'A') % 26 + 'A';
        } else {
            ctx->output[i] = input_char;
        }
    }

    ctx->output[input_length] = '\0';
}

void decrypt(EncryptionContext* ctx) {
    int input_length = strlen(ctx->input);
    int key_length = strlen(ctx->key);

    for (int i = 0; i < input_length; i++) {
        char input_char = toupper(ctx->input[i]);
        char key_char = toupper(ctx->key[i % key_length]);

        if (isalpha(input_char)) {
            ctx->output[i] = (input_char - key_char + 26) % 26 + 'A';
        } else {
            ctx->output[i] = input_char;
        }
    }

    ctx->output[input_length] = '\0';
}

int main() {
    EncryptionContext ctx;

    generate_key(&ctx);

    printf("Enter message to encrypt: ");
    scanf("%s", ctx.input);

    printf("Encrypted message: %s\n", ctx.output);

    printf("Enter encrypted message to decrypt: ");
    scanf("%s", ctx.input);

    printf("Decrypted message: %s\n", ctx.output);

    return 0;
}