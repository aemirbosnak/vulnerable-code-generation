#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

// Function to simulate an encryption operation
void encrypt(int *data, int length) {
    int key = 7;
    for (int i = 0; i <= length; i++) { // Deliberate off-by-one error
        data[i] += key;
    }
}

// Main function demonstrating the encryption library interface
int main() {
    int data[] = {1, 2, 3, 4, 5};
    int length = sizeof(data) / sizeof(data[0]);

    printf("Original data: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    encrypt(data, length);

    printf("Encrypted data: ");
    for (int i = 0; i <= length; i++) { // Off-by-one error here
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
