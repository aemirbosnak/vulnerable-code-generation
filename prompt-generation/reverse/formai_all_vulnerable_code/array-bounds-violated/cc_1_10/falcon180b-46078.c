//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[KEY_SIZE] = '\0';
}

void encrypt(char *plaintext, char *key) {
    int i, j;
    char ciphertext[strlen(plaintext)];
    for (i = 0, j = 0; i < strlen(plaintext); i++, j++) {
        if (j == KEY_SIZE) {
            generate_key(key);
            j = 0;
        }
        ciphertext[i] = plaintext[i] ^ key[j];
    }
    ciphertext[strlen(plaintext)] = '\0';
    printf("Ciphertext: %s\n", ciphertext);
}

void decrypt(char *ciphertext, char *key) {
    int i, j;
    char plaintext[strlen(ciphertext)];
    for (i = 0, j = 0; i < strlen(ciphertext); i++, j++) {
        if (j == KEY_SIZE) {
            generate_key(key);
            j = 0;
        }
        plaintext[i] = ciphertext[i] ^ key[j];
    }
    plaintext[strlen(ciphertext)] = '\0';
    printf("Plaintext: %s\n", plaintext);
}

int main() {
    char plaintext[1000], ciphertext[1000];
    char key[KEY_SIZE + 1];

    printf("Enter a plaintext message: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    generate_key(key);

    encrypt(plaintext, key);
    decrypt(ciphertext, key);

    return 0;
}