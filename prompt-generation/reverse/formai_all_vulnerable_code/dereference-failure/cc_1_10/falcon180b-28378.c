//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_SIZE 1024
#define MAX_MESSAGE_LENGTH 1024

typedef struct {
    char *public_key;
    char *private_key;
} key_pair;

void generate_key_pair(key_pair *key_pair) {
    char *public_key = malloc(MAX_KEY_SIZE);
    char *private_key = malloc(MAX_KEY_SIZE);

    srand(time(NULL));

    for (int i = 0; i < MAX_KEY_SIZE; i++) {
        public_key[i] = 'A' + rand() % 26;
        private_key[i] = 'A' + rand() % 26;
    }

    key_pair->public_key = public_key;
    key_pair->private_key = private_key;
}

void encrypt_message(char *message, key_pair *key_pair) {
    char *encrypted_message = malloc(MAX_MESSAGE_LENGTH);

    for (int i = 0; i < strlen(message); i++) {
        encrypted_message[i] = message[i] ^ key_pair->public_key[i % MAX_KEY_SIZE];
    }

    printf("Encrypted message: %s\n", encrypted_message);
}

void decrypt_message(char *encrypted_message, key_pair *key_pair) {
    char *decrypted_message = malloc(MAX_MESSAGE_LENGTH);

    for (int i = 0; i < strlen(encrypted_message); i++) {
        decrypted_message[i] = encrypted_message[i] ^ key_pair->private_key[i % MAX_KEY_SIZE];
    }

    printf("Decrypted message: %s\n", decrypted_message);
}

int main() {
    key_pair key_pair;
    generate_key_pair(&key_pair);

    char *message = "Hello, world!";
    encrypt_message(message, &key_pair);
    decrypt_message(message, &key_pair);

    return 0;
}