#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define CHUNK_SIZE 256

void compress_data(char *input, char *output) {
    char *buffer = malloc(BUFFER_SIZE);
    int bufferIndex = 0;
    int chunkIndex = 0;

    for (int i = 0; input[i] != '\0'; ++i) {
        buffer[bufferIndex++] = input[i];

        if ((bufferIndex == BUFFER_SIZE) || (i == (size_t)(input + CHUNK_SIZE))) {
            compress_chunk(buffer, output);
            bufferIndex = 0;
        }
    }

    if (bufferIndex > 0) {
        compress_chunk(buffer, output);
    }

    free(buffer);
}

void compress_chunk(char *buffer, char *output) {
    // This is where the deliberate vulnerability exists. buffer[CHUNK_SIZE] is dereferenced here even when it might not be initialized.
    printf("%d\n", buffer[CHUNK_SIZE]);

    strcat(output, buffer);
}

int main() {
    char input[BUFFER_SIZE];
    char output[2 * BUFFER_SIZE];

    printf("Enter data to compress:\n");
    fgets(input, BUFFER_SIZE, stdin);

    compress_data(input, output);

    printf("Compressed data:\n%s\n", output);

    return 0;
}
