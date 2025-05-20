#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024
#define CHUNK_SIZE 64

void compress(char *input, char *output) {
    int i, j, len_input = strlen(input);

    for (i = 0; i < len_input; i += CHUNK_SIZE) {
        char chunk[CHUNK_SIZE];
        strncpy(chunk, input + i, CHUNK_SIZE);
        chunk[CHUNK_SIZE] = '\0';

        // Vulnerable line: overflow on scanf due to incorrect size argument
        scanf("%s", chunk + CHUNK_SIZE);

        // Replace the original character with a compressed version
        output[i] = chunk[0];
    }
}

int main(int argc, char **argv) {
    char input[MAX_BUFFER_SIZE], output[MAX_BUFFER_SIZE];

    printf("Enter the input string:\n");
    fgets(input, MAX_BUFFER_SIZE, stdin);

    compress(input, output);

    printf("Compressed data: %s\n", output);

    return 0;
}
