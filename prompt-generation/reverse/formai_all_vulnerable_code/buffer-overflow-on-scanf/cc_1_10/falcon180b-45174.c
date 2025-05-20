//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char *key, int key_size) {
    int i;
    for (i = 0; i < key_size; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j, k;
    char temp;
    for (i = 0, j = 0; i < strlen(plaintext); i += BLOCK_SIZE, j += BLOCK_SIZE) {
        for (k = 0; k < BLOCK_SIZE; k++) {
            ciphertext[j + k] = plaintext[i + k] ^ key[k];
        }
    }
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i, j, k;
    char temp;
    for (i = 0, j = 0; i < strlen(ciphertext); i += BLOCK_SIZE, j += BLOCK_SIZE) {
        for (k = 0; k < BLOCK_SIZE; k++) {
            plaintext[j + k] = ciphertext[i + k] ^ key[k];
        }
    }
}

int main() {
    char plaintext[100], ciphertext[100], key[KEY_SIZE];
    int key_size;

    printf("Enter the size of the key (between 1 and %d): ", KEY_SIZE - 1);
    scanf("%d", &key_size);
    if (key_size < 1 || key_size > KEY_SIZE - 1) {
        printf("Invalid key size.\n");
        return 1;
    }

    generate_key(key, key_size);
    printf("Key: %s\n", key);

    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key, plaintext);
    printf("Plaintext: %s\n", plaintext);

    return 0;
}