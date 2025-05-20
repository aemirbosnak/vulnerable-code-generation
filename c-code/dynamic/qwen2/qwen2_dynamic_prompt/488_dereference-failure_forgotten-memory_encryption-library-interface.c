#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simulated encryption function
void encrypt(char *data, int key) {
    while (*data) {
        *data = *data + key;
        data++;
    }
}

// Simulated decryption function
void decrypt(char *data, int key) {
    while (*data) {
        *data = *data - key;
        data++;
    }
}

// Encryption library interface
int encrypt_data(const char *input, char **output, int key) {
    if (!input || !output) return -1;

    // Allocate memory for encrypted data
    *output = (char *)malloc(strlen(input) + 1);
    if (!*output) return -2;

    // Encrypt data
    encrypt((char *)input, key);

    return 0;
}

// Decryption library interface
int decrypt_data(const char *input, char **output, int key) {
    if (!input || !output) return -1;

    // Allocate memory for decrypted data
    *output = (char *)malloc(strlen(input) + 1);
    if (!*output) return -2;

    // Decrypt data
    decrypt((char *)input, key);

    return 0;
}

int main() {
    const char *plaintext = "Hello, World!";
    char *encrypted = NULL;
    char *decrypted = NULL;
    int key = 3;

    // Encrypt data
    int result = encrypt_data(plaintext, &encrypted, key);
    if (result != 0) {
        printf("Encryption failed with error: %d\n", result);
        return 1;
    }

    // Print encrypted data
    printf("Encrypted: %s\n", encrypted);

    // Decrypt data
    result = decrypt_data(encrypted, &decrypted, key);
    if (result != 0) {
        printf("Decryption failed with error: %d\n", result);
        free(encrypted); // Free allocated memory before exiting
        return 1;
    }

    // Print decrypted data
    printf("Decrypted: %s\n", decrypted);

    // Free allocated memory
    free(encrypted);
    free(decrypted);

    return 0;
}
