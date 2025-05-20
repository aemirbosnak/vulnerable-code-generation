//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000
#define KEY_SIZE 16

typedef struct {
    char key[KEY_SIZE];
    int position;
} Vigenere;

void generate_key(char key[KEY_SIZE]) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'A';
    }
}

void encrypt(char plaintext[SIZE], char ciphertext[SIZE], Vigenere key) {
    for (int i = 0; i < SIZE; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            plaintext[i] = (plaintext[i] - 'A' + key.position) % 26 + 'A';
        } else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            plaintext[i] = (plaintext[i] - 'a' + key.position) % 26 + 'a';
        }
    }
    for (int i = 0; i < SIZE; i++) {
        ciphertext[i] = plaintext[i];
    }
}

void decrypt(char ciphertext[SIZE], char plaintext[SIZE], Vigenere key) {
    for (int i = 0; i < SIZE; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            ciphertext[i] = (ciphertext[i] - 'A' - key.position + 26) % 26 + 'A';
        } else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            ciphertext[i] = (ciphertext[i] - 'a' - key.position + 26) % 26 + 'a';
        }
    }
    for (int i = 0; i < SIZE; i++) {
        plaintext[i] = ciphertext[i];
    }
}

int main() {
    srand(time(NULL));
    char plaintext[SIZE] = "Hello, world!";
    char ciphertext[SIZE];
    Vigenere key;
    generate_key(key.key);
    encrypt(plaintext, ciphertext, key);
    printf("Ciphertext: %s\n", ciphertext);
    decrypt(ciphertext, plaintext, key);
    printf("Plaintext: %s\n", plaintext);
    return 0;
}