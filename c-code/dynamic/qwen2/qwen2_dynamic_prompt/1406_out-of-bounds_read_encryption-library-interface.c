#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void encrypt(const char *input, char *output, size_t key) {
    size_t len = strlen(input);
    for (size_t i = 0; i <= len; i++) { // Out of bounds read vulnerability here
        output[i] = input[i] + key;
    }
}

int main() {
    const char *plaintext = "Hello, World!";
    char ciphertext[14];
    size_t key = 3;

    encrypt(plaintext, ciphertext, key);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
