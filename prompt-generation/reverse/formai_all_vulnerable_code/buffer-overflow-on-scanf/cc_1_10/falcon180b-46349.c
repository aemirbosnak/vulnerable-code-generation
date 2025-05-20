//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define MAX_DATA_LENGTH 500

void generate_key(char *key, int length) {
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[length] = '\0';
}

void encrypt_data(char *data, char *key) {
    int data_length = strlen(data);
    int key_length = strlen(key);

    for (int i = 0; i < data_length; i++) {
        if (isalpha(data[i])) {
            data[i] = (data[i] - 'a' + (int)key[i % key_length] - 'a') % 26 + 'a';
        }
    }
}

void decrypt_data(char *data, char *key) {
    int data_length = strlen(data);
    int key_length = strlen(key);

    for (int i = 0; i < data_length; i++) {
        if (isalpha(data[i])) {
            data[i] = (data[i] - 'a' - (int)key[i % key_length] + 26) % 26 + 'a';
        }
    }
}

int main() {
    srand(time(NULL));

    char data[MAX_DATA_LENGTH];
    printf("Enter data to encrypt: ");
    scanf("%s", data);

    char key[MAX_KEY_LENGTH];
    generate_key(key, strlen(data));

    encrypt_data(data, key);

    printf("Encrypted data: %s\n", data);

    decrypt_data(data, key);

    printf("Decrypted data: %s\n", data);

    return 0;
}