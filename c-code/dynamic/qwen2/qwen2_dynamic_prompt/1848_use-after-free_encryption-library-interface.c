#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simulated encryption function
void encrypt(char *data) {
    for (int i = 0; data[i]; i++) {
        data[i] += 3;
    }
}

// Simulated decryption function
void decrypt(char *data) {
    for (int i = 0; data[i]; i++) {
        data[i] -= 3;
    }
}

// Encryption library interface
typedef struct {
    char *key;
} EncryptionLibrary;

// Initialize the encryption library with a key
EncryptionLibrary* init_library(const char *key) {
    EncryptionLibrary *lib = (EncryptionLibrary*)malloc(sizeof(EncryptionLibrary));
    lib->key = strdup(key);
    return lib;
}

// Encrypt data using the library's key
void encrypt_data(EncryptionLibrary *lib, char *data) {
    if (lib == NULL || lib->key == NULL) {
        fprintf(stderr, "Error: Library not initialized properly.\n");
        exit(EXIT_FAILURE);
    }
    encrypt(data);
}

// Decrypt data using the library's key
void decrypt_data(EncryptionLibrary *lib, char *data) {
    if (lib == NULL || lib->key == NULL) {
        fprintf(stderr, "Error: Library not initialized properly.\n");
        exit(EXIT_FAILURE);
    }
    decrypt(data);
}

// Free the encryption library
void free_library(EncryptionLibrary *lib) {
    if (lib != NULL) {
        free(lib->key);
        free(lib);
    }
}

int main() {
    EncryptionLibrary *lib = init_library("secretKey");

    char *data = (char*)malloc(20 * sizeof(char));
    strcpy(data, "Hello, World!");

    printf("Original Data: %s\n", data);

    encrypt_data(lib, data);
    printf("Encrypted Data: %s\n", data);

    decrypt_data(lib, data);
    printf("Decrypted Data: %s\n", data);

    // Use-after-free vulnerability
    free_library(lib);
    printf("Data after free: %s\n", data); // Use-after-free

    free(data);

    return 0;
}
