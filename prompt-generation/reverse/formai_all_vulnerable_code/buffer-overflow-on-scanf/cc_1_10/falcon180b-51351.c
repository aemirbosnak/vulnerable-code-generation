//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE] = '\0';
}

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j;
    char block[BLOCK_SIZE];

    for (i = 0, j = 0; i < strlen(plaintext); i++) {
        if (i % BLOCK_SIZE == 0) {
            int k;
            for (k = 0; k < BLOCK_SIZE && i < strlen(plaintext); k++) {
                block[k] = plaintext[i];
                i++;
            }
            block[k] = '\0';
            ciphertext = strcat(ciphertext, block);
        } else {
            block[j++] = plaintext[i];
        }
    }
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i, j;
    char block[BLOCK_SIZE];

    for (i = 0, j = 0; i < strlen(ciphertext); i++) {
        if (i % BLOCK_SIZE == 0) {
            int k;
            for (k = 0; k < BLOCK_SIZE && i < strlen(ciphertext); k++) {
                block[k] = ciphertext[i];
                i++;
            }
            block[k] = '\0';
            plaintext = strcat(plaintext, block);
        } else {
            int p = (int)key[j % KEY_SIZE] - 'a';
            block[j++] = (char)(((int)ciphertext[i] - 'a' - p) % 26 + 'a');
        }
    }
}

int main() {
    char plaintext[1000], key[KEY_SIZE + 1], ciphertext[1000];

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    generate_key(key);

    printf("Enter key: ");
    scanf("%s", key);

    encrypt(plaintext, key, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key, plaintext);

    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}