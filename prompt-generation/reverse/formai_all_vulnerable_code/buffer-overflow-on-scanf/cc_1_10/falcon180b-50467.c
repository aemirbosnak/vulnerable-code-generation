//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BLOCK_SIZE 8
#define KEY_SIZE 16

// Function to generate a key
void generate_key(char *key) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[KEY_SIZE] = '\0';
}

// Function to encrypt a message using the key
void encrypt(char *message, char *key) {
    int i, j;
    char *cipher = (char *) malloc(strlen(message) + 1);
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            cipher[j++] = (message[i] + key[i % KEY_SIZE]) % 26 + 'A';
        } else {
            cipher[j++] = message[i];
        }
    }
    cipher[j] = '\0';
    printf("Encrypted message: %s\n", cipher);
}

// Function to decrypt a message using the key
void decrypt(char *message, char *key) {
    int i, j;
    char *plaintext = (char *) malloc(strlen(message) + 1);
    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            plaintext[j++] = (message[i] - key[i % KEY_SIZE] + 26) % 26 + 'A';
        } else {
            plaintext[j++] = message[i];
        }
    }
    plaintext[j] = '\0';
    printf("Decrypted message: %s\n", plaintext);
}

int main() {
    char message[100];
    char key[KEY_SIZE + 1];
    printf("Enter a message: ");
    scanf("%s", message);
    generate_key(key);
    printf("Key: %s\n", key);
    encrypt(message, key);
    decrypt(message, key);
    return 0;
}