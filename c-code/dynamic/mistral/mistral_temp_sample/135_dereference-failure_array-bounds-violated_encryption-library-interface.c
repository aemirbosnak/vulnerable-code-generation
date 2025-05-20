#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    int key_len;
} EncryptionKey;

void generate_key(EncryptionKey *key) {
    key->key = malloc(256 * sizeof(char));
    for (int i = 0; i < 256; ++i) {
        key->key[i] = rand() % 26 + 'a';
    }
    key->key_len = 256;
}

char* encrypt(EncryptionKey key, char *plaintext) {
    char *ciphertext = malloc(key.key_len * strlen(plaintext) * sizeof(char));

    for (int i = 0; plaintext[i] != '\0'; ++i) {
        ciphertext[i * key.key_len] = plaintext[i] ^ key.key[i % key.key_len];
    }

    return ciphertext;
}

int main() {
    EncryptionKey key;
    generate_key(&key);

    char plaintext[] = "SECRET_MESSAGE";
    char *ciphertext = encrypt(key, plaintext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    free(ciphertext);

    // Intentionally accessing out of bounds array element in the key structure
    printf("Key length: %d\n", key.key[key.key_len]);

    return 0;
}
