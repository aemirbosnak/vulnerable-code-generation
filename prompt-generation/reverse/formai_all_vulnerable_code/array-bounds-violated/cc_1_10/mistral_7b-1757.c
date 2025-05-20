//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 26
#define MESSAGE_SIZE 50

typedef struct {
    char key[KEY_SIZE];
} SecretKey;

void init_key(SecretKey* key) {
    srand(time(NULL));
    for (int i = 0; i < KEY_SIZE; ++i) {
        key->key[i] = 'A' + rand() % 26;
    }
}

void encrypt_message(char* message, SecretKey key) {
    for (int i = 0; i < strlen(message) && i < MESSAGE_SIZE; ++i) {
        int index = (int) message[i] - 'A';
        message[i] = key.key[(index + (int) key.key[0] - 'A') % KEY_SIZE];
    }
}

void decrypt_message(char* message, SecretKey key) {
    for (int i = 0; i < strlen(message) && i < MESSAGE_SIZE; ++i) {
        int index = (int) message[i] - 'A';
        message[i] = key.key[(index - (int) key.key[0] + KEY_SIZE) % KEY_SIZE];
    }
}

int keys_equal(SecretKey key1, SecretKey key2) {
    for (int i = 0; i < KEY_SIZE; ++i) {
        if (key1.key[i] != key2.key[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    SecretKey key1, key2;
    char message[MESSAGE_SIZE] = "Hello, world!";

    init_key(&key1);
    printf("Generated key 1: ");
    for (int i = 0; i < KEY_SIZE; ++i) {
        printf("%c ", key1.key[i]);
    }
    printf("\n");

    init_key(&key2);
    printf("Generated key 2: ");
    for (int i = 0; i < KEY_SIZE; ++i) {
        printf("%c ", key2.key[i]);
    }
    printf("\n");

    encrypt_message(message, key1);
    printf("Encrypted message with key 1: %s\n", message);

    decrypt_message(message, key1);
    printf("Decrypted message with key 1: %s\n", message);

    if (keys_equal(key1, key2)) {
        printf("Keys are equal.\n");
    } else {
        printf("Keys are not equal.\n");
    }

    return 0;
}