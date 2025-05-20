//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 8
#define ROUNDS 16

void generate_key(char key[KEY_LENGTH]) {
    time_t t;
    time(&t);
    srand(t);

    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

void encrypt(char message[BLOCK_SIZE], char key[KEY_LENGTH]) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        int j = (i + 1) % BLOCK_SIZE;
        char temp = message[i];
        message[i] = message[j];
        message[j] = temp;
    }

    for (int i = 0; i < ROUNDS; i++) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            message[j] = (message[j] + key[i * (j % KEY_LENGTH)]) % 26 + 'A';
        }
    }
}

void decrypt(char cipher[BLOCK_SIZE], char key[KEY_LENGTH]) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        int j = (i + 1) % BLOCK_SIZE;
        char temp = cipher[i];
        cipher[i] = cipher[j];
        cipher[j] = temp;
    }

    for (int i = ROUNDS - 1; i >= 0; i--) {
        for (int j = 0; j < BLOCK_SIZE; j++) {
            cipher[j] = (cipher[j] - key[i * (j % KEY_LENGTH)]) % 26 + 'A';
        }
    }
}

int main() {
    char message[BLOCK_SIZE];
    char key[KEY_LENGTH];

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    generate_key(key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}