//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

void generate_key(char key[SIZE]) {
    int i;
    for (i = 0; i < SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char plaintext[SIZE], char key[SIZE], char ciphertext[SIZE]) {
    int i;
    for (i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            ciphertext[i] = (char) ((int) plaintext[i] + (int) key[i % SIZE] - 65);
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
}

void decrypt(char ciphertext[SIZE], char key[SIZE], char plaintext[SIZE]) {
    int i;
    for (i = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[i] = (char) ((int) ciphertext[i] - (int) key[i % SIZE] + 65);
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
}

int main() {
    char plaintext[SIZE];
    char key[SIZE];
    char ciphertext[SIZE];

    printf("Enter a plaintext message: ");
    scanf("%s", plaintext);

    generate_key(key);

    printf("Enter the key: ");
    scanf("%s", key);

    encrypt(plaintext, key, ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    decrypt(ciphertext, key, plaintext);

    printf("Decrypted message: %s\n", plaintext);

    return 0;
}