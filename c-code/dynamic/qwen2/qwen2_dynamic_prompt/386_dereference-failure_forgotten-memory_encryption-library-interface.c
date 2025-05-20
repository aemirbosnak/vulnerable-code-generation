#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *data;
    size_t length;
} EncryptedData;

EncryptedData* encrypt(const char *plaintext) {
    EncryptedData *encrypted = malloc(sizeof(EncryptedData));
    if (!encrypted) return NULL;

    encrypted->length = strlen(plaintext);
    encrypted->data = malloc(encrypted->length + 1);
    if (!encrypted->data) {
        free(encrypted);
        return NULL;
    }

    strcpy(encrypted->data, plaintext);

    // Simulate encryption by appending an 'X' to each character
    for (size_t i = 0; i < encrypted->length; i++) {
        encrypted->data[i] += 1;
    }
    encrypted->data[encrypted->length] = '\0';

    return encrypted;
}

void decrypt(EncryptedData *encrypted) {
    if (!encrypted || !encrypted->data) return;

    // Simulate decryption by subtracting an 'X' from each character
    for (size_t i = 0; i < encrypted->length; i++) {
        encrypted->data[i] -= 1;
    }
}

int main() {
    const char *plaintext = "Hello, World!";
    EncryptedData *encrypted = encrypt(plaintext);

    if (!encrypted) {
        fprintf(stderr, "Encryption failed\n");
        return 1;
    }

    printf("Encrypted: %s\n", encrypted->data);

    decrypt(encrypted);
    printf("Decrypted: %s\n", encrypted->data);

    // Intentional dereference failure: forgetting to free the allocated memory
    // This will cause a memory leak

    return 0;
}
