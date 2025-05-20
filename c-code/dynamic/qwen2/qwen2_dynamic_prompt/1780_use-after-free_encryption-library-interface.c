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
    decrypt(encrypted);

    // Use-after-free vulnerability
    free(encrypted->data);
    encrypted->data = NULL; // Prevent dangling pointer

    // Exploit the use-after-free
    decrypt(encrypted); // This should crash due to dereferencing freed memory

    return 0;
}
