//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 16
#define MAX_DATA_SIZE 4096

void generate_key(char* key, int key_size) {
    for(int i=0; i<key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

int encrypt(char* data, char* key, int data_size, int key_size) {
    for(int i=0; i<data_size; i++) {
        if(isalpha(data[i])) {
            data[i] = (data[i] - 'a' + key[i % key_size]) % 26 + 'a';
        }
    }
    return 0;
}

int decrypt(char* data, char* key, int data_size, int key_size) {
    for(int i=0; i<data_size; i++) {
        if(isalpha(data[i])) {
            data[i] = (data[i] - 'a' - key[i % key_size] + 26) % 26 + 'a';
        }
    }
    return 0;
}

int main() {
    char data[MAX_DATA_SIZE];
    char key[MAX_KEY_SIZE];
    int data_size, key_size;

    printf("Enter the data to encrypt: ");
    scanf("%[^\n]s", data);
    data_size = strlen(data);

    printf("Enter the key to encrypt with: ");
    scanf("%[^\n]s", key);
    key_size = strlen(key);

    if(key_size > MAX_KEY_SIZE) {
        printf("Error: Key size must be less than or equal to %d\n", MAX_KEY_SIZE);
        return 1;
    }

    encrypt(data, key, data_size, key_size);
    printf("Encrypted data: %s\n", data);

    decrypt(data, key, data_size, key_size);
    printf("Decrypted data: %s\n", data);

    return 0;
}