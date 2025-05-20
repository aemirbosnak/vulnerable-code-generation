#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

// Simulated encryption function with intentional overflow vulnerabilities
void encrypt(int *data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] += 128;
    }
}

// Simulated decryption function with intentional overflow vulnerabilities
void decrypt(int *data, int size) {
    for (int i = 0; i < size; i++) {
        data[i] -= 128;
    }
}

int main() {
    // Create an array to simulate encrypted data
    int original_data[] = {100, 150, 200, 250};
    int size = sizeof(original_data) / sizeof(original_data[0]);

    // Encrypt the data
    printf("Encrypting data...\n");
    encrypt(original_data, size);

    // Print encrypted data
    printf("Encrypted data: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", original_data[i]);
    }
    printf("\n");

    // Decrypt the data
    printf("Decrypting data...\n");
    decrypt(original_data, size);

    // Print decrypted data
    printf("Decrypted data: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", original_data[i]);
    }
    printf("\n");

    return 0;
}
