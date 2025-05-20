//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"
#define BLOCK_SIZE 16

void encrypt(char* message, int length, char* key) {
    int i, j;
    char key_index = 0;
    char result[length + 1];

    for (i = 0; i < length; i++) {
        result[i] = message[i] ^ key[key_index];
        key_index = (key_index + 1) % strlen(key);
    }
    result[i] = '\0';

    strcpy(message, result);
}

void decrypt(char* message, int length, char* key) {
    int i, j;
    char key_index = 0;
    char result[length + 1];

    for (i = 0; i < length; i++) {
        result[i] = message[i] ^ key[key_index];
        key_index = (key_index + 1) % strlen(key);
    }
    result[i] = '\0';

    strcpy(message, result);
}

int main() {
    char message[100];
    char key[100];
    int length;

    printf("Enter message to encrypt: ");
    scanf("%s", message);
    length = strlen(message);

    printf("Enter key (minimum %d characters): ", BLOCK_SIZE);
    scanf("%s", key);

    if (strlen(key) < BLOCK_SIZE) {
        printf("Key must be at least %d characters long.\n", BLOCK_SIZE);
        return 1;
    }

    encrypt(message, length, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, length, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}