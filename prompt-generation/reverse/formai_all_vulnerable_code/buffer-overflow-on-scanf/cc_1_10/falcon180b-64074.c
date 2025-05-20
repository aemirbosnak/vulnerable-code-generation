//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 32
#define MAX_BLOCK_SIZE 16

void generate_key(char* key) {
    int i;

    for (i = 0; i < MAX_KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

void encrypt(char* key, char* plaintext, char* ciphertext) {
    int i, j;

    for (i = 0, j = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            ciphertext[j++] = ((int) plaintext[i] + (int) key[i % MAX_KEY_SIZE]) % 26 + 'A';
        } else {
            ciphertext[j++] = plaintext[i];
        }
    }
}

void decrypt(char* key, char* ciphertext, char* plaintext) {
    int i, j;

    for (i = 0, j = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[j++] = ((int) ciphertext[i] - (int) key[i % MAX_KEY_SIZE + 26]) % 26 + 'A';
        } else {
            plaintext[j++] = ciphertext[i];
        }
    }
}

int main() {
    char key[MAX_KEY_SIZE];
    char plaintext[MAX_BLOCK_SIZE];
    char ciphertext[MAX_BLOCK_SIZE];

    generate_key(key);

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    encrypt(key, plaintext, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    decrypt(key, ciphertext, plaintext);

    printf("Plaintext: %s\n", plaintext);

    return 0;
}