//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_KEY_LENGTH 64
#define MAX_BLOCK_LENGTH 16
#define MAX_ROUNDS 10000

void generate_key(char *key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

void encrypt(char *message, char *key, int rounds) {
    int message_length = strlen(message);
    int block_length = message_length / rounds;
    int remainder = message_length % rounds;

    for (int i = 0; i < rounds; i++) {
        for (int j = 0; j < block_length; j++) {
            message[i * block_length + j] = (message[i * block_length + j] + key[i % MAX_KEY_LENGTH]) % 26 + 'a';
        }
    }

    if (remainder > 0) {
        for (int j = 0; j < remainder; j++) {
            message[rounds * block_length + j] = (message[rounds * block_length + j] + key[rounds % MAX_KEY_LENGTH]) % 26 + 'a';
        }
    }
}

void decrypt(char *ciphertext, char *key, int rounds) {
    int ciphertext_length = strlen(ciphertext);
    int block_length = ciphertext_length / rounds;
    int remainder = ciphertext_length % rounds;

    for (int i = 0; i < rounds; i++) {
        for (int j = 0; j < block_length; j++) {
            ciphertext[i * block_length + j] = (ciphertext[i * block_length + j] - key[i % MAX_KEY_LENGTH]) % 26 + 'a';
        }
    }

    if (remainder > 0) {
        for (int j = 0; j < remainder; j++) {
            ciphertext[rounds * block_length + j] = (ciphertext[rounds * block_length + j] - key[rounds % MAX_KEY_LENGTH]) % 26 + 'a';
        }
    }
}

int main() {
    srand(time(NULL));
    char message[MAX_BLOCK_LENGTH];
    char ciphertext[MAX_BLOCK_LENGTH];
    char key[MAX_KEY_LENGTH];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    generate_key(key, MAX_KEY_LENGTH);
    encrypt(message, key, MAX_ROUNDS);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key, MAX_ROUNDS);
    printf("Decrypted message: %s\n", message);

    return 0;
}