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
    printf("Encrypted: ");
    encrypt(buffer, length);
    for (int i = 0; i < length; i++) {
        printf("%c", buffer[i]);
    }
    printf("\n");

    // Correct usage
    buffer = (char *)malloc(length * sizeof(char));
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Encrypt some data
    strcpy(buffer, "Hello, World!");
    printf("Original: %s\n", buffer);

    encrypt(buffer, length);
    printf("Encrypted: ");
    for (int i = 0; i < length; i++) {
        printf("%c", buffer[i]);
    }
    printf("\n");

    // Decrypt the data
    decrypt(buffer, length);
    printf("Decrypted: %s\n", buffer);

    free(buffer);
}

int main() {
    vulnerable_function();
    return 0;
}
