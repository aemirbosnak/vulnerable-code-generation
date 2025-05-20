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
    char *encrypted_text = (char *)malloc(14);
    if (!encrypted_text) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Encrypt the plaintext
    encrypt(encrypted_text, key);

    // Print the encrypted text
    printf("Encrypted: %s\n", encrypted_text);

    // Free the allocated memory
    free(encrypted_text);

    // Dereference a freed pointer to cause a crash
    printf("Decrypted: %s\n", encrypted_text); // This line will cause a segmentation fault

    return 0;
}
