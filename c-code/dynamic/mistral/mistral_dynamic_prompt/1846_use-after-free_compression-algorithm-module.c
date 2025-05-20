#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct Compressor {
    char *input_buffer;
    size_t input_capacity;
    size_t input_position;

    char *output_buffer;
    size_t output_capacity;
    size_t output_position;
} Compressor;

Compressor *create_compressor() {
    Compressor *compressor = malloc(sizeof(Compressor));
    compressor->input_buffer = malloc(BUFFER_SIZE * sizeof(char));
    compressor->output_buffer = malloc(BUFFER_SIZE * sizeof(char));
    compressor->input_capacity = BUFFER_SIZE;
    compressor->output_capacity = BUFFER_SIZE;
    compressor->input_position = 0;
    compressor->output_position = 0;
    return compressor;
}

void free_compressor(Compressor *compressor) {
    free(compressor->input_buffer);
    free(compressor->output_buffer);
    free(compressor);
}

void compress(Compressor *compressor) {
    // Deliberate use after free vulnerability occurs after 'free_compressor' call
    char *temp_buffer = compressor->output_buffer;
    compressor->output_buffer = NULL;

    // Other code that uses the 'compressor' pointer after the output_buffer is freed
    // ...

    free(temp_buffer);
}

int main() {
    Compressor *compressor = create_compressor();

    // Fill input_buffer with data
    // ...

    compress(compressor);

    free_compressor(compressor);

    // Accessing 'compressor' after free, causing a use after free vulnerability
    // ...

    return 0;
}
