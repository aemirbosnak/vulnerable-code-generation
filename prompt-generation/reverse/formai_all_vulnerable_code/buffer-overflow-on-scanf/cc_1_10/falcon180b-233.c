//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LENGTH 16
#define BLOCK_LENGTH 8
#define ROUNDS 16

void generate_key(char key[KEY_LENGTH]) {
    srand(time(NULL));
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char plaintext[BLOCK_LENGTH], char key[KEY_LENGTH], char ciphertext[BLOCK_LENGTH]) {
    for (int i = 0; i < BLOCK_LENGTH; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % KEY_LENGTH];
    }
}

void decrypt(char ciphertext[BLOCK_LENGTH], char key[KEY_LENGTH], char plaintext[BLOCK_LENGTH]) {
    for (int i = 0; i < BLOCK_LENGTH; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % KEY_LENGTH];
    }
}

void print_key(char key[KEY_LENGTH]) {
    printf("Encryption key: ");
    for (int i = 0; i < KEY_LENGTH; i++) {
        printf("%c", key[i]);
    }
    printf("\n");
}

void print_block(char block[BLOCK_LENGTH]) {
    for (int i = 0; i < BLOCK_LENGTH; i++) {
        printf("%c", block[i]);
    }
    printf("\n");
}

int main() {
    char plaintext[BLOCK_LENGTH];
    char key[KEY_LENGTH];
    char ciphertext[BLOCK_LENGTH];

    generate_key(key);
    print_key(key);

    printf("Enter plaintext message: ");
    for (int i = 0; i < BLOCK_LENGTH; i++) {
        scanf("%c", &plaintext[i]);
    }

    for (int i = 0; i < ROUNDS; i++) {
        encrypt(plaintext, key, ciphertext);
        printf("Encrypted message after round %d: ", i + 1);
        print_block(ciphertext);
    }

    printf("Decrypted message: ");
    for (int i = 0; i < BLOCK_LENGTH; i++) {
        scanf("%c", &plaintext[i]);
    }

    for (int i = 0; i < ROUNDS; i++) {
        decrypt(ciphertext, key, plaintext);
        printf("Decrypted message after round %d: ", i + 1);
        print_block(plaintext);
    }

    return 0;
}