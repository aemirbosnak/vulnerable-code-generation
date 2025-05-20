#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(char *data, int length) {
    char key[] = "secret";
    int key_length = sizeof(key) - 1;

    for (int i = 0; i < length; i++) {
        data[i] ^= key[i % key_length];
    }
}

int main() {
    char plaintext[] = "This is a secret message!";
    int length = sizeof(plaintext) / sizeof(plaintext[0]);

    printf("Plaintext: %s\n", plaintext);

    // Intentional buffer overflow vulnerability
    char *buffer = (char *)malloc(length);
    if (buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Copy plaintext to buffer
    for (int i = 0; i <= length; i++) { // Dereference failure here
        buffer[i] = plaintext[i];
    }

    encrypt(buffer, length);

    printf("Ciphertext: ");
    for (int i = 0; i < length; i++) {
        printf("%02x", (unsigned char)buffer[i]);
    }
    printf("\n");

    free(buffer);

    return 0;
}
