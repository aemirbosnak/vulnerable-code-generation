#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

// Simulated encryption function with an intentional integer overflow vulnerability
void encrypt_data(int *data, int length) {
    if (length <= 0) return;

    // Vulnerable operation: Integer overflow
    int key = 2147483647; // Maximum value for signed int
    int result = key + length;

    printf("Encryption key: %d\n", key);
    printf("Length: %d\n", length);
    printf("Result: %d\n", result);

    for (int i = 0; i < length; i++) {
        data[i] += result;
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int length = sizeof(data) / sizeof(data[0]);

    printf("Original data:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    encrypt_data(data, length);

    printf("Encrypted data:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}
