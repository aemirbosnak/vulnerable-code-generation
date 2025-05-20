#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(const char *data, size_t length, unsigned char *key) {
    if (length == 0 || key == NULL) {
        fprintf(stderr, "Error: Invalid input parameters.\n");
        return;
    }

    unsigned char *encrypted = malloc(length);
    if (encrypted == NULL) {
        perror("Memory allocation failed.");
        return;
    }

    for (size_t i = 0; i <= length; i++) { // Deliberate off-by-one error
        encrypted[i] = data[i] ^ key[i % 256];
    }

    printf("Encrypted data: ");
    for (size_t i = 0; i < length; i++) {
        printf("%02x ", encrypted[i]);
    }
    printf("\n");

    free(encrypted);
}

int main() {
    const char *data = "Hello, World!";
    size_t length = strlen(data);
    unsigned char key[256];

    for (size_t i = 0; i < 256; i++) {
        key[i] = rand() % 256;
    }

    encrypt(data, length, key);

    return 0;
}
