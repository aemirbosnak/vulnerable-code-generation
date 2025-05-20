#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(char *input, int input_size, char *output) {
    int i;
    for (i = 0; i < input_size; i++) {
        output[i] = input[i];
    }
}

int main() {
    char input[] = "This is a test string.";
    int input_size = sizeof(input);
    char *output = malloc(input_size);

    compress(input, input_size, output);

    printf("Original: %s\n", input);
    printf("Compressed: %s\n", output);

    free(output);
    return 0;
}
