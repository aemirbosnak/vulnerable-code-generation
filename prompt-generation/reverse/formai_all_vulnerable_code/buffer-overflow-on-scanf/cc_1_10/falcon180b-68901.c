//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_LENGTH 100
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
} EncryptionContext;

void generateRandomKey(char* key) {
    for (int i = 0; i < strlen(key); i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encryptMessage(EncryptionContext* ctx) {
    int keyIndex = 0;
    int messageIndex = 0;
    while (ctx->message[messageIndex]) {
        if (ctx->message[messageIndex] >= 'a' && ctx->message[messageIndex] <= 'z') {
            ctx->message[messageIndex] = ctx->key[keyIndex % strlen(ctx->key)] + ctx->message[messageIndex] - 'a' + 'a';
            keyIndex++;
        } else if (ctx->message[messageIndex] >= 'A' && ctx->message[messageIndex] <= 'Z') {
            ctx->message[messageIndex] = ctx->key[keyIndex % strlen(ctx->key)] + ctx->message[messageIndex] - 'A' + 'a';
            keyIndex++;
        } else {
            ctx->message[messageIndex] = ctx->message[messageIndex];
        }
        messageIndex++;
    }
}

void decryptMessage(EncryptionContext* ctx) {
    int keyIndex = 0;
    int messageIndex = 0;
    while (ctx->message[messageIndex]) {
        if (ctx->message[messageIndex] >= 'a' && ctx->message[messageIndex] <= 'z') {
            ctx->message[messageIndex] = ctx->key[keyIndex % strlen(ctx->key)] - ctx->message[messageIndex] + 'a';
            keyIndex++;
        } else if (ctx->message[messageIndex] >= 'A' && ctx->message[messageIndex] <= 'Z') {
            ctx->message[messageIndex] = ctx->key[keyIndex % strlen(ctx->key)] - ctx->message[messageIndex] + 'A';
            keyIndex++;
        } else {
            ctx->message[messageIndex] = ctx->message[messageIndex];
        }
        messageIndex++;
    }
}

int main() {
    srand(time(NULL));
    EncryptionContext ctx;
    printf("Enter the key: ");
    scanf("%s", ctx.key);
    printf("Enter the message: ");
    scanf("%s", ctx.message);
    generateRandomKey(ctx.key);
    encryptMessage(&ctx);
    printf("Encrypted message: %s\n", ctx.message);
    decryptMessage(&ctx);
    printf("Decrypted message: %s\n", ctx.message);
    return 0;
}