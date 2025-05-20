//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1000000

typedef struct {
    char *buffer;
    size_t size;
} Buffer;

void buffer_init(Buffer *buffer) {
    buffer->buffer = (char *) malloc(MAX_BUFFER_SIZE);
    buffer->size = 0;
}

void buffer_free(Buffer *buffer) {
    free(buffer->buffer);
}

void buffer_append(Buffer *buffer, const char *data, size_t data_size) {
    if (buffer->size + data_size > MAX_BUFFER_SIZE) {
        fprintf(stderr, "Buffer overflow\n");
        exit(1);
    }
    memcpy(buffer->buffer + buffer->size, data, data_size);
    buffer->size += data_size;
}

void buffer_reset(Buffer *buffer) {
    buffer->size = 0;
}

int buffer_checksum(Buffer *buffer) {
    int checksum = 0;
    for (size_t i = 0; i < buffer->size; i++) {
        checksum += buffer->buffer[i];
    }
    return checksum;
}

int main() {
    Buffer buffer;
    buffer_init(&buffer);

    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening input file\n");
        return 1;
    }

    char input_buffer[4096];
    while (fread(input_buffer, 1, sizeof(input_buffer), input_file) > 0) {
        buffer_append(&buffer, input_buffer, fread(input_buffer, 1, sizeof(input_buffer), input_file));
    }
    fclose(input_file);

    int checksum = buffer_checksum(&buffer);

    printf("Checksum: %d\n", checksum);

    buffer_free(&buffer);

    return 0;
}