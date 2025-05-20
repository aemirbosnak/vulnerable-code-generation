#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *data;
} EncryptedData;

EncryptedData* encrypt_data(const char *plaintext) {
    EncryptedData *encrypted = (EncryptedData*)malloc(sizeof(EncryptedData));
    encrypted->data = (char*)malloc(BUFFER_SIZE);
    if (!encrypted || !encrypted->data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(encrypted->data, plaintext);
    return encrypted;
}

void decrypt_data(EncryptedData *encrypted) {
    if (encrypted && encrypted->data) {
        printf("Decrypted: %s\n", encrypted->data);
    } else {
        printf("Invalid data pointer\n");
    }
}

int main() {
    EncryptedData *data = encrypt_data("Sensitive Information");

    // Simulate some operations
    decrypt_data(data);

    // Free the memory
    free(data->data);
    data->data = NULL; // Set to NULL to avoid dangling pointer

    // Use-after-free vulnerability
    decrypt_data(data); // This will cause undefined behavior

    return 0;
}
