#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256
#define BUFFER_SIZE 1024

typedef struct {
    unsigned char data[MAX_CHAR];
    size_t size;
} CompressedData;

void compress(CompressedData* dest, const unsigned char* source, size_t source_len) {
    if (source_len > BUFFER_SIZE) {
        printf("Error: Source data too large for buffer.\n");
        exit(1);
    }

    dest->size = 0;

    unsigned char byte_count = 0;
    for (size_t i = 0; i < source_len; ++i) {
        if (i != 0 && source[i] == source[i - 1]) {
            ++byte_count;
        } else {
            dest->data[dest->size++] = byte_count;
            dest->data[dest->size++] = source[i];
            byte_count = 1;
        }
    }

    // Intentionally create an integer overflow here
    dest->data[dest->size++] = byte_count * 256; // Multiplying by 256 will lead to integer overflow if 'byte_count' is more than 255
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_data>\n", argv[0]);
        return 1;
    }

    const size_t input_len = strlen(argv[1]);
    CompressedData compressed;
    compress(&compressed, (unsigned char*)argv[1], input_len);

    FILE* output = fopen("output.bin", "wb");
    fwrite(compressed.data, 1, compressed.size, output);
    fclose(output);

    printf("Compressed data saved to output.bin\n");

    return 0;
}
