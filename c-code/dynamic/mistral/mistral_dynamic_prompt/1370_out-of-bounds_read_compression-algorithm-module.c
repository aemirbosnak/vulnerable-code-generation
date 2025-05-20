#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input, char *output) {
    char buffer[BUFFER_SIZE];
    int len = 0;
    int i;

    for (i = 0; input[i]; i++) {
        buffer[len++] = input[i];

        if ((len % 128) == 0 && len != i + 1) {
            buffer[len++] = '\n';
        }
    }

    strcpy(output, buffer);
}

int main(int argc, char *argv[]) {
    char input[BUFFER_SIZE];
    char output[BUFFER_SIZE];

    if (argc != 2) {
        printf("Usage: ./compress <input_file>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 2;
    }

    fgets(input, BUFFER_SIZE, file);
    compress(input, output);

    printf("Compressed data: %s\n", output);

    fclose(file);

    // Intentionally out-of-bounds read (read past the end of the input string)
    char extra_char = input[strlen(input) + 1];
    printf("Read extra character: %c\n", extra_char);

    return 0;
}
