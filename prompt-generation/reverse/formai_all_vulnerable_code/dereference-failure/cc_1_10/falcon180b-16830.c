//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char* key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char* message, char* key, char* encrypted_message, int message_size) {
    int i = 0;
    int j = 0;
    while (i < message_size) {
        char block[BLOCK_SIZE] = {0};
        strncat(block, message + i, BLOCK_SIZE);
        for (int k = 0; k < BLOCK_SIZE; k++) {
            encrypted_message[j++] = block[k] ^ key[k];
        }
        i += BLOCK_SIZE;
    }
}

void decrypt(char* encrypted_message, char* key, char* message, int message_size) {
    int i = 0;
    int j = 0;
    while (i < message_size) {
        char block[BLOCK_SIZE] = {0};
        strncat(block, encrypted_message + i, BLOCK_SIZE);
        for (int k = 0; k < BLOCK_SIZE; k++) {
            message[j++] = block[k] ^ key[k];
        }
        i += BLOCK_SIZE;
    }
}

int main() {
    char key[KEY_SIZE] = {0};
    generate_key(key, KEY_SIZE);

    char message[100] = "Hello, World!";
    char encrypted_message[100] = {0};
    char decrypted_message[100] = {0};

    int message_size = strlen(message);
    encrypt(message, key, encrypted_message, message_size);

    printf("Encrypted message: %s\n", encrypted_message);

    decrypt(encrypted_message, key, decrypted_message, message_size);

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}