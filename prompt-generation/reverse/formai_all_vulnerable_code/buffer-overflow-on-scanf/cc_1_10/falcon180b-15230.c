//Falcon-180B DATASET v1.0 Category: Encryption ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 8
#define BLOCK_SIZE 8

void generate_key(char key[KEY_LENGTH]) {
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char message[BLOCK_SIZE], char key[KEY_LENGTH]) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        message[i] = toupper(message[i]);
        message[i] = (message[i] + key[i % KEY_LENGTH]) % 26 + 'a';
    }
}

void decrypt(char cipher[BLOCK_SIZE], char key[KEY_LENGTH]) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        cipher[i] = toupper(cipher[i]);
        cipher[i] = (cipher[i] - key[i % KEY_LENGTH] + 26) % 26 + 'a';
    }
}

int main() {
    char message[BLOCK_SIZE];
    char cipher[BLOCK_SIZE];
    char key[KEY_LENGTH];

    printf("Enter a message to encrypt: ");
    scanf("%8s", message);

    generate_key(key);

    encrypt(message, key);

    printf("Encrypted message: %s\n", message);

    strcpy(cipher, message);

    decrypt(cipher, key);

    printf("Decrypted message: %s\n", cipher);

    return 0;
}