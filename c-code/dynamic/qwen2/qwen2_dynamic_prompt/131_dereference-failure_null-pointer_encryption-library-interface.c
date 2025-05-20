#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

// Simulated encryption function that uses a null pointer
void encrypt(char *data, int length) {
    char *key = NULL;
    for (int i = 0; i < length; i++) {
        data[i] ^= key[i % 16]; // Dereference null pointer here
    }
}

int main() {
    char plaintext[] = "This is a secret message";
    int length = sizeof(plaintext) - 1;

    printf("Plaintext: %s\n", plaintext);
    encrypt(plaintext, length); // Call the vulnerable encryption function

    printf("Encrypted: %s\n", plaintext);

    return 0;
}
