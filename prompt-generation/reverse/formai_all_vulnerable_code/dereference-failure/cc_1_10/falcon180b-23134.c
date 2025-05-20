//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 64

void generate_key(unsigned char *key) {
    time_t t;
    srand(time(&t));
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(unsigned char *message, unsigned char *key, int message_len) {
    int i, j;
    unsigned char temp;
    for (i = 0; i < message_len; i += BLOCK_SIZE) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            temp = message[i + j];
            message[i + j] = message[i + j] ^ key[j];
            key[j] = temp;
        }
    }
}

void decrypt(unsigned char *message, unsigned char *key, int message_len) {
    int i, j;
    unsigned char temp;
    for (i = 0; i < message_len; i += BLOCK_SIZE) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            temp = message[i + j];
            message[i + j] = message[i + j] ^ key[j];
            key[j] = temp;
        }
    }
}

int main() {
    unsigned char key[KEY_SIZE];
    generate_key(key);

    unsigned char message[] = "Hello, World! ";
    int message_len = strlen((char *)message);

    encrypt(message, key, message_len);

    printf("Encrypted message: ");
    for (int i = 0; i < message_len; i++) {
        printf("%02X ", message[i]);
    }
    printf("\n");

    decrypt(message, key, message_len);

    printf("Decrypted message: %s\n", message);

    return 0;
}