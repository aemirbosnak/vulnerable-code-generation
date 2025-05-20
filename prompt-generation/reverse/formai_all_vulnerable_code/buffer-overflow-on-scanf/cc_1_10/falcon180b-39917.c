//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_MESSAGE_SIZE 1024

typedef struct {
    char key[MAX_KEY_SIZE];
    int keySize;
    int messageSize;
    char message[MAX_MESSAGE_SIZE];
} EncryptionContext;

EncryptionContext *createEncryptionContext(char *key, int keySize, int messageSize) {
    EncryptionContext *context = (EncryptionContext *) malloc(sizeof(EncryptionContext));
    strncpy(context->key, key, keySize);
    context->keySize = keySize;
    context->messageSize = messageSize;
    context->message[0] = '\0';
    return context;
}

void destroyEncryptionContext(EncryptionContext *context) {
    free(context);
}

void encrypt(EncryptionContext *context) {
    int i, j;
    for (i = 0, j = 0; i < context->messageSize; i++) {
        if (isalpha(context->message[i])) {
            context->message[i] = tolower(context->message[i]);
            context->message[i] = context->message[i] + (context->key[j] % 26);
            j = (j + 1) % context->keySize;
        }
    }
}

void decrypt(EncryptionContext *context) {
    int i, j;
    for (i = 0, j = 0; i < context->messageSize; i++) {
        if (isalpha(context->message[i])) {
            context->message[i] = tolower(context->message[i]);
            context->message[i] = context->message[i] - (context->key[j] % 26);
            j = (j + 1) % context->keySize;
        }
    }
}

int main() {
    EncryptionContext *context;
    char *key, *message;
    int keySize, messageSize;

    printf("Enter key size (1-32): ");
    scanf("%d", &keySize);
    if (keySize < 1 || keySize > MAX_KEY_SIZE) {
        printf("Invalid key size.\n");
        return 1;
    }

    printf("Enter key: ");
    scanf(" %[^\n]", key);
    keySize = strlen(key);

    printf("Enter message size (1-%d): ", MAX_MESSAGE_SIZE);
    scanf("%d", &messageSize);
    if (messageSize < 1 || messageSize > MAX_MESSAGE_SIZE) {
        printf("Invalid message size.\n");
        return 1;
    }

    printf("Enter message: ");
    scanf(" %[^\n]", message);
    messageSize = strlen(message);

    context = createEncryptionContext(key, keySize, messageSize);
    strncpy(context->message, message, messageSize);

    printf("Encrypted message:\n%s\n", context->message);
    encrypt(context);
    printf("Decrypted message:\n%s\n", context->message);

    destroyEncryptionContext(context);

    return 0;
}