#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

// Simulated encryption function
void encrypt(char *data, int length) {
    for (int i = 0; i < length; i++) {
        data[i] += 3;
    }
}

// Simulated decryption function
void decrypt(char *data, int length) {
    for (int i = 0; i < length; i++) {
        data[i] -= 3;
    }
}

// Encryption library interface
void encrypt_data(char *data, int length) {
    if (data == NULL) {
        printf("Error: Invalid pointer\n");
        exit(1);
    }
    encrypt(data, length);
}

// Decryption library interface
void decrypt_data(char *data, int length) {
    if (data == NULL) {
        printf("Error: Invalid pointer\n");
        exit(1);
    }
    decrypt(data, length);
}

int main() {
    char *plaintext = "Hello, World!";
    int length = 13;

    // Encrypting the plaintext
    printf("Plaintext: %s\n", plaintext);
    encrypt_data(plaintext, length);

    // Decrypting the ciphertext
    printf("Ciphertext: %s\n", plaintext);
    decrypt_data(plaintext, length);

    return 0;
}
