#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 32
#define BLOCK_SIZE 16

void encrypt(char *plaintext, char *key) {
    char ciphertext[strlen(plaintext) + BLOCK_SIZE];
    for (int i = 0; i < strlen(plaintext); i += BLOCK_SIZE) {
        for (int j = 0; j < BLOCK_SIZE && (i + j < strlen(plaintext)); j++) {
            char ch = plaintext[i + j] ^ key[j % MAX_KEY_LENGTH];
            ciphertext[j] = ch < 0 ? ch + 256 : ch;
        }
    }
    printf("Encrypted text: %s\n", ciphertext);
}

int main() {
    char plaintext[1024];
    char key[MAX_KEY_LENGTH];
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);

    // Out of bounds read
    char garbage[512];
    strcpy(garbage, key + MAX_KEY_LENGTH);

    encrypt(plaintext, key);

    return 0;
}
