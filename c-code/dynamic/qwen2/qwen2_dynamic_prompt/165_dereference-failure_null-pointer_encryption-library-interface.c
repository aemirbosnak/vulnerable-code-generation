#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

// Simulated encryption function
void encrypt(char *data, int length) {
    for (int i = 0; i < length; i++) {
        data[i] += 1;
    }
}

// Simulated decryption function
void decrypt(char *data, int length) {
    for (int i = 0; i < length; i++) {
        data[i] -= 1;
    }
}

// Encryption library interface
void encrypt_data(char *data, int length) {
    if (data == NULL) {
        printf("Error: Data pointer is null\n");
        return;
    }
    encrypt(data, length);
}

// Decryption library interface
void decrypt_data(char *data, int length) {
    if (data == NULL) {
        printf("Error: Data pointer is null\n");
        return;
    }
    decrypt(data, length);
}

int main() {
    char *plaintext = "Hello, World!";
    int length = 13;

    // Encrypting the plaintext
    printf("Original Text: %s\n", plaintext);
    encrypt_data(plaintext, length);
    printf("Encrypted Text: %s\n", plaintext);

    // Decrypting the ciphertext
    decrypt_data(plaintext, length);
    printf("Decrypted Text: %s\n", plaintext);

    // Intentionally passing a null pointer to demonstrate dereference failure
    char *null_pointer = NULL;
    printf("Attempting to encrypt with null pointer...\n");
    encrypt_data(null_pointer, length);

    return 0;
}
