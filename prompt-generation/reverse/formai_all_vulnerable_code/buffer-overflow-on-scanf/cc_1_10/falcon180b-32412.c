//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 64

void generate_key(char* key) {
    int i;
    for (i = 0; i < SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[SIZE] = '\0';
}

void encrypt(char* plaintext, char* key, char* ciphertext) {
    int i, j;
    for (i = 0, j = 0; plaintext[i]; i++) {
        if (isalpha(plaintext[i])) {
            ciphertext[j++] = toupper(plaintext[i] + (int) key[i % SIZE] - 97);
        } else {
            ciphertext[j++] = plaintext[i];
        }
    }
    ciphertext[j] = '\0';
}

void decrypt(char* ciphertext, char* key, char* plaintext) {
    int i, j;
    for (i = 0, j = 0; ciphertext[i]; i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[j++] = (int) key[i % SIZE] - 97 + tolower(ciphertext[i] - 65);
        } else {
            plaintext[j++] = ciphertext[i];
        }
    }
    plaintext[j] = '\0';
}

int main() {
    char plaintext[100], ciphertext[100], key[100];
    printf("Enter plaintext to encrypt: ");
    scanf("%s", plaintext);
    printf("Enter key to use: ");
    scanf("%s", key);
    generate_key(key);
    encrypt(plaintext, key, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);
    printf("Enter key to use for decryption: ");
    scanf("%s", key);
    decrypt(ciphertext, key, plaintext);
    printf("Decrypted text: %s\n", plaintext);
    return 0;
}