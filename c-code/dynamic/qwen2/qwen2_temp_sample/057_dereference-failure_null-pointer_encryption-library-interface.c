#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *data;
} EncryptionKey;

void generate_key(EncryptionKey *key, const char *password) {
    key->data = (char *)malloc(BUFFER_SIZE);
    if (key->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(key->data, password);
}

void encrypt_data(const char *plaintext, EncryptionKey *key, char *ciphertext) {
    if (key->data == NULL) {
        fprintf(stderr, "Encryption key is null\n");
        return;
    }
    int len = strlen(plaintext);
    for (int i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i] ^ key->data[i % strlen(key->data)];
    }
    ciphertext[len] = '\0';
}

void free_key(EncryptionKey *key) {
    if (key->data != NULL) {
        free(key->data);
        key->data = NULL;
    }
}

int main() {
    EncryptionKey myKey;
    char plaintext[BUFFER_SIZE];
    char ciphertext[BUFFER_SIZE];

    generate_key(&myKey, "secret");

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    encrypt_data(plaintext, &myKey, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    free_key(&myKey);

    return 0;
}
