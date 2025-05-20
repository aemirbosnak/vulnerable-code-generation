//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEY_SIZE 1024
#define MAX_DATA_SIZE 1024

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
    char data[MAX_DATA_SIZE];
    int data_size;
} crypt_data;

void generate_key(crypt_data *crypt, int key_size) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < key_size; i++) {
        crypt->key[i] = charset[rand() % strlen(charset)];
    }
    crypt->key_size = key_size;
}

void generate_data(crypt_data *crypt, int data_size) {
    for (int i = 0; i < data_size; i++) {
        crypt->data[i] = rand() % 26 + 'A';
    }
    crypt->data_size = data_size;
}

void encrypt(crypt_data *crypt) {
    for (int i = 0; i < crypt->data_size; i++) {
        crypt->data[i] = crypt->data[i] ^ crypt->key[i % crypt->key_size];
    }
}

void decrypt(crypt_data *crypt) {
    for (int i = 0; i < crypt->data_size; i++) {
        crypt->data[i] = crypt->data[i] ^ crypt->key[i % crypt->key_size];
    }
}

int main() {
    crypt_data crypt;
    int key_size, data_size;

    printf("Enter key size (up to %d): ", MAX_KEY_SIZE - 1);
    scanf("%d", &key_size);
    generate_key(&crypt, key_size);

    printf("Enter data size (up to %d): ", MAX_DATA_SIZE - 1);
    scanf("%d", &data_size);
    generate_data(&crypt, data_size);

    printf("Data: %s\n", crypt.data);
    encrypt(&crypt);
    printf("Encrypted data: %s\n", crypt.data);
    decrypt(&crypt);
    printf("Decrypted data: %s\n", crypt.data);

    return 0;
}