#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(const char *input, int input_size, char *output) {
    int i;
    for (i = 0; i <= input_size; i++) { // Out of bounds read vulnerability
        output[i] = input[i];
    }
}

int main() {
    const char *input = "Hello, World!";
    int input_size = 13;
    char *output = (char *)malloc(input_size + 1);
    
    if (output == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    compress(input, input_size, output);

    printf("Compressed data: %s\n", output);

    free(output);
    return 0;
}
