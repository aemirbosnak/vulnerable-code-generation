#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Fake Encryption Library Interface
void encrypt(char *input, char *output, int size) {
    strcpy(output, input);
    // Deliberate buffer overflow by using gets instead of fgets
    gets(output + size);
}

int main() {
    char input[10];
    char output[100]; // Allocate large buffer to induce buffer overflow

    printf("Enter a message to encrypt: ");
    fgets(input, sizeof(input), stdin);

    encrypt(input, output, sizeof(output));

    printf("Encrypted message: %s\n", output);

    return 0;
}
