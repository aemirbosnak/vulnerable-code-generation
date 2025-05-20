#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simulated encryption function
void encrypt(char *data, int key) {
    if (data == NULL) {
        printf("Error: Data is null\n");
        return;
    }
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] += key;
    }
}

// Simulated decryption function
void decrypt(char *data, int key) {
    if (data == NULL) {
        printf("Error: Data is null\n");
        return;
    }
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] -= key;
    }
}

// Encryption library interface
void encrypt_data(char *data, int key) {
    encrypt(data, key);
}

// Decryption library interface
void decrypt_data(char *data, int key) {
    decrypt(data, key);
}

int main() {
    char *plaintext = "Hello, World!";
    int key = 3;

    // Encrypting the plaintext
    printf("Original Text: %s\n", plaintext);
    encrypt_data(plaintext, key);
    printf("Encrypted Text: %s\n", plaintext);

    // Decrypting the ciphertext
    decrypt_data(plaintext, key);
    printf("Decrypted Text: %s\n", plaintext);

    // Intentionally causing a dereference failure by passing a null pointer
    char *ciphertext = NULL;
    printf("Attempting to decrypt null data...\n");
    decrypt_data(ciphertext, key); // This will cause a dereference failure

    return 0;
}
