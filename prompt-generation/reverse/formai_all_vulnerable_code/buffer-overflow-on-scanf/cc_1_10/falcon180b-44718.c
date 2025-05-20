//Falcon-180B DATASET v1.0 Category: Encryption ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000
#define ALPHABET_LENGTH 26

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    char message[MAX_MESSAGE_LENGTH];
    int message_length;
    char encrypted_message[MAX_MESSAGE_LENGTH];
    int encrypted_message_length;
} EncryptionContext;

void generate_random_key(char* key, int key_length) {
    srand(time(NULL));
    for (int i = 0; i < key_length; i++) {
        key[i] = 'a' + rand() % ALPHABET_LENGTH;
    }
    key[key_length] = '\0';
}

void encrypt_message(EncryptionContext* ctx) {
    for (int i = 0; i < ctx->message_length; i++) {
        if (ctx->message[i] >= 'a' && ctx->message[i] <= 'z') {
            ctx->encrypted_message[i] = ctx->message[i] + ctx->key[i % ctx->key_length] - 'a';
        } else {
            ctx->encrypted_message[i] = ctx->message[i];
        }
    }
    ctx->encrypted_message[ctx->message_length] = '\0';
    ctx->encrypted_message_length = ctx->message_length;
}

void decrypt_message(EncryptionContext* ctx) {
    for (int i = 0; i < ctx->encrypted_message_length; i++) {
        if (ctx->encrypted_message[i] >= 'a' && ctx->encrypted_message[i] <= 'z') {
            ctx->message[i] = ctx->encrypted_message[i] - ctx->key[i % ctx->key_length] + 'a';
        } else {
            ctx->message[i] = ctx->encrypted_message[i];
        }
    }
    ctx->message[ctx->encrypted_message_length] = '\0';
    ctx->message_length = ctx->encrypted_message_length;
}

int main() {
    EncryptionContext ctx;
    printf("Enter the message to be encrypted: ");
    scanf("%s", ctx.message);
    ctx.message_length = strlen(ctx.message);

    printf("Enter the encryption key: ");
    scanf("%s", ctx.key);
    ctx.key_length = strlen(ctx.key);

    generate_random_key(ctx.key, ctx.key_length);
    encrypt_message(&ctx);

    printf("Encrypted message: %s\n", ctx.encrypted_message);

    decrypt_message(&ctx);

    printf("Decrypted message: %s\n", ctx.message);

    return 0;
}