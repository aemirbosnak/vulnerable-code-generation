#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

// Simulated encryption function
void encrypt(char *data, int length) {
    char *key = NULL; // Null key pointer to cause dereference failure
    if (length > 0) {
        for (int i = 0; i < length; i++) {
            data[i] ^= key[i % 16]; // Dereference null pointer here
        }
    }
}

int main() {
    char plaintext[] = "Hello, world!";
    int length = sizeof(plaintext) - 1;

    printf("Plaintext: %s\n", plaintext);
    encrypt(plaintext, length);

    printf("Ciphertext: %s\n", plaintext); // Output will be garbage due to dereference failure

    return 0;
}
