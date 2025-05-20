#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

typedef struct {
    char key[BUFFER_SIZE];
} EncryptionKey;

void encrypt_data(const char *data, const EncryptionKey *key, char *output) {
    if (data == NULL || key == NULL || output == NULL) {
        fprintf(stderr, "Error: Null pointer encountered\n");
        exit(EXIT_FAILURE);
    }

    int len = strlen(data);
    for (int i = 0; i < len; i++) {
        output[i] = data[i] ^ key->key[i % BUFFER_SIZE];
    }
    output[len] = '\0';
}

int main() {
    char data[BUFFER_SIZE];
    EncryptionKey key;
    char output[BUFFER_SIZE];

    printf("Enter data to encrypt: ");
    fgets(data, BUFFER_SIZE, stdin);

    // Simulate a null pointer scenario by setting key pointer to NULL
    EncryptionKey *key_ptr = NULL;

    // Intentionally dereferencing a null pointer
    strcpy(key.key, "secret_key");
    encrypt_data(data, key_ptr, output); // This will cause a dereference failure

    return 0;
}
