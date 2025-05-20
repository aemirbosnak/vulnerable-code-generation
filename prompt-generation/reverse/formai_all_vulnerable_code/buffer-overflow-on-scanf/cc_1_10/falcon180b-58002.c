//Falcon-180B DATASET v1.0 Category: Encryption ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 1024
#define MAX_MESSAGE_SIZE 1024

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
    char message[MAX_MESSAGE_SIZE];
    int message_size;
} EncryptionContext;

void generate_key(char* key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

void encrypt(EncryptionContext* context) {
    for (int i = 0; i < context->message_size; i++) {
        char message_char = context->message[i];
        char key_char = context->key[i % context->key_size];
        char encrypted_char = (char) ((message_char + key_char - 'a') % 26 + 'a');
        context->message[i] = encrypted_char;
    }
}

void decrypt(EncryptionContext* context) {
    for (int i = 0; i < context->message_size; i++) {
        char message_char = context->message[i];
        char key_char = context->key[i % context->key_size];
        char decrypted_char = (char) ((message_char - key_char + 26) % 26 + 'a');
        context->message[i] = decrypted_char;
    }
}

int main() {
    EncryptionContext context;
    char key[MAX_KEY_SIZE];
    char message[MAX_MESSAGE_SIZE];

    printf("Enter the message to be encrypted: ");
    scanf("%s", message);
    printf("Enter the key for encryption: ");
    scanf("%s", key);

    generate_key(key, strlen(key));
    context.key_size = strlen(key);
    context.message_size = strlen(message);
    strcpy(context.key, key);
    strcpy(context.message, message);

    encrypt(&context);

    printf("Encrypted message: %s\n", context.message);

    decrypt(&context);

    printf("Decrypted message: %s\n", context.message);

    return 0;
}