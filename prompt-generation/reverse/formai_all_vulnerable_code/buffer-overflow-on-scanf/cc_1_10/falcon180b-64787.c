//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char* key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char* plaintext, char* key, char* ciphertext) {
    int i, j;
    for (i = 0, j = 0; i < strlen(plaintext); i += BLOCK_SIZE, j += BLOCK_SIZE) {
        char block[BLOCK_SIZE];
        strncpy(block, plaintext + i, BLOCK_SIZE);
        for (int k = 0; k < BLOCK_SIZE; k++) {
            block[k] = block[k] ^ key[j + k];
        }
        strcat(ciphertext, block);
    }
}

void decrypt(char* ciphertext, char* key, char* plaintext) {
    int i, j;
    for (i = 0, j = 0; i < strlen(ciphertext); i += BLOCK_SIZE, j += BLOCK_SIZE) {
        char block[BLOCK_SIZE];
        strncpy(block, ciphertext + i, BLOCK_SIZE);
        for (int k = 0; k < BLOCK_SIZE; k++) {
            block[k] = block[k] ^ key[j + k];
        }
        strcat(plaintext, block);
    }
}

int main() {
    char plaintext[1000];
    char key[KEY_SIZE];
    char ciphertext[1000];

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    generate_key(key);

    printf("Key: ");
    for (int i = 0; i < KEY_SIZE; i++) {
        printf("%d ", key[i]);
    }

    encrypt(plaintext, key, ciphertext);

    printf("Ciphertext: ");
    printf("%s\n", ciphertext);

    decrypt(ciphertext, key, plaintext);

    printf("Decrypted plaintext: ");
    printf("%s\n", plaintext);

    return 0;
}