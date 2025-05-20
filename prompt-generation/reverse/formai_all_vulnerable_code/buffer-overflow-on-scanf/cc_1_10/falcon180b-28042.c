//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_LENGTH 16
#define BLOCK_LENGTH 8

void generate_key(unsigned char* key) {
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(unsigned char* plaintext, unsigned char* key, unsigned char* ciphertext) {
    int i, j;
    unsigned char temp;

    for (i = 0, j = 0; i < strlen(plaintext); i++, j++) {
        if (j == BLOCK_LENGTH) {
            temp = ciphertext[j - BLOCK_LENGTH];
            ciphertext[j - BLOCK_LENGTH] = ciphertext[j];
            ciphertext[j] = temp;
            j = (j - BLOCK_LENGTH) % BLOCK_LENGTH;
        }

        ciphertext[j] ^= plaintext[i] ^ key[i % KEY_LENGTH];
    }
}

void decrypt(unsigned char* ciphertext, unsigned char* key, unsigned char* plaintext) {
    int i, j;
    unsigned char temp;

    for (i = 0, j = 0; i < strlen(ciphertext); i++, j++) {
        if (j == BLOCK_LENGTH) {
            temp = ciphertext[j - BLOCK_LENGTH];
            ciphertext[j - BLOCK_LENGTH] = ciphertext[j];
            ciphertext[j] = temp;
            j = (j - BLOCK_LENGTH) % BLOCK_LENGTH;
        }

        plaintext[i] = ciphertext[j] ^ key[i % KEY_LENGTH] ^ (j % BLOCK_LENGTH);
    }
}

int main() {
    unsigned char key[KEY_LENGTH];
    unsigned char plaintext[100];
    unsigned char ciphertext[100];

    generate_key(key);

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    encrypt(plaintext, key, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key, plaintext);

    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}