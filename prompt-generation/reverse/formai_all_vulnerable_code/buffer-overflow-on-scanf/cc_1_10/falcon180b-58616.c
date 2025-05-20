//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 256
#define MAX_BLOCK_SIZE 64

void generate_key(char *key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        char c = rand() % 26 + 'a';
        key[i] = tolower(c);
    }
}

void encrypt_block(char *block, char *key, int key_size) {
    for (int i = 0; i < strlen(block); i++) {
        char c = block[i];
        if (isalpha(c)) {
            c = (c - 'a' + key[i % key_size]) % 26 + 'a';
        }
        block[i] = c;
    }
}

void decrypt_block(char *block, char *key, int key_size) {
    for (int i = 0; i < strlen(block); i++) {
        char c = block[i];
        if (isalpha(c)) {
            c = (c - key[i % key_size] + 26) % 26 + 'a';
        }
        block[i] = c;
    }
}

int main() {
    char message[MAX_BLOCK_SIZE];
    char key[MAX_KEY_SIZE];
    int key_size = rand() % MAX_KEY_SIZE + 1;
    printf("Enter message: ");
    scanf("%s", message);
    printf("Enter key size (1-%d): ", MAX_KEY_SIZE);
    scanf("%d", &key_size);
    generate_key(key, key_size);
    printf("Key: %s\n", key);
    encrypt_block(message, key, key_size);
    printf("Encrypted message: %s\n", message);
    decrypt_block(message, key, key_size);
    printf("Decrypted message: %s\n", message);
    return 0;
}