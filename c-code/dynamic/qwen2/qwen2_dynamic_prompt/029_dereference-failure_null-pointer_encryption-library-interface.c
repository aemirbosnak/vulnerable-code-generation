#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

// Simulated encryption function
void encrypt(char *data, int key) {
    if (data == NULL) {
        printf("Error: Data is null\n");
        return;
    }
    while (*data) {
        *data = *data + key;
        data++;
    }
}

int main() {
    char *plaintext = "Hello, World!";
    int key = 3;

    // Simulate a scenario where the plaintext pointer is accidentally set to NULL
    plaintext = NULL;

    // Attempt to encrypt the plaintext
    encrypt(plaintext, key);

    return 0;
}
