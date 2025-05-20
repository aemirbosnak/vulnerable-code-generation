//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_SIZE 1024
#define MAX_DATA_SIZE (1024 * 1024)

typedef struct {
    char key[MAX_KEY_SIZE];
    char data[MAX_DATA_SIZE];
    int data_size;
    int key_size;
} encrypted_data;

void generate_key(char* key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt_data(char* data, int data_size, char* key, int key_size) {
    for (int i = 0; i < data_size; i++) {
        data[i] ^= key[i % key_size];
    }
}

void decrypt_data(char* data, int data_size, char* key, int key_size) {
    for (int i = 0; i < data_size; i++) {
        data[i] ^= key[i % key_size];
    }
}

int main() {
    encrypted_data encrypted_data;
    char key[MAX_KEY_SIZE];
    char data[MAX_DATA_SIZE];
    int data_size;
    int key_size;

    printf("Enter data to encrypt: ");
    fgets(data, MAX_DATA_SIZE, stdin);
    data_size = strlen(data);

    printf("Enter key size: ");
    scanf("%d", &key_size);

    generate_key(key, key_size);

    encrypt_data(data, data_size, key, key_size);

    encrypted_data.data_size = data_size;
    encrypted_data.key_size = key_size;
    strcpy(encrypted_data.key, key);
    strcpy(encrypted_data.data, data);

    printf("Encrypted data: %s\n", encrypted_data.data);

    return 0;
}