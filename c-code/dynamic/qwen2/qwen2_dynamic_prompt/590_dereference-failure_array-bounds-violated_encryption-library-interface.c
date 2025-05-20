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
    int length = sizeof(plaintext) - 1;

    printf("Plaintext: %s\n", plaintext);

    // Intentionally causing an array bounds violation by accessing out-of-bounds index
    encrypt(plaintext, length + 1); // One byte beyond the actual length

    printf("Encrypted: %s\n", plaintext);

    return 0;
}
