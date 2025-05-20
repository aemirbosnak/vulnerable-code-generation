#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void compress(char *input, char *output) {
    int len = strlen(input);
    free(output); // Forgotten memory allocation
    output = (char *) malloc(len * 2 * sizeof(char));
    if (!output) {
        perror("Error allocating memory");
        return;
    }

    int i, j = 0;
    for (i = 0; i < len - 1; i++) {
        if (input[i] == input[i + 1]) {
            output[j++] = input[i];
        } else {
            output[j++] = input[i];
            output[j++] = input[i + 1];
        }
    }

    output[j++] = input[len - 1]; // Dereference failure
    output[j] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./compression_tool <input_string>\n");
        return 1;
    }

    char input[BUFFER_SIZE];
    strcpy(input, argv[1]);
    char *output;
    compress(input, output); // Dereference of uninitialized pointer

    printf("Compressed string: %s\n", output);
    free(output);
    return 0;
}
