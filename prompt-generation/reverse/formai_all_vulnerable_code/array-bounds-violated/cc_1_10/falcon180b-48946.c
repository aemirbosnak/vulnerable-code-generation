//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char* key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE] = '\0';
}

void encrypt(char* message, char* key) {
    int i, j;
    char buffer[KEY_SIZE];
    strcpy(buffer, key);
    for (i = 0; i < strlen(message); i++) {
        message[i] = toupper(message[i]);
        if (isalpha(message[i])) {
            message[i] = (message[i] - 'A' + (int)buffer[i % KEY_SIZE]) % 26 + 'A';
        }
    }
}

void decrypt(char* message, char* key) {
    int i, j;
    char buffer[KEY_SIZE];
    strcpy(buffer, key);
    for (i = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = (message[i] - 'A' - (int)buffer[i % KEY_SIZE + KEY_SIZE - 1] + 26) % 26 + 'A';
        }
    }
}

int main() {
    char message[1000], key[KEY_SIZE + 1];
    generate_key(key);
    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    encrypt(message, key);
    printf("Encrypted message: %s\n", message);
    decrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}