//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 50
#define MAX_DATA_LENGTH 1000

void encrypt(char* key, char* data) {
    int key_length = strlen(key);
    int data_length = strlen(data);
    char encrypted[MAX_DATA_LENGTH];
    int i, j, k = 0;

    for (i = 0; i < data_length; i++) {
        encrypted[i] = data[i] ^ key[k];
        k = (k + 1) % key_length;
    }
    encrypted[i] = '\0';
    strcpy(data, encrypted);
}

void decrypt(char* key, char* data) {
    int key_length = strlen(key);
    int data_length = strlen(data);
    char decrypted[MAX_DATA_LENGTH];
    int i, j, k = 0;

    for (i = 0; i < data_length; i++) {
        decrypted[i] = data[i] ^ key[k];
        k = (k + 1) % key_length;
    }
    decrypted[i] = '\0';
    strcpy(data, decrypted);
}

int main() {
    char key[MAX_KEY_LENGTH];
    char data[MAX_DATA_LENGTH];
    int key_length, data_length;

    printf("Enter key: ");
    scanf("%s", key);
    key_length = strlen(key);

    printf("Enter data to be encrypted: ");
    scanf("%s", data);
    data_length = strlen(data);

    encrypt(key, data);
    printf("Encrypted data: %s\n", data);

    decrypt(key, data);
    printf("Decrypted data: %s\n", data);

    return 0;
}