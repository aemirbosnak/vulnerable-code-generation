//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 32
#define MAX_MESSAGE_SIZE 1024

void generate_key(char *key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[key_size] = '\0';
}

void encrypt(char *message, char *key, int key_size) {
    for (int i = 0; i < strlen(message); i++) {
        char c = toupper(message[i]);
        if (isalpha(c)) {
            int index = c - 'A';
            message[i] = 'A' + ((index + key_size - 1) % key_size);
        }
    }
}

void decrypt(char *message, char *key, int key_size) {
    for (int i = 0; i < strlen(message); i++) {
        char c = toupper(message[i]);
        if (isalpha(c)) {
            int index = c - 'A';
            message[i] = 'A' + ((index - key_size + 26) % 26);
        }
    }
}

int main() {
    char message[MAX_MESSAGE_SIZE];
    char key[MAX_KEY_SIZE];

    printf("Enter a message to encrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);

    printf("Enter a key to encrypt with: ");
    scanf("%s", key);

    generate_key(key, strlen(key));

    encrypt(message, key, strlen(key));

    printf("Encrypted message: %s\n", message);

    decrypt(message, key, strlen(key));

    printf("Decrypted message: %s\n", message);

    return 0;
}