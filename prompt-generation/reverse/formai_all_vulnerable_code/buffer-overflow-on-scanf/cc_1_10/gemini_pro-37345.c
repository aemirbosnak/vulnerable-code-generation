//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

unsigned char key[KEY_SIZE];
unsigned char plaintext[BLOCK_SIZE];
unsigned char ciphertext[BLOCK_SIZE];

void encrypt(unsigned char *plaintext, unsigned char *ciphertext, unsigned char *key) {
    int i;
    for(i = 0; i < BLOCK_SIZE; i++) {
        ciphertext[i] = plaintext[i] ^ key[i];
    }
}

void decrypt(unsigned char *ciphertext, unsigned char *plaintext, unsigned char *key) {
    int i;
    for(i = 0; i < BLOCK_SIZE; i++) {
        plaintext[i] = ciphertext[i] ^ key[i];
    }
}

int main() {
    // Generate a random key
    srand(time(NULL));
    for(int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }

    // Get the plaintext from the user
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    // Encrypt the plaintext
    encrypt(plaintext, ciphertext, key);

    // Print the ciphertext
    printf("Ciphertext: ");
    for(int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the ciphertext
    decrypt(ciphertext, plaintext, key);

    // Print the plaintext
    printf("Plaintext: %s\n", plaintext);

    return 0;
}