//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_SIZE 100
#define MAX_DATA_SIZE 1000

void generate_key(char* key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

void encrypt(char* data, int data_size, char* key) {
    for (int i = 0; i < data_size; i++) {
        data[i] = (data[i] + key[i % strlen(key)]) % 26 + 'a';
    }
}

void decrypt(char* data, int data_size, char* key) {
    for (int i = 0; i < data_size; i++) {
        data[i] = (data[i] - key[i % strlen(key)]) % 26 + 'a';
    }
}

int main() {
    char key[MAX_KEY_SIZE];
    char data[MAX_DATA_SIZE];
    int key_size, data_size;

    printf("Enter key size (1-100): ");
    scanf("%d", &key_size);

    generate_key(key, key_size);

    printf("Enter data to encrypt: ");
    scanf("%s", data);

    encrypt(data, strlen(data), key);

    printf("Encrypted data: %s\n", data);

    printf("Enter encrypted data to decrypt: ");
    scanf("%s", data);

    decrypt(data, strlen(data), key);

    printf("Decrypted data: %s\n", data);

    return 0;
}