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

// Function to demonstrate invalid pointer dereference vulnerability
void vulnerable_function() {
    char *buffer = NULL;
    int length = 10;

    // Allocate memory dynamically
    buffer = (char *)malloc(length * sizeof(char));
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Encrypt some data
    encrypt(buffer, length);

    // Intentionally set buffer to an invalid pointer
    buffer = NULL;

    // Attempt to decrypt using the invalid pointer
    decrypt(buffer, length); // Vulnerability here

    // Free allocated memory
    free(buffer);
}

int main() {
    printf("Starting encryption demonstration...\n");
    vulnerable_function();
    printf("Encryption demonstration completed.\n");
    return 0;
}
