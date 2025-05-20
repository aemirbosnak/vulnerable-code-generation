//Falcon-180B DATASET v1.0 Category: Encryption ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 256
#define MAX_MESSAGE_LENGTH 1000

void generate_key(char *key, int key_length) {
    for (int i = 0; i < key_length; ++i) {
        char c = rand() % 26 + 'a';
        key[i] = c;
    }
    key[key_length] = '\0';
}

void encrypt(char *message, char *key, char *ciphertext) {
    for (int i = 0; i < strlen(message); ++i) {
        char c = message[i];
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + (int)key[i % strlen(key)]) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + (int)key[i % strlen(key)]) % 26 + 'A';
        }
        ciphertext[i] = c;
    }
    ciphertext[strlen(message)] = '\0';
}

void decrypt(char *ciphertext, char *key, char *message) {
    for (int i = 0; i < strlen(ciphertext); ++i) {
        char c = ciphertext[i];
        if (c >= 'a' && c <= 'z') {
            c = (c - (int)key[i % strlen(key)] + 26) % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = (c - (int)key[i % strlen(key)] + 26) % 26 + 'A';
        }
        message[i] = c;
    }
    message[strlen(ciphertext)] = '\0';
}

int main() {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char ciphertext[MAX_MESSAGE_LENGTH];

    generate_key(key, strlen(key));

    printf("Enter a message to encrypt: ");
    scanf("%s", message);

    encrypt(message, key, ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    decrypt(ciphertext, key, message);

    printf("Decrypted message: %s\n", message);

    return 0;
}