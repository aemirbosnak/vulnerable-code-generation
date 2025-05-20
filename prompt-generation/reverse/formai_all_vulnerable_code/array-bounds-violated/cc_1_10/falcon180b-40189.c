//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 16

typedef struct {
    unsigned char key[MAX_KEY_SIZE];
    int key_size;
    unsigned char iv[MAX_KEY_SIZE];
} encryption_context;

void generate_random_key(unsigned char* key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 256;
    }
}

void generate_random_iv(unsigned char* iv, int iv_size) {
    for (int i = 0; i < iv_size; i++) {
        iv[i] = rand() % 256;
    }
}

void encrypt_message(encryption_context* ctx, unsigned char* message, int message_size) {
    unsigned char buffer[MAX_KEY_SIZE];
    int buffer_size = 0;

    for (int i = 0; i < message_size; i++) {
        unsigned char c = message[i];
        buffer[buffer_size++] = c ^ ctx->key[i % ctx->key_size];
    }

    for (int i = 0; i < ctx->key_size; i++) {
        buffer[buffer_size++] = ctx->iv[i];
    }

    for (int i = 0; i < buffer_size; i++) {
        message[i] = buffer[i];
    }
}

void decrypt_message(encryption_context* ctx, unsigned char* message, int message_size) {
    unsigned char buffer[MAX_KEY_SIZE];
    int buffer_size = 0;

    for (int i = 0; i < message_size; i++) {
        unsigned char c = message[i];
        buffer[buffer_size++] = c ^ ctx->iv[i % ctx->key_size];
    }

    for (int i = 0; i < ctx->key_size; i++) {
        buffer[buffer_size++] = ctx->key[i];
    }

    for (int i = 0; i < buffer_size; i++) {
        message[i] = buffer[i];
    }
}

int main() {
    encryption_context ctx;

    generate_random_key(ctx.key, MAX_KEY_SIZE);
    generate_random_iv(ctx.iv, MAX_KEY_SIZE);

    unsigned char message[] = "Hello, world! ";
    int message_size = strlen((char*)message);

    encrypt_message(&ctx, message, message_size);

    printf("Encrypted message: ");
    for (int i = 0; i < message_size; i++) {
        printf("%02x ", message[i]);
    }
    printf("\n");

    decrypt_message(&ctx, message, message_size);

    printf("Decrypted message: %s\n", message);

    return 0;
}