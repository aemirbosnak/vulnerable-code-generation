//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(unsigned char* key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(unsigned char* plaintext, unsigned char* key, unsigned char* ciphertext) {
    int j = 0;
    for (int i = 0; i < strlen(plaintext); i++) {
        plaintext[i] ^= key[j];
        if (j == KEY_SIZE - 1) {
            j = 0;
        } else {
            j++;
        }
    }
    strcpy(ciphertext, plaintext);
}

void decrypt(unsigned char* ciphertext, unsigned char* key, unsigned char* plaintext) {
    int j = 0;
    for (int i = 0; i < strlen(ciphertext); i++) {
        ciphertext[i] ^= key[j];
        if (j == KEY_SIZE - 1) {
            j = 0;
        } else {
            j++;
        }
    }
    strcpy(plaintext, ciphertext);
}

int main() {
    unsigned char key[KEY_SIZE];
    unsigned char plaintext[100];
    unsigned char ciphertext[100];
    generate_key(key);
    printf("Enter plaintext: ");
    scanf("%s", plaintext);
    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    decrypt(ciphertext, key, plaintext);
    printf("Plaintext: %s\n", plaintext);
    return 0;
}