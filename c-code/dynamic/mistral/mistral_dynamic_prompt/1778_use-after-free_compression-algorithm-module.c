#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *data;
    size_t length;
} CompressedData;

void compress(char *input, CompressedData *output) {
    output->data = malloc(BUFFER_SIZE);
    output->length = 0;

    for (size_t i = 0; input[i]; ++i) {
        if (output->length == BUFFER_SIZE) {
            output->data = realloc(output->data, output->length + BUFFER_SIZE);
        }
        output->data[output->length] = input[i];
        ++output->length;
    }
}

void decompress(CompressedData data, char *output) {
    for (size_t i = 0; i < data.length; ++i) {
        output[i] = data.data[i];
    }
    free(data.data); // ❗️ Potential Use-After-Free vulnerability
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <input_string>\n", argv[0]);
        return 1;
    }

    CompressedData compressed;
    compress(argv[1], &compressed);
    char decompressed[BUFFER_SIZE];
    decompress(compressed, decompressed);
    printf("Decompressed:\n%s\n", decompressed);
    free(compressed.data); // Using compressed memory after it has been freed, leading to a segmentation fault or other undefined behavior

    return 0;
}
