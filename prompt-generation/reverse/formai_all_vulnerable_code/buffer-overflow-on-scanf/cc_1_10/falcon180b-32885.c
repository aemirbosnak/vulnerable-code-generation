//Falcon-180B DATASET v1.0 Category: Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 256
#define MAX_MESSAGE_LENGTH 1000

void encrypt(char *key, char *message, char *result);
void decrypt(char *key, char *message, char *result);

int main() {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char result[MAX_MESSAGE_LENGTH];

    printf("Enter the encryption key: ");
    scanf("%s", key);

    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    encrypt(key, message, result);

    printf("Encrypted message: %s\n", result);

    printf("Enter the encrypted message to decrypt: ");
    scanf("%s", result);

    decrypt(key, result, message);

    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char *key, char *message, char *result) {
    int key_length = strlen(key);
    int message_length = strlen(message);
    int i, j;

    for (i = 0, j = 0; i < message_length; i++) {
        result[j++] = message[i] ^ key[i % key_length];
    }
}

void decrypt(char *key, char *message, char *result) {
    int key_length = strlen(key);
    int message_length = strlen(message);
    int i, j;

    for (i = 0, j = 0; i < message_length; i++) {
        result[j++] = message[i] ^ key[i % key_length];
    }
}