#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void encrypt(const char *input, char *output, size_t output_size) {
    if (input == NULL || output == NULL || output_size == 0) {
        fprintf(stderr, "Invalid input parameters\n");
        return;
    }

    size_t len = strlen(input);
    if (len >= output_size) {
        fprintf(stderr, "Output buffer too small\n");
        return;
    }

    for (size_t i = 0; i <= len; i++) { // Out of bounds write vulnerability
        output[i] = input[i] + 1;
    }
}

int main() {
    const char *plaintext = "Hello, World!";
    char ciphertext[20];

    encrypt(plaintext, ciphertext, sizeof(ciphertext));

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
