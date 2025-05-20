//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_KEY_SIZE 32
#define MAX_DATA_SIZE 1024

void generate_key(char* key, int key_size) {
    int i;
    for (i = 0; i < key_size; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char* data, char* key, int data_size, int key_size) {
    int i, j;
    for (i = 0, j = 0; i < data_size; i++) {
        data[i] = data[i] ^ key[j];
        j++;
        if (j >= key_size) {
            j = 0;
        }
    }
}

void decrypt(char* data, char* key, int data_size, int key_size) {
    int i, j;
    for (i = 0, j = 0; i < data_size; i++) {
        data[i] = data[i] ^ key[j];
        j++;
        if (j >= key_size) {
            j = 0;
        }
    }
}

int main() {
    char data[MAX_DATA_SIZE];
    char key[MAX_KEY_SIZE];
    int data_size, key_size;

    printf("Enter data to encrypt: ");
    fgets(data, MAX_DATA_SIZE, stdin);
    data_size = strlen(data);

    printf("Enter key size (up to %d): ", MAX_KEY_SIZE);
    scanf("%d", &key_size);
    generate_key(key, key_size);

    encrypt(data, key, data_size, key_size);

    printf("Encrypted data: %s\n", data);

    decrypt(data, key, data_size, key_size);

    printf("Decrypted data: %s\n", data);

    return 0;
}