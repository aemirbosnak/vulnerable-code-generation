//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 64
#define MAX_MESSAGE_LENGTH 1024

typedef struct {
    char key[MAX_KEY_LENGTH];
    char message[MAX_MESSAGE_LENGTH];
    char encrypted_message[MAX_MESSAGE_LENGTH];
} cryptogram;

void generate_key(cryptogram *crypt) {
    int key_length = rand() % MAX_KEY_LENGTH + 1;
    crypt->key[key_length] = '\0';
    for (int i = 0; i < key_length; i++) {
        crypt->key[i] = rand() % 26 + 'a';
    }
}

void encrypt(cryptogram *crypt) {
    int message_length = strlen(crypt->message);
    int key_length = strlen(crypt->key);
    for (int i = 0; i < message_length; i++) {
        crypt->encrypted_message[i] = crypt->message[i] ^ crypt->key[i % key_length];
    }
    crypt->encrypted_message[message_length] = '\0';
}

void decrypt(cryptogram *crypt) {
    int message_length = strlen(crypt->encrypted_message);
    int key_length = strlen(crypt->key);
    for (int i = 0; i < message_length; i++) {
        crypt->message[i] = crypt->encrypted_message[i] ^ crypt->key[i % key_length];
    }
    crypt->message[message_length] = '\0';
}

int main() {
    cryptogram crypt;
    generate_key(&crypt);
    printf("key: %s\n", crypt.key);
    printf("message: ");
    scanf("%s", crypt.message);
    encrypt(&crypt);
    printf("encrypted message: %s\n", crypt.encrypted_message);
    decrypt(&crypt);
    printf("decrypted message: %s\n", crypt.message);
    return 0;
}