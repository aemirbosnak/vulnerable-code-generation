//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEY_SIZE 256
#define MAX_BLOCK_SIZE 128

void generate_key(char* key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char* plaintext, char* key, int key_size, char* ciphertext) {
    int i, j;
    for (i = 0, j = 0; i < strlen(plaintext); i++) {
        ciphertext[j++] = plaintext[i] ^ key[i % key_size];
    }
    ciphertext[j] = '\0';
}

void decrypt(char* ciphertext, char* key, int key_size, char* plaintext) {
    int i, j;
    for (i = 0, j = 0; i < strlen(ciphertext); i++) {
        plaintext[j++] = ciphertext[i] ^ key[i % key_size];
    }
    plaintext[j] = '\0';
}

int main() {
    char plaintext[MAX_BLOCK_SIZE];
    char ciphertext[MAX_BLOCK_SIZE];
    char key[MAX_KEY_SIZE];

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    printf("Enter key: ");
    generate_key(key, strlen(plaintext));

    encrypt(plaintext, key, strlen(plaintext), ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key, strlen(plaintext), plaintext);

    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}