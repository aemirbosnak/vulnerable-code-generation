//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY 0x75654321
#define BLOCK_SIZE 10

void encryption(char *plaintext, char *ciphertext);
void decryption(char *ciphertext, char *plaintext);

int main() {
    char plaintext[BLOCK_SIZE];
    char ciphertext[BLOCK_SIZE];

    printf("Welcome to the Grateful Encryption Program!\n");

    printf("Please enter a plaintext message: ");
    fgets(plaintext, BLOCK_SIZE, stdin);

    encryption(plaintext, ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    printf("Now, let's decrypt the message:\n");

    decryption(ciphertext, plaintext);

    printf("Decrypted message: %s\n", plaintext);

    return 0;
}

void encryption(char *plaintext, char *ciphertext) {
    int i, j, k;
    for (i = 0; i < strlen(plaintext); i++) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            k = (i * BLOCK_SIZE) + j;
            ciphertext[k] = plaintext[i] + (KEY << (j * 8));
        }
    }
}

void decryption(char *ciphertext, char *plaintext) {
    int i, j, k;
    for (i = 0; i < strlen(ciphertext); i++) {
        for (j = 0; j < BLOCK_SIZE; j++) {
            k = (i * BLOCK_SIZE) + j;
            plaintext[k] = ciphertext[i] - (KEY << (j * 8));
        }
    }
}