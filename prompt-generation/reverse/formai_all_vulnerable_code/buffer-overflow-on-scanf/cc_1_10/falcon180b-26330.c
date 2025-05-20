//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 64
#define ROUNDS 1000

void generate_key(char* key) {
    time_t now = time(NULL);
    srand(now);
    for (int i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_LENGTH] = '\0';
}

void encrypt(char* plaintext, char* key, char* ciphertext) {
    int plaintext_len = strlen(plaintext);
    int ciphertext_len = plaintext_len + BLOCK_SIZE - 1;
    ciphertext[ciphertext_len] = '\0';

    int key_index = 0;
    for (int i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ key[key_index];
        key_index = (key_index + 1) % KEY_LENGTH;
    }

    for (int i = plaintext_len; i < ciphertext_len; i++) {
        ciphertext[i] = rand() % 26 + 'a';
    }
}

void decrypt(char* ciphertext, char* key, char* plaintext) {
    int ciphertext_len = strlen(ciphertext);
    int plaintext_len = ciphertext_len - BLOCK_SIZE + 1;
    plaintext[plaintext_len] = '\0';

    int key_index = 0;
    for (int i = 0; i < ciphertext_len; i++) {
        plaintext[i] = ciphertext[i] ^ key[key_index];
        key_index = (key_index + 1) % KEY_LENGTH;
    }
}

int main() {
    char plaintext[1000];
    char key[KEY_LENGTH + 1];
    char ciphertext[1000];

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    generate_key(key);

    encrypt(plaintext, key, ciphertext);

    printf("Encrypted text: %s\n", ciphertext);

    decrypt(ciphertext, key, plaintext);

    printf("Decrypted text: %s\n", plaintext);

    return 0;
}