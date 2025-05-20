//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char* key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE] = '\0';
}

void encrypt(char* plaintext, char* key, char* ciphertext) {
    int i = 0, j = 0;
    while (*plaintext) {
        if (isalpha(*plaintext)) {
            char c = *plaintext;
            c = (c + *key) % 26 + 'a';
            ciphertext[j++] = c;
        } else {
            ciphertext[j++] = *plaintext;
        }
        plaintext++;
    }
    ciphertext[j] = '\0';
}

void decrypt(char* ciphertext, char* key, char* plaintext) {
    int i = 0, j = 0;
    while (*ciphertext) {
        if (isalpha(*ciphertext)) {
            char c = *ciphertext;
            c = (c - *key + 26) % 26 + 'a';
            plaintext[j++] = c;
        } else {
            plaintext[j++] = *ciphertext;
        }
        ciphertext++;
    }
    plaintext[j] = '\0';
}

int main() {
    char plaintext[1000], key[KEY_SIZE + 1], ciphertext[1000];
    printf("Enter plaintext: ");
    scanf("%s", plaintext);
    generate_key(key);
    encrypt(plaintext, key, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);
    decrypt(ciphertext, key, plaintext);
    printf("Decrypted text: %s\n", plaintext);
    return 0;
}