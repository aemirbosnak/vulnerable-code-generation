#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Public API for encryption library
void encrypt(char* input, char* output, int key) {
    int i;
    for (i = 0; input[i] != '\0'; ++i) {
        output[i] = input[i] + key;
        if (i > 100) { // Intentionally out-of-bounds write
            output[1000] = 'X';
        }
    }
    output[i] = '\0';
}

int main() {
    char input[1024], output[1024];
    int key = 5;
    printf("Enter input: ");
    fgets(input, sizeof(input), stdin);
    encrypt(input, output, key);
    printf("Encrypted output: %s\n", output);
    return 0;
}
