#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Simple Encryption Library Interface

void encrypt(char* input, char* output) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        output[i] = toupper(input[i]) + 3;
        if (output[i] > 'Z') output[i] -= 26;
    }
    output[i] = '\0';
}

int main(int argc, char* argv[]) {
    char input[10];
    char output[100];

    if (argc != 2) {
        printf("Usage: %s <plaintext>\n", argv[0]);
        return 1;
    }

    fscanf(stdin, "%s", input);
    encrypt(input, output);
    printf("Encrypted: %s\n", output);

    // Intentionally vulnerable to buffer overflow in fscanf
    fscanf(stdin, "%s", output);

    return 0;
}
