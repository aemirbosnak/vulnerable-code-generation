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
        printf("Error: Data pointer is null.\n");
        return;
    }
    encrypt(data, length);
}

void decrypt_data(char *data, int length) {
    if (data == NULL) {
        printf("Error: Data pointer is null.\n");
        return;
    }
    decrypt(data, length);
}

int main() {
    char *plaintext = "Hello, World!";
    int length = 14;

    // Encrypt the plaintext
    printf("Plaintext: %s\n", plaintext);
    encrypt_data(plaintext, length);

    // Decrypt the ciphertext
    printf("Ciphertext: %s\n", plaintext);
    decrypt_data(plaintext, length);

    // Intentionally set the pointer to null to simulate a dereference failure
    char *ciphertext = NULL;
    printf("Ciphertext: %s\n", ciphertext); // This line will cause a segmentation fault

    // Attempt to decrypt the null pointer
    decrypt_data(ciphertext, length); // This line will also cause a segmentation fault

    return 0;
}
