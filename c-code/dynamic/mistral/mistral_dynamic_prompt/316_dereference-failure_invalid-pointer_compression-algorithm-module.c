#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Compressor {
    int capacity;
    int size;
    char *buffer;
} Compressor;

void compress(Compressor *compressor, const char *input) {
    if (compressor->size + strlen(input) > compressor->capacity) {
        printf("Error: Compressor is full.\n");
        return;
    }

    strcat(compressor->buffer, input);
    compressor->size += strlen(input);
}

void decompress(Compressor *compressor) {
    if (compressor->size <= 0) {
        printf("Error: No data to decompress.\n");
        return;
    }

    char *output = malloc(compressor->size * sizeof(char));
    strcpy(output, compressor->buffer);
    compressor->size = 0;

    printf("Decompressed data:\n%s\n", output);
    free(output);
}

int main(int argc, char *argv[]) {
    Compressor compressor = {.capacity = 100, .size = 0};
    compressor.buffer = malloc(compressor.capacity * sizeof(char));

    compressor.buffer[0] = 'H';
    compressor.buffer[1] = 'e';
    compressor.buffer[2] = 'l';
    compressor.buffer[3] = 'l';
    compressor.buffer[4] = 'o';

    compressor.size = 5;

    compressor.buffer[10] = 'W'; // Invalidate the pointer by accessing an out-of-bounds index

    decompress(&compressor);

    return 0;
}
