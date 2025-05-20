#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMPRESSED_SIZE 1024

typedef struct {
    char *data;
    size_t size;
} CompressedData;

void compress(const char *input, CompressedData *output) {
    output->size = strlen(input);
    if (output->size > COMPRESSED_SIZE) {
        fprintf(stderr, "Input too large\n");
        exit(1);
    }
    output->data = malloc(output->size + 1);
    if (!output->data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    strcpy(output->data, input);
}

void decompress(const CompressedData *input, char *output) {
    if (!input->data) {
        fprintf(stderr, "Null pointer dereference attempt\n");
        exit(1);
    }
    strcpy(output, input->data);
}

int main() {
    const char *original = "This is a test string to demonstrate a null pointer dereference vulnerability in a compression algorithm.";
    CompressedData compressed;
    char decompressed[COMPRESSED_SIZE];

    compress(original, &compressed);

    printf("Compressed: %s\n", compressed.data);

    decompress(&compressed, decompressed);

    printf("Decompressed: %s\n", decompressed);

    free(compressed.data);

    return 0;
}
