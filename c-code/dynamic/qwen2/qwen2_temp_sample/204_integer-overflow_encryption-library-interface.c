#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 1024

typedef struct {
    unsigned char key[MAX_KEY_SIZE];
    size_t key_size;
} EncryptionKey;

void initialize_key(EncryptionKey *key, const unsigned char *input, size_t input_size) {
    if (input_size > MAX_KEY_SIZE) {
        fprintf(stderr, "Error: Key size exceeds maximum allowed.\n");
        exit(EXIT_FAILURE);
    }
    memcpy(key->key, input, input_size);
    key->key_size = input_size;
}

unsigned char* encrypt(const EncryptionKey *key, const unsigned char *plaintext, size_t plaintext_size) {
    unsigned char *ciphertext = malloc(plaintext_size + key->key_size);
    if (!ciphertext) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    size_t i;
    for (i = 0; i < plaintext_size; i++) {
        ciphertext[i] = plaintext[i] ^ key->key[i % key->key_size];
    }

    // Integer overflow vulnerability
    size_t offset = 2147483647; // Maximum value for signed int on most systems
    ciphertext[plaintext_size] = offset;
    ciphertext[plaintext_size + 1] = offset >> 8;

    return ciphertext;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <key> <plaintext>\n", argv[0]);
        return EXIT_FAILURE;
    }

    EncryptionKey key;
    initialize_key(&key, (unsigned char *)argv[1], strlen(argv[1]));

    unsigned char *plaintext = (unsigned char *)argv[2];
    size_t plaintext_size = strlen((char *)plaintext);

    unsigned char *ciphertext = encrypt(&key, plaintext, plaintext_size);

    printf("Ciphertext: ");
    for (size_t i = 0; i <= plaintext_size + 1; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    free(ciphertext);
    return EXIT_SUCCESS;
}
