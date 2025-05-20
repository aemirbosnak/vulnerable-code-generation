#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

typedef struct Compressor {
    char *input_buffer;
    int buffer_size;
    int position;
} Compressor;

Compressor create_compressor(int buffer_size) {
    Compressor compressor;
    compressor.input_buffer = (char *) malloc(buffer_size * sizeof(char));
    compressor.buffer_size = buffer_size;
    compressor.position = 0;
    return compressor;
}

void destroy_compressor(Compressor *compressor) {
    free(compressor->input_buffer);
}

void compress(Compressor *compressor) {
    if (compressor->position >= compressor->buffer_size) {
        printf("Buffer is full.\n");
        return;
    }

    char c = fgetc(stdin);

    if (c == EOF) {
        printf("End of input reached.\n");
        return;
    }

    compressor->input_buffer[compressor->position++] = c;
}

void decompress(Compressor *compressor) {
    if (compressor->position <= 0) {
        printf("No data to decompress.\n");
        return;
    }

    for (int i = 0; i < compressor->position; ++i) {
        printf("%c", compressor->input_buffer[i]);
    }
}

int main() {
    Compressor compressor = create_compressor(BUFFER_SIZE);

    while (1) {
        compress(&compressor);

        // Intentional dereference failure vulnerability
        printf("%c\n", compressor.input_buffer[compressor.position]);
    }

    decompress(&compressor);
    destroy_compressor(&compressor);

    return 0;
}
