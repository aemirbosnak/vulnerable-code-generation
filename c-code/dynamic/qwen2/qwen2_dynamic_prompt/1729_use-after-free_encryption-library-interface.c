#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void encrypt(char *data) {
    int i;
    for (i = 0; data[i] != '\0'; i++) {
        data[i] += 3;
    }
}

int main() {
    char *plaintext = "Hello, World!";
    printf("Plaintext: %s\n", plaintext);

    // Allocate memory dynamically
    char *encrypted = (char *)malloc(14);
    if (encrypted == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Encrypt the plaintext
    strcpy(encrypted, plaintext);
    encrypt(encrypted);
    printf("Encrypted: %s\n", encrypted);

    // Free the allocated memory
    free(encrypted);

    // Use after free vulnerability
    printf("Encrypted after free: %s\n", encrypted); // This line will cause undefined behavior

    return 0;
}
