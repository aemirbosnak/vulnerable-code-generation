//Falcon-180B DATASET v1.0 Category: Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 40
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    int mode;
} EncryptionContext;

// Initialize encryption context
void init_encryption_context(EncryptionContext *ctx, char *key, int key_length, int mode) {
    strncpy(ctx->key, key, MAX_KEY_LENGTH);
    ctx->key_length = key_length;
    ctx->mode = mode;
}

// Encrypt message using Caesar cipher
void caesar_encrypt(EncryptionContext *ctx, char *message) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; ++i, ++j) {
        if (isalpha(message[i])) {
            char c = message[i];
            if (isupper(c)) {
                c = tolower(c);
            }
            c = (c + ctx->key_length - 65) % 26 + 65;
            if (isupper(c)) {
                c = toupper(c);
            }
            message[i] = c;
        }
        else {
            message[i] = message[i];
        }
    }
}

// Decrypt message using Caesar cipher
void caesar_decrypt(EncryptionContext *ctx, char *message) {
    int i, j;
    for (i = 0, j = 0; message[i]!= '\0'; ++i, ++j) {
        if (isalpha(message[i])) {
            char c = message[i];
            if (isupper(c)) {
                c = tolower(c);
            }
            c = (c + 'z' - ctx->key_length) % 26 + 'a';
            if (isupper(c)) {
                c = toupper(c);
            }
            message[i] = c;
        }
        else {
            message[i] = message[i];
        }
    }
}

int main() {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    int key_length;
    int mode;

    // Get key from user
    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key_length = strlen(key);

    // Get encryption mode from user
    printf("Enter encryption mode (0 for Caesar cipher, 1 for Vigenere cipher): ");
    scanf("%d", &mode);

    // Initialize encryption context
    EncryptionContext ctx;
    init_encryption_context(&ctx, key, key_length, mode);

    // Get message from user
    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);

    // Encrypt message
    caesar_encrypt(&ctx, message);

    // Print encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}