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
    char *plaintext = (char *)malloc(100);
    if (!plaintext) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    strcpy(plaintext, "Hello, World!");
    printf("Plaintext: %s\n", plaintext);

    encrypt(plaintext, 3);
    printf("Encrypted: %s\n", plaintext);

    free(plaintext);

    // Use-after-free vulnerability
    printf("After free: %s\n", plaintext); // This line will cause undefined behavior

    return 0;
}
