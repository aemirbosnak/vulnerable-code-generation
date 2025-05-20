#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(const char *input, char *output, size_t length) {
    for (size_t i = 0; i <= length; i++) { // Out of bounds read vulnerability
        output[i] = input[i];
    }
}

int main() {
    const char *input = "Hello, World!";
    char *output = malloc(13); // Allocate memory for 12 characters plus null terminator

    if (output == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    compress(input, output, 12); // Correct length to avoid buffer overflow

    printf("Compressed: %s\n", output);

    free(output);
    return 0;
}
