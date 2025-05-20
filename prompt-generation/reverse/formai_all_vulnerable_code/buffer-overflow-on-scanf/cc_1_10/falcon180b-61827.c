//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 32
#define MAX_BLOCK_SIZE 64
#define MAX_ROUNDS 16

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
    int rounds;
} encryption_params;

void generate_key(char* key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

void generate_random_data(char* data, int data_size) {
    for (int i = 0; i < data_size; i++) {
        data[i] = rand() % 26 + 'a';
    }
    data[data_size] = '\0';
}

void encrypt(char* data, int data_size, encryption_params* params) {
    char key[MAX_KEY_SIZE];
    generate_key(key, params->key_size);
    for (int i = 0; i < data_size; i++) {
        data[i] ^= key[i % params->key_size];
    }
}

void decrypt(char* data, int data_size, encryption_params* params) {
    char key[MAX_KEY_SIZE];
    generate_key(key, params->key_size);
    for (int i = 0; i < data_size; i++) {
        data[i] ^= key[i % params->key_size];
    }
}

int main() {
    encryption_params params;
    printf("Enter key size (1-32): ");
    scanf("%d", &params.key_size);
    printf("Enter number of rounds (1-16): ");
    scanf("%d", &params.rounds);
    generate_key(params.key, params.key_size);
    char data[MAX_BLOCK_SIZE];
    generate_random_data(data, params.key_size);
    printf("Original data: %s\n", data);
    encrypt(data, params.key_size, &params);
    printf("Encrypted data: %s\n", data);
    decrypt(data, params.key_size, &params);
    printf("Decrypted data: %s\n", data);
    return 0;
}