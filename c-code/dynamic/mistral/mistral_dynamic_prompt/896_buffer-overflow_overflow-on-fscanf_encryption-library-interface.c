#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Fake Encryption Library
void encrypt(char* input, char* output) {
    int i;
    for (i = 0; input[i]; i++) {
        output[i] = toupper(input[i]);
    }
    output[i] = '\0';
}

int main() {
    char input[10];
    char encrypted[100]; // Vulnerable to buffer overflow

    printf("Enter a message to encrypt: ");
    fscanf(stdin, "%s", input);

    encrypt(input, encrypted);
    printf("Encrypted message: %s\n", encrypted);

    return 0;
}
