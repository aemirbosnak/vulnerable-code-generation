//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 16
#define MAX_BLOCK_LENGTH 16
#define MAX_ROUNDS 10

// Function to generate a random key
void generate_key(char* key, int length) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

// Function to encrypt a block of text using a key
void encrypt(char* block, char* key, int rounds) {
    int i, j, k;
    for (i = 0; i < rounds; i++) {
        for (j = 0; j < strlen(block); j++) {
            block[j] = block[j] + key[i % strlen(key)];
        }
    }
}

// Function to decrypt a block of text using a key
void decrypt(char* block, char* key, int rounds) {
    int i, j, k;
    for (i = 0; i < rounds; i++) {
        for (j = 0; j < strlen(block); j++) {
            block[j] = block[j] - key[i % strlen(key)];
        }
    }
}

// Function to test encryption and decryption
void test_encryption(char* block, char* key) {
    char encrypted_block[MAX_BLOCK_LENGTH];
    encrypt(block, key, MAX_ROUNDS);
    printf("Encrypted block: %s\n", encrypted_block);

    char decrypted_block[MAX_BLOCK_LENGTH];
    decrypt(encrypted_block, key, MAX_ROUNDS);
    printf("Decrypted block: %s\n", decrypted_block);
}

int main() {
    char key[MAX_KEY_LENGTH];
    generate_key(key, strlen(key));

    char block[MAX_BLOCK_LENGTH];
    printf("Enter a block of text to encrypt: ");
    scanf("%s", block);

    test_encryption(block, key);

    return 0;
}