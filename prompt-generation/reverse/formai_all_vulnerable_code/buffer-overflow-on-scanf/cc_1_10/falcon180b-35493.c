//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

typedef struct {
    char key[KEY_SIZE];
    unsigned int rounds;
} encryption_params;

void encrypt(char *message, encryption_params *params) {
    int message_len = strlen(message);
    char *encrypted_message = malloc(message_len + 1);

    char *key = params->key;
    int key_len = strlen(key);
    int i;

    for (i = 0; i < message_len; i++) {
        encrypted_message[i] = message[i] ^ key[i % key_len];
    }

    int rounds = params->rounds;
    for (i = 0; i < rounds; i++) {
        int j;
        for (j = 0; j < message_len; j++) {
            encrypted_message[j] = encrypted_message[j] ^ (encrypted_message[(j + 1) % message_len]);
        }
    }

    encrypted_message[message_len] = '\0';

    printf("Encrypted message: %s\n", encrypted_message);
    free(encrypted_message);
}

void decrypt(char *message, encryption_params *params) {
    int message_len = strlen(message);
    char *decrypted_message = malloc(message_len + 1);

    char *key = params->key;
    int key_len = strlen(key);
    int i;

    for (i = 0; i < message_len; i++) {
        decrypted_message[i] = message[i] ^ key[i % key_len];
    }

    int rounds = params->rounds;
    for (i = 0; i < rounds; i++) {
        int j;
        for (j = 0; j < message_len; j++) {
            decrypted_message[j] = decrypted_message[j] ^ (decrypted_message[(j + 1) % message_len]);
        }
    }

    decrypted_message[message_len] = '\0';

    printf("Decrypted message: %s\n", decrypted_message);
    free(decrypted_message);
}

int main() {
    encryption_params params;
    char message[100];
    char key[KEY_SIZE];
    int rounds;

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    printf("Enter encryption key: ");
    scanf("%s", key);

    printf("Enter number of rounds: ");
    scanf("%d", &rounds);

    strcpy(params.key, key);
    params.rounds = rounds;

    encrypt(message, &params);
    decrypt(message, &params);

    return 0;
}