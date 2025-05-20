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

    printf("Plaintext: %s\n", plaintext);

    // Simulate an encryption call
    encrypt(plaintext, key);

    printf("Encrypted: %s\n", plaintext);

    return 0;
}
