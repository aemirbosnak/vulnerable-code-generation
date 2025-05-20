#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    char *key;
    int length;
} EncryptionKey;

void generate_key(EncryptionKey *key) {
    key->key = (char *) malloc(256 * sizeof(char));
    printf("Enter a 256 character key: ");
    fgets(key->key, 256, stdin);
    key->length = strlen(key->key);
}

char encrypt(char c, EncryptionKey key) {
    int idx = (key.length + tolower(c) - 97) % key.length;
    return key.key[idx];
}

char* encrypt_string(char *input, EncryptionKey key) {
    int len = strlen(input);
    char *encrypted = (char *) malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        if (input[i] != '\0') {
            encrypted[i] = encrypt(input[i], key);
        } else {
            encrypted[i] = '\0';
        }
    }
    return encrypted;
}

void free_key(EncryptionKey *key) {
    free(key->key);
}

int main() {
    EncryptionKey my_key;
    generate_key(&my_key);
    char *plaintext = "SECRET MESSAGE";
    char *encrypted_text = encrypt_string(plaintext, my_key);
    printf("Encrypted text: %s\n", encrypted_text);

    // Dereference failure vulnerability intentionally introduced here
    printf("Key: %s\n", my_key.key);

    free_key(&my_key);
    return 0;
}
