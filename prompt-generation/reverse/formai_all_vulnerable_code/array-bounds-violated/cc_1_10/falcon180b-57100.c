//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_KEY_LENGTH 64
#define MAX_MESSAGE_LENGTH 1024
#define NUM_ROUNDS 10000

typedef struct {
    int key_length;
    char key[MAX_KEY_LENGTH];
    int message_length;
    char message[MAX_MESSAGE_LENGTH];
} encryption_context;

void generate_key(encryption_context* ctx) {
    srand(time(NULL));
    for (int i = 0; i < ctx->key_length; i++) {
        ctx->key[i] = rand() % 26 + 'a';
    }
}

void encrypt(encryption_context* ctx) {
    for (int i = 0; i < ctx->message_length; i++) {
        ctx->message[i] = ctx->message[i] + ctx->key[i % ctx->key_length];
        if (isupper(ctx->message[i])) {
            ctx->message[i] = tolower(ctx->message[i]);
        }
    }
}

void decrypt(encryption_context* ctx) {
    for (int i = 0; i < ctx->message_length; i++) {
        ctx->message[i] = ctx->message[i] - ctx->key[i % ctx->key_length];
        if (islower(ctx->message[i])) {
            ctx->message[i] = toupper(ctx->message[i]);
        }
    }
}

int main() {
    encryption_context ctx;
    ctx.key_length = 0;
    ctx.message_length = 0;
    printf("Enter key length: ");
    scanf("%d", &ctx.key_length);
    printf("Enter message length: ");
    scanf("%d", &ctx.message_length);

    if (ctx.key_length > MAX_KEY_LENGTH || ctx.message_length > MAX_MESSAGE_LENGTH) {
        printf("Error: key/message length exceeds maximum limit.\n");
        return 1;
    }

    ctx.key[ctx.key_length - 1] = '\0';
    ctx.message[ctx.message_length - 1] = '\0';

    printf("Enter key: ");
    scanf("%s", ctx.key);
    printf("Enter message: ");
    scanf("%s", ctx.message);

    generate_key(&ctx);
    for (int i = 0; i < NUM_ROUNDS; i++) {
        encrypt(&ctx);
        decrypt(&ctx);
    }

    printf("Encrypted message: %s\n", ctx.message);

    return 0;
}