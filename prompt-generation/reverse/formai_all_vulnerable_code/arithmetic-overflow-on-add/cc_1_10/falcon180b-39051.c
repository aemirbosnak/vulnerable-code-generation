//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 64
#define MAX_BLOCK_SIZE 16

typedef struct {
    char key[MAX_KEY_LENGTH];
    int key_length;
    int block_size;
    char iv[MAX_BLOCK_SIZE];
} cipher_t;

static void generate_key(cipher_t* cipher, const char* plaintext) {
    int i, j, key_length = strlen(plaintext);
    char* key = cipher->key;

    for (i = 0; i < key_length; i++) {
        key[i] = plaintext[i] ^ 'a';
    }
    cipher->key_length = key_length;
}

static void encrypt(cipher_t* cipher, const char* plaintext, char* ciphertext) {
    int i, j, key_length = cipher->key_length;
    char* key = cipher->key;
    int block_size = cipher->block_size;
    char* iv = cipher->iv;

    char* buffer = malloc(block_size + 1);
    memset(buffer, 0, block_size + 1);

    for (i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            buffer[i % block_size] = plaintext[i];
        }
    }

    for (i = 0; i < strlen(plaintext); i++) {
        j = (i % block_size) * 2;
        ciphertext[i] = buffer[j] ^ key[j % key_length];
    }

    free(buffer);
}

static void decrypt(cipher_t* cipher, const char* ciphertext, char* plaintext) {
    int i, j, key_length = cipher->key_length;
    char* key = cipher->key;
    int block_size = cipher->block_size;
    char* iv = cipher->iv;

    char* buffer = malloc(block_size + 1);
    memset(buffer, 0, block_size + 1);

    for (i = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            buffer[i % block_size] = ciphertext[i];
        }
    }

    for (i = 0; i < strlen(ciphertext); i++) {
        j = (i % block_size) * 2;
        plaintext[i] = buffer[j] ^ key[j % key_length];
    }

    free(buffer);
}

int main() {
    cipher_t cipher;
    char plaintext[MAX_BLOCK_SIZE];
    char ciphertext[MAX_BLOCK_SIZE];
    char decrypted_text[MAX_BLOCK_SIZE];

    printf("Enter a plaintext message to encrypt: ");
    scanf("%s", plaintext);

    generate_key(&cipher, plaintext);
    encrypt(&cipher, plaintext, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);

    decrypt(&cipher, ciphertext, decrypted_text);
    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}