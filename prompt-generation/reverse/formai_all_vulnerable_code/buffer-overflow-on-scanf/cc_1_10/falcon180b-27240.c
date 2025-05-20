//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 8

void generate_key(char *key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_LENGTH] = '\0';
}

void encrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_index = 0;
    int block_count = message_length / BLOCK_SIZE;
    for (int i = 0; i < block_count; i++) {
        char block[BLOCK_SIZE];
        for (int j = 0; j < BLOCK_SIZE; j++) {
            block[j] = message[i * BLOCK_SIZE + j];
        }
        for (int j = 0; j < BLOCK_SIZE; j++) {
            block[j] = block[j] ^ key[key_index];
            key_index++;
            if (key_index == KEY_LENGTH) {
                key_index = 0;
            }
        }
        for (int j = 0; j < BLOCK_SIZE; j++) {
            message[i * BLOCK_SIZE + j] = block[j];
        }
    }
}

void decrypt(char *message, char *key) {
    int message_length = strlen(message);
    int key_index = 0;
    int block_count = message_length / BLOCK_SIZE;
    for (int i = 0; i < block_count; i++) {
        char block[BLOCK_SIZE];
        for (int j = 0; j < BLOCK_SIZE; j++) {
            block[j] = message[i * BLOCK_SIZE + j];
        }
        for (int j = 0; j < BLOCK_SIZE; j++) {
            block[j] = block[j] ^ key[key_index];
            key_index++;
            if (key_index == KEY_LENGTH) {
                key_index = 0;
            }
        }
        for (int j = 0; j < BLOCK_SIZE; j++) {
            message[i * BLOCK_SIZE + j] = block[j];
        }
    }
}

int main() {
    char message[1000], key[KEY_LENGTH + 1];
    printf("Enter the message to be encrypted: ");
    scanf("%s", message);
    generate_key(key);
    printf("Encrypted message: ");
    encrypt(message, key);
    printf("%s\n", message);
    printf("Decrypted message: ");
    decrypt(message, key);
    printf("%s\n", message);
    return 0;
}