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

// Function to demonstrate invalid pointer usage
void vulnerable_function() {
    char *buffer = NULL;
    int length = 10;

    // Attempt to encrypt data using an uninitialized pointer
    encrypt(buffer, length);

    // Freeing the null pointer is safe but unnecessary
    free(buffer);
}

int main() {
    printf("Starting encryption demonstration...\n");
    vulnerable_function();
    printf("Encryption demonstration completed.\n");

    return 0;
}
