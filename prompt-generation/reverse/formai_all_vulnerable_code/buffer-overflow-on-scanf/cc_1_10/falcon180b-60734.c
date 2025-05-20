//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 32
#define BLOCK_SIZE 16

void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }
}

void encrypt(char *key, char *message, char *cipher) {
    int i, j;
    for (i = 0, j = 0; i < strlen(message); i++, j++) {
        if (j == BLOCK_SIZE) {
            generate_key(key);
            j = 0;
        }
        cipher[i] = message[i] ^ key[j];
    }
}

void decrypt(char *key, char *cipher, char *message) {
    int i, j;
    for (i = 0, j = 0; i < strlen(cipher); i++, j++) {
        if (j == BLOCK_SIZE) {
            generate_key(key);
            j = 0;
        }
        message[i] = cipher[i] ^ key[j];
    }
}

int main() {
    char key[KEY_SIZE];
    generate_key(key);
    printf("Key: ");
    for (int i = 0; i < KEY_SIZE; i++) {
        printf("%02X ", key[i]);
    }
    printf("\n");

    char message[100];
    printf("Enter message: ");
    scanf("%s", message);

    char cipher[100];
    encrypt(key, message, cipher);
    printf("Cipher: ");
    for (int i = 0; i < strlen(cipher); i++) {
        printf("%02X ", cipher[i]);
    }
    printf("\n");

    char decrypted_message[100];
    decrypt(key, cipher, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}