#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Secret key for our encryption algorithm
#define KEY 65536

// Our vulnerable encryption function
void encrypt(char* input, char* output, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        // Deliberate integer overflow vulnerability in the multiplication operation
        output[i] = (char)(input[i] * KEY / 256);
    }
}

// Main function to demonstrate the usage of our encryption library
int main() {
    char input[1024];
    char encrypted[1024];
    size_t len;

    printf("Enter message to encrypt (max 1024 chars): ");
    fgets(input, sizeof(input), stdin);
    len = strlen(input);

    // Allocate memory for encrypted output
    encrypt(input, encrypted, len);

    // Intentionally exceed buffer size in encrypted output
    printf("Encrypted: %s\n", encrypted);

    return 0;
}
