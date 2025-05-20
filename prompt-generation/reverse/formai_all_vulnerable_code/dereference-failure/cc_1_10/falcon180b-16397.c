//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_SIZE 256
#define MAX_BLOCK_SIZE 4096

typedef struct {
    char key[MAX_KEY_SIZE];
    int keylen;
    int rounds;
} encryption_params;

void generate_key(char* key, int keylen) {
    srand(time(NULL));
    for (int i = 0; i < keylen; i++) {
        char c = rand() % 26 + 'a';
        key[i] = c;
    }
    key[keylen] = '\0';
}

void encrypt(char* plaintext, int plaintext_len, char* key, int keylen, int rounds) {
    char* ciphertext = malloc(plaintext_len + 1);
    memset(ciphertext, 0, plaintext_len + 1);

    for (int i = 0; i < plaintext_len; i++) {
        char c = plaintext[i];
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + rounds) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + rounds) % 26 + 'A';
        }
        ciphertext[i] = c;
    }

    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("Ciphertext: %s\n", ciphertext);
}

void decrypt(char* ciphertext, int ciphertext_len, char* key, int keylen, int rounds) {
    char* plaintext = malloc(ciphertext_len + 1);
    memset(plaintext, 0, ciphertext_len + 1);

    for (int i = 0; i < ciphertext_len; i++) {
        char c = ciphertext[i];
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' - rounds + 26) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' - rounds + 26) % 26 + 'A';
        }
        plaintext[i] = c;
    }

    printf("Ciphertext: %s\n", ciphertext);
    printf("Key: %s\n", key);
    printf("Plaintext: %s\n", plaintext);
}

int main() {
    encryption_params params;
    params.keylen = 16;
    params.rounds = 10;
    generate_key(params.key, params.keylen);

    char* plaintext = "This is a secret message.";
    int plaintext_len = strlen(plaintext);

    encrypt(plaintext, plaintext_len, params.key, params.keylen, params.rounds);
    decrypt(plaintext, plaintext_len, params.key, params.keylen, params.rounds);

    return 0;
}