//Falcon-180B DATASET v1.0 Category: Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(unsigned char *key) {
    time_t t;
    time(&t);
    srand(t);

    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(unsigned char *key, unsigned char *plaintext, int plaintext_len, unsigned char *ciphertext) {
    int j = 0;
    for (int i = 0; i < plaintext_len; i += BLOCK_SIZE) {
        unsigned char block[BLOCK_SIZE];
        memcpy(block, plaintext + i, BLOCK_SIZE);

        for (int k = 0; k < BLOCK_SIZE; k++) {
            ciphertext[j++] = plaintext[i + k] ^ key[k];
        }
    }
}

void decrypt(unsigned char *key, unsigned char *ciphertext, int ciphertext_len, unsigned char *plaintext) {
    int j = 0;
    for (int i = 0; i < ciphertext_len; i += BLOCK_SIZE) {
        unsigned char block[BLOCK_SIZE];
        memcpy(block, ciphertext + i, BLOCK_SIZE);

        for (int k = 0; k < BLOCK_SIZE; k++) {
            plaintext[j++] = ciphertext[i + k] ^ key[k];
        }
    }
}

int main() {
    unsigned char key[KEY_SIZE];
    generate_key(key);

    printf("Key: ");
    for (int i = 0; i < KEY_SIZE; i++) {
        printf("%02X ", key[i]);
    }
    printf("\n");

    unsigned char plaintext[] = "Hello, world!";
    int plaintext_len = strlen(plaintext);

    unsigned char ciphertext[plaintext_len];
    encrypt(key, plaintext, plaintext_len, ciphertext);

    printf("Ciphertext: ");
    for (int i = 0; i < plaintext_len; i++) {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n");

    unsigned char decrypted_text[plaintext_len];
    decrypt(key, ciphertext, plaintext_len, decrypted_text);

    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}