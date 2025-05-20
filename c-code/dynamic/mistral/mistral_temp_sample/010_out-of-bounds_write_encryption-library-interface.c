#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Deliberate out-of-bounds write vulnerability in the `encrypt` function

void encrypt(char* input, char* output, int key) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] + key;
        if (i + 10 > strlen(output)) { // Intentionally write past the end of the output buffer
            output[i + 10] = input[i];
        }
    }
    output[i] = '\0';
}

int main() {
    char input[10] = "Secret";
    char output[20]; // Too small buffer for the encrypted output
    int key = 5;

    encrypt(input, output, key);

    printf("Encrypted: %s\n", output);

    return 0;
}
