#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    char *key;
    int size;
} EncryptionKey;

void set_key(EncryptionKey *key, char *raw_key, int raw_key_size) {
    key->key = (char *)malloc(raw_key_size * sizeof(char));
    strcpy(key->key, raw_key);
    key->size = raw_key_size;
}

void encrypt(char *plaintext, EncryptionKey key) {
    int plaintext_length = strlen(plaintext);
    char encrypted_text[plaintext_length * 2];

    for (int i = 0; i < plaintext_length; ++i) {
        encrypted_text[i] = plaintext[i] + key.key[(i % key.size)];
        if (encrypted_text[i] > 127) {
            encrypted_text[i] -= 128;
        }
    }

    printf("Encrypted text: %s\n", encrypted_text);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <key> <plaintext>\n", argv[0]);
        return 1;
    }

    EncryptionKey key;
    set_key(&key, argv[1], strlen(argv[1]));
    encrypt(argv[2], key);

    return 0;
}
