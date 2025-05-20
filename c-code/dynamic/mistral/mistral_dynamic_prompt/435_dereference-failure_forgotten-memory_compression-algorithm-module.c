#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char* data;
    size_t size;
} CompressedData;

void compress(CompressedData* dest, const unsigned char* src, size_t len) {
    dest->data = malloc(len);
    memcpy(dest->data, src, len);
    dest->size = len;
}

void free_compressed_data(CompressedData* data) {
    if (data->data) {
        free(data->data);
        data->data = NULL;
        data->size = 0;
    }
}

void decompress(const CompressedData* src, unsigned char* dest) {
    memcpy(dest, src->data, src->size);
}

int main() {
    CompressedData compressedData;
    unsigned char input[10];
    unsigned char output[5];

    for (size_t i = 0; i < 10; i++)
        input[i] = 'a' + (i % 26);

    compress(&compressedData, input, 10);
    printf("Compressed data size: %zu\n", compressedData.size);

    for (size_t i = 0; i < compressedData.size; i++)
        output[i] = compressedData.data[i];

    printf("Decompressed data: ");
    for (size_t i = 0; i < compressedData.size; i++)
        putchar(output[i]);

    printf("\n");

    free(compressedData.data);

    return 0;
}
