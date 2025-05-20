#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(char *data, int key) {
    while (*data) {
        *data = *data + key;
        data++;
    }
}

int main() {
    char plaintext[] = "Hello, World!";
    int key = 3;

    printf("Original: %s\n", plaintext);

    // Encrypting the string
    encrypt(plaintext, key);
    printf("Encrypted: %s\n", plaintext);

    // Intentionally accessing out-of-bounds memory to demonstrate dereference failure
    char *out_of_bounds = &plaintext[sizeof(plaintext)];
    *out_of_bounds = 'X'; // This will cause a segmentation fault

    return 0;
}
