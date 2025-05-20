#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 256
#define BLOCK_SIZE 64

void encrypt(char *plaintext, char *key, char *ciphertext) {
    strcpy(ciphertext, plaintext);
    for (int i = 0; i < strlen(ciphertext); i++) {
        ciphertext[i] ^= key[i % KEY_SIZE];
    }
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    strcpy(plaintext, ciphertext);
    for (int i = 0; i < strlen(plaintext); i++) {
        plaintext[i] ^= key[i % KEY_SIZE];
    }
}

int main() {
    char plaintext[128], key[KEY_SIZE], ciphertext[128];
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter key (must be the same size as plaintext or ciphertext): ");
    fgets(key, sizeof(key), stdin);

    encrypt(plaintext, key, ciphertext);
    printf("Encrypted: %s\n", ciphertext);

    char decrypted[128];
    decrypt(ciphertext, key, decrypted);
    printf("Decrypted: %s\n", decrypted);

    return 0;
}
