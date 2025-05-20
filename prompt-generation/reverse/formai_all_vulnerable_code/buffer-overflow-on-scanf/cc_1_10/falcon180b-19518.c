//Falcon-180B DATASET v1.0 Category: Encryption ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 8

typedef struct {
    char key[KEY_LENGTH + 1];
    int key_length;
} encryption_key;

void generate_key(encryption_key *key) {
    char *random_string = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int i;

    for (i = 0; i < KEY_LENGTH; i++) {
        key->key[i] = random_string[rand() % strlen(random_string)];
    }

    key->key_length = KEY_LENGTH;
    key->key[KEY_LENGTH] = '\0';
}

void encrypt(char *message, encryption_key *key) {
    int i, j;

    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] + key->key[j % key->key_length];
            j++;
        }
    }
}

void decrypt(char *message, encryption_key *key) {
    int i, j;

    for (i = 0, j = 0; i < strlen(message); i++) {
        if (isalpha(message[i])) {
            message[i] = message[i] - key->key[j % key->key_length];
            j++;
        }
    }
}

int main() {
    encryption_key key;
    char message[100];

    printf("Enter message to encrypt: ");
    scanf("%s", message);

    generate_key(&key);

    encrypt(message, &key);

    printf("Encrypted message: %s\n", message);

    decrypt(message, &key);

    printf("Decrypted message: %s\n", message);

    return 0;
}