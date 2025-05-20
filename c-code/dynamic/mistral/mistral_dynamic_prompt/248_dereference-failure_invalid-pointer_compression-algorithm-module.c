#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096
#define MAX_CHUNK_SIZE 128

void compress(char *input, char *output) {
    char chunk[MAX_CHUNK_SIZE];
    char *buffer = malloc(BUFFER_SIZE);
    size_t index = 0;
    size_t length = strlen(input);

    for (size_t i = 0; i < length; ++i) {
        if (i % MAX_CHUNK_SIZE == 0) {
            memcpy(chunk, &input[i], 1);
            index = 0;
        }

        chunk[index++] = input[i];
        if (index == MAX_CHUNK_SIZE || i == (length - 1)) {
            sprintf(buffer + (i - index), "%s", chunk);
            output_chunk(buffer, (i - index));
            if (index != MAX_CHUNK_SIZE) {
                memset(chunk, 0, sizeof(chunk));
            }
        }
    }

    free(buffer);
}

void output_chunk(char *chunk, size_t length) {
    char *output_buffer = malloc(length + 1);
    memcpy(output_buffer, chunk, length);
    output_buffer[length] = '\0';

    printf("Compressing chunk: %s\n", output_buffer);

    char *invalid_pointer = NULL;
    printf("Invalid access: %s\n", invalid_pointer); // Here lies the vulnerability

    free(output_buffer);
}

int main() {
    char input[] = "A programmer and security researcher walk into a bar. Or a bug, if you will.";
    char output[strlen(input) * 2 + 1];

    compress(input, output);

    printf("Compressed data: %s\n", output);

    return 0;
}
