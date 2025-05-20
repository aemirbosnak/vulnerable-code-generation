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

// Function to demonstrate invalid pointer dereference
void vulnerable_function() {
    char *buffer = NULL;
    int length = 10;

    // Attempt to use an uninitialized pointer
    printf("Encrypting...\n");
    encrypt(buffer, length);

    // Attempt to free a null pointer
    printf("Freeing buffer...\n");
    free(buffer);
}

int main() {
    printf("Starting encryption library test...\n");
    vulnerable_function();
    printf("Test completed.\n");
    return 0;
}
