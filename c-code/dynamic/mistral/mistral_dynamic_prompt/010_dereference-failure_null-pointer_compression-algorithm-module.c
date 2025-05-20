#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define MAX_INPUT_SIZE 65536

typedef struct {
    unsigned char *buffer;
    size_t buffer_size;
    size_t position;
} CompressionBuffer;

void init_compression_buffer(CompressionBuffer *buffer) {
    buffer->buffer = malloc(BUFFER_SIZE);
    buffer->buffer_size = BUFFER_SIZE;
    buffer->position = 0;
}

void resize_compression_buffer(CompressionBuffer *buffer) {
    buffer->buffer = realloc(buffer->buffer, buffer->buffer_size * 2);
    buffer->buffer_size *= 2;
}

void compress_data(const char *input, CompressionBuffer *buffer) {
    size_t input_length = strlen(input);

    if (buffer->position + input_length >= buffer->buffer_size)
        resize_compression_buffer(buffer);

    memcpy(buffer->buffer + buffer->position, input, input_length);
    buffer->position += input_length;
}

void process_compressed_data(CompressionBuffer buffer) {
    printf("Compressed Data: ");
    for (size_t i = 0; i < buffer.position; ++i) {
        printf("%c", buffer.buffer[i]);
    }
    printf("\n");

    free(buffer.buffer);
}

int main() {
    char input[MAX_INPUT_SIZE];
    CompressionBuffer buffer;
    init_compression_buffer(&buffer);

    printf("Enter the input data to compress:\n");
    fgets(input, MAX_INPUT_SIZE, stdin);

    compress_data(input, &buffer);
    process_compressed_data(buffer);

    // Intentionally dereferencing null pointer after freeing the buffer
    printf("%c\n", buffer.buffer[0]);

    return 0;
}
