//Falcon-180B DATASET v1.0 Category: Encryption ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_SIZE 10000
#define KEY_SIZE 16

typedef struct {
    char key[KEY_SIZE];
    int rounds;
} block_t;

void generate_key(char* key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(block_t* block, char* key) {
    int i, j, n;
    n = strlen(block->key);
    for (i = 0; i < n; i++) {
        block->key[i] = toupper(block->key[i]);
    }
    for (i = 0; i < block->rounds; i++) {
        for (j = 0; j < n; j++) {
            block->key[j] = (block->key[j] + key[i % KEY_SIZE]) % 26 + 'a';
        }
    }
}

void decrypt(block_t* block, char* key) {
    int i, j, n;
    n = strlen(block->key);
    for (i = 0; i < n; i++) {
        block->key[i] = toupper(block->key[i]);
    }
    for (i = block->rounds - 1; i >= 0; i--) {
        for (j = 0; j < n; j++) {
            block->key[j] = (block->key[j] - key[i % KEY_SIZE]) % 26 + 'a';
        }
    }
}

int main() {
    char message[MAX_SIZE];
    char key[KEY_SIZE];
    int rounds;
    printf("Enter message: ");
    scanf("%s", message);
    printf("Enter rounds: ");
    scanf("%d", &rounds);
    printf("Enter key: ");
    scanf("%s", key);
    block_t block;
    strcpy(block.key, message);
    block.rounds = rounds;
    generate_key(key);
    encrypt(&block, key);
    printf("Encrypted message: %s\n", block.key);
    decrypt(&block, key);
    printf("Decrypted message: %s\n", block.key);
    return 0;
}