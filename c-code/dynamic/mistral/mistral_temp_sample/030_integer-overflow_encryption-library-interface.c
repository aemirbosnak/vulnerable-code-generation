#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 10
#define BLOCK_SIZE 64

typedef struct {
    char key[MAX_KEY_LENGTH];
    char iv[BLOCK_SIZE];
} AESKey;

void aes_encrypt(AESKey key, char* plaintext, char* ciphertext) {
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] + key.key[i % MAX_KEY_LENGTH];
    }
}

void aes_decrypt(AESKey key, char* ciphertext, char* plaintext) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = ciphertext[i] - key.key[i % MAX_KEY_LENGTH];
    }
}

int main() {
    AESKey my_key = {"1234567890", "abcdefghijklmnop"};
    char plaintext[] = "SecretMessage";
    char ciphertext[strlen(plaintext) + 1];
    char decrypted[strlen(plaintext) + 1];

    aes_encrypt(my_key, plaintext, ciphertext);

    printf("Encrypted: %s\n", ciphertext);

    aes_decrypt(my_key, ciphertext, decrypted);

    printf("Decrypted: %s\n", decrypted);

    return 0;
}
