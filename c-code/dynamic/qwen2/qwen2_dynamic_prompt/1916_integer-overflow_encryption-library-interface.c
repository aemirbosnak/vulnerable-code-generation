#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

// Simulated encryption function with an intentional integer overflow vulnerability
void encrypt(int *data, int length) {
    int key = 123456789;
    for (int i = 0; i < length; i++) {
        data[i] += key; // Intentional overflow here
    }
}

// Function to simulate decryption
void decrypt(int *data, int length) {
    int key = 123456789;
    for (int i = 0; i < length; i++) {
        data[i] -= key; // Correcting the overflow
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int length = sizeof(data) / sizeof(data[0]);

    printf("Original Data: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    encrypt(data, length);

    printf("Encrypted Data: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    decrypt(data, length);

    printf("Decrypted Data: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
