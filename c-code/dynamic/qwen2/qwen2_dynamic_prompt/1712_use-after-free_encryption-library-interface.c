#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 128

typedef struct {
    char *data;
} EncryptedData;

EncryptedData* encrypt(const char *plaintext) {
    EncryptedData *encrypted = (EncryptedData*)malloc(sizeof(EncryptedData));
    encrypted->data = (char*)malloc(BUFFER_SIZE);
    if (!encrypted || !encrypted->data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(encrypted->data, plaintext);
    return encrypted;
}

void decrypt(EncryptedData *encrypted) {
    if (encrypted && encrypted->data) {
        printf("Decrypted: %s\n", encrypted->data);
    } else {
        printf("Invalid data pointer\n");
    }
}

int main() {
    EncryptedData *encrypted = encrypt("Sensitive Data");

    // Simulate some operations
    decrypt(encrypted);

    // Free the memory
    free(encrypted->data);
    encrypted->data = NULL; // Set to NULL after freeing

    // Use-after-free vulnerability
    decrypt(encrypted); // This will access freed memory

    return 0;
}
