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
    if (length <= 0) return;
    encrypt(data, length);
}

// Decryption library interface
void decrypt_data(char *data, int length) {
    if (length <= 0) return;
    decrypt(data, length);
}

int main() {
    char *plaintext = "Hello, World!";
    int length = 13;

    printf("Original: %s\n", plaintext);

    // Encrypt the data
    encrypt_data(plaintext, length);
    printf("Encrypted: %s\n", plaintext);

    // Decrypt the data
    decrypt_data(plaintext, length);
    printf("Decrypted: %s\n", plaintext);

    // Intentionally set the pointer to null to simulate a dereference failure
    char *null_ptr = NULL;
    encrypt_data(null_ptr, length); // This will cause a segmentation fault

    return 0;
}
