//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: configurable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8
#define MAX_SIZE 1000

char *key = "MySecretKey";
char *plaintext = "Hello World!";

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char *plaintext, char *key) {
    int i, j, k;
    char *ciphertext = malloc(MAX_SIZE);
    memset(ciphertext, 0, MAX_SIZE);

    for (i = 0, j = 0; i < strlen(plaintext); i++) {
        k = (int) plaintext[i] ^ (int) key[j];
        if (k < 0) {
            k += 256;
        }
        ciphertext[i] = k;
        j++;
        if (j == KEY_SIZE) {
            j = 0;
        }
    }

    printf("Encrypted Text: %s\n", ciphertext);
    free(ciphertext);
}

void decrypt(char *ciphertext, char *key) {
    int i, j, k;
    char *plaintext = malloc(MAX_SIZE);
    memset(plaintext, 0, MAX_SIZE);

    for (i = 0, j = 0; i < strlen(ciphertext); i++) {
        k = (int) ciphertext[i] ^ (int) key[j];
        if (k < 0) {
            k += 256;
        }
        plaintext[i] = k;
        j++;
        if (j == KEY_SIZE) {
            j = 0;
        }
    }

    printf("Decrypted Text: %s\n", plaintext);
    free(plaintext);
}

int main() {
    generate_key(key);
    printf("Key: %s\n", key);

    encrypt(plaintext, key);
    decrypt(plaintext, key);

    return 0;
}