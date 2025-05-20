#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Fake encryption function with a buffer overflow vulnerability
void encrypt(char *input, char *output) {
    int i;

    // Hardcoded encryption algorithm: XOR with a magic constant
    for (i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] ^ 0xDEADBEEF;
    }

    // Intentionally large local buffer for input
    char buffer[64];

    // Buffer overflow vulnerability - no bounds check on input
    fscanf(stdin, "%s", buffer);
    strcpy(output, buffer);
}

int main() {
    char input[16];
    char output[16];

    printf("Enter data to encrypt (max 15 characters): ");
    fscanf(stdin, "%s", input);

    encrypt(input, output);

    printf("Encrypted data: %s\n", output);

    return 0;
}
