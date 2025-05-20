//Falcon-180B DATASET v1.0 Category: Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 256
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    int num_rounds;
} EncryptionContext;

void generate_key(char key[], int key_length) {
    for (int i = 0; i < key_length; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt_message(char message[], int message_length, EncryptionContext context) {
    char encrypted_message[MAX_MESSAGE_LENGTH];
    int encrypted_message_length = 0;

    for (int i = 0; i < message_length; i++) {
        encrypted_message[encrypted_message_length] = message[i] ^ context.key[i % context.key_length];
        encrypted_message_length++;
    }

    memcpy(message, encrypted_message, encrypted_message_length);
    message_length = encrypted_message_length;
}

void decrypt_message(char message[], int message_length, EncryptionContext context) {
    char decrypted_message[MAX_MESSAGE_LENGTH];
    int decrypted_message_length = 0;

    for (int i = 0; i < message_length; i++) {
        decrypted_message[decrypted_message_length] = message[i] ^ context.key[i % context.key_length];
        decrypted_message_length++;
    }

    memcpy(message, decrypted_message, decrypted_message_length);
    message_length = decrypted_message_length;
}

int main() {
    EncryptionContext context;
    char message[MAX_MESSAGE_LENGTH];
    int message_length;

    printf("Enter message: ");
    scanf("%s", message);
    message_length = strlen(message);

    generate_key(context.key, MAX_KEY_LENGTH);
    context.key_length = strlen(context.key);
    context.num_rounds = 5;

    encrypt_message(message, message_length, context);
    printf("Encrypted message: %s\n", message);

    decrypt_message(message, message_length, context);
    printf("Decrypted message: %s\n", message);

    return 0;
}