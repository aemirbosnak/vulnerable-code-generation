#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(char *data, int length) {
    for (int i = 0; i < length; i++) {
        data[i] += 3;
    }
}

int main() {
    char *plaintext = "Hello, World!";
    int length = 14;

    // Allocate memory dynamically
    char *encryptedtext = (char *)malloc(length * sizeof(char));
    if (encryptedtext == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Encrypt the plaintext
    encrypt(encryptedtext, length);

    // Print the encrypted text
    printf("Encrypted: %s\n", encryptedtext);

    // Free the allocated memory
    free(encryptedtext);

    // Dereference a freed pointer to cause a crash
    printf("Decrypted: %s\n", encryptedtext); // This line will cause a segmentation fault

    return 0;
}
