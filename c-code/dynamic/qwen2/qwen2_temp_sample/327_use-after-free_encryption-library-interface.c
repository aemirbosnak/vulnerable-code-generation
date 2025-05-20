#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simulated encryption function
void encrypt(char *data, int key) {
    for (int i = 0; data[i] != '\0'; i++) {
        data[i] += key;
    }
}

int main() {
    char *plaintext = (char *)malloc(20 * sizeof(char));
    if (plaintext == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    strcpy(plaintext, "Hello, World!");
    printf("Plaintext: %s\n", plaintext);

    // Encrypt the string
    encrypt(plaintext, 3);
    printf("Encrypted: %s\n", plaintext);

    // Free the memory
    free(plaintext);

    // Use after free vulnerability
    printf("Encrypted after free: %s\n", plaintext); // Accessing freed memory

    return 0;
}
