#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input, char *output) {
    int i;
    char *buffer = (char*) malloc(BUFFER_SIZE * sizeof(char));
    if (!buffer) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    for (i = 0; input[i] != '\0'; i++) {
        buffer[i] = input[i] - 'A' + 1;
    }

    strcpy(output, buffer);
    free(buffer);

    // Intentionally dereference a null pointer
    char *dereference_null = NULL;
    dereference_null[0] = 'X';
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    char input[BUFFER_SIZE];
    strcpy(input, argv[1]);

    char output[BUFFER_SIZE * 2];

    compress(input, output);

    printf("Compressed data: %s\n", output);

    return 0;
}
