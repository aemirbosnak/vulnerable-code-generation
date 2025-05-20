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
    char *plaintext = "Hello, World!";
    int key = 3;

    // Allocate memory dynamically
    char *encryptedtext = (char *)malloc(14);
    if (!encryptedtext) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Encrypt the plaintext
    encrypt(encryptedtext, key);

    // Print the encrypted text
    printf("Encrypted: %s\n", encryptedtext);

    // Free the allocated memory
    free(encryptedtext);

    // Dereference a freed pointer to cause a crash
    printf("Decrypted: %s\n", encryptedtext); // This line will cause a segmentation fault

    return 0;
}
