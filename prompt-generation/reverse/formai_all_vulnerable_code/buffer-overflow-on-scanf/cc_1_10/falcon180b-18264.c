//Falcon-180B DATASET v1.0 Category: Encryption ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 64
#define MAX_MSG_SIZE 1024
#define ALPHABET_SIZE 26

void generate_key(char *key, int key_size) {
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % ALPHABET_SIZE + 'A';
    }
}

void encrypt(char *msg, char *key, int key_size) {
    for (int i = 0; i < strlen(msg); i++) {
        if (isalpha(msg[i])) {
            char c = tolower(msg[i]);
            int k = tolower(key[i % key_size]) - 'a';
            msg[i] = (c + k - 'a') % 26 + 'a';
        }
    }
}

void decrypt(char *msg, char *key, int key_size) {
    for (int i = 0; i < strlen(msg); i++) {
        if (isalpha(msg[i])) {
            char c = tolower(msg[i]);
            int k = tolower(key[i % key_size]) - 'a';
            msg[i] = (c - k + 26) % 26 + 'a';
        }
    }
}

int main() {
    char msg[MAX_MSG_SIZE];
    char key[MAX_KEY_SIZE];
    int msg_size, key_size;

    printf("Enter message to encrypt: ");
    fgets(msg, MAX_MSG_SIZE, stdin);
    msg_size = strlen(msg);

    printf("Enter key size (1-64): ");
    scanf("%d", &key_size);

    if (key_size > MAX_KEY_SIZE) {
        printf("Invalid key size.\n");
        return 1;
    }

    generate_key(key, key_size);

    encrypt(msg, key, key_size);

    printf("Encrypted message: %s\n", msg);

    decrypt(msg, key, key_size);

    printf("Decrypted message: %s\n", msg);

    return 0;
}