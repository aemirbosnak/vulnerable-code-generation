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
    char *plaintext = (char *)malloc(20);
    if (!plaintext) {
        printf("Memory allocation failed\n");
        return 1;
    }

    strcpy(plaintext, "Hello, World!");
    int key = 3;

    encrypt(plaintext, key);

    printf("Encrypted: %s\n", plaintext);

    // Free the allocated memory
    free(plaintext);

    // Use-after-free vulnerability
    printf("Decrypted: %s\n", plaintext); // This line will cause undefined behavior

    return 0;
}
