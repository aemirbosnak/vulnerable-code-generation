//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 1024

typedef struct {
    char *public_key;
    char *private_key;
} KeyPair;

KeyPair generate_keys() {
    char *public_key = malloc(MAX_KEY_LENGTH);
    char *private_key = malloc(MAX_KEY_LENGTH);

    for (int i = 0; i < MAX_KEY_LENGTH; i++) {
        public_key[i] = rand() % 2? '0' : '1';
        private_key[i] = rand() % 2? '0' : '1';
    }

    return (KeyPair) { public_key, private_key };
}

char *encrypt(char *message, char *public_key) {
    char *encrypted_message = malloc(strlen(message) + 1);

    for (int i = 0; i < strlen(message); i++) {
        encrypted_message[i] = message[i] ^ public_key[i % MAX_KEY_LENGTH];
    }

    return encrypted_message;
}

char *decrypt(char *encrypted_message, char *private_key) {
    char *decrypted_message = malloc(strlen(encrypted_message) + 1);

    for (int i = 0; i < strlen(encrypted_message); i++) {
        decrypted_message[i] = encrypted_message[i] ^ private_key[i % MAX_KEY_LENGTH];
    }

    return decrypted_message;
}

int main() {
    KeyPair keys = generate_keys();
    char *public_key = keys.public_key;
    char *private_key = keys.private_key;

    char *message = "Hello, world!";
    char *encrypted_message = encrypt(message, public_key);
    printf("Encrypted message: %s\n", encrypted_message);

    char *decrypted_message = decrypt(encrypted_message, private_key);
    printf("Decrypted message: %s\n", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);
    free(public_key);
    free(private_key);

    return 0;
}