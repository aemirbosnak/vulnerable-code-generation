//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_KEY_SIZE 16
#define MAX_MESSAGE_SIZE 100

void generate_key(char *key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

void encrypt(char *message, char *key, char *ciphertext) {
    int message_size = strlen(message);
    int key_size = strlen(key);

    for (int i = 0; i < message_size; i++) {
        ciphertext[i] = message[i] ^ key[i % key_size];
    }
    ciphertext[message_size] = '\0';
}

void decrypt(char *ciphertext, char *key, char *message) {
    int message_size = strlen(ciphertext);
    int key_size = strlen(key);

    for (int i = 0; i < message_size; i++) {
        message[i] = ciphertext[i] ^ key[i % key_size];
    }
    message[message_size] = '\0';
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];
    char ciphertext[MAX_MESSAGE_SIZE];

    printf("Enter message to encrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    generate_key(key, MAX_KEY_SIZE);

    encrypt(message, key, ciphertext);

    printf("Encrypted message: %s\n", ciphertext);

    decrypt(ciphertext, key, message);

    printf("Decrypted message: %s\n", message);

    return 0;
}