#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMPRESSED_SIZE 1024

typedef struct {
    char *data;
    size_t length;
} CompressedData;

CompressedData compress(const char *input) {
    CompressedData result;
    result.data = (char *)malloc(COMPRESSED_SIZE);
    if (!result.data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    result.length = strlen(input);
    memcpy(result.data, input, result.length);
    return result;
}

void decompress(CompressedData *cd) {
    printf("Decompressed data: %s\n", cd->data);
    // Use after free vulnerability here
    printf("Use after free: %s\n", cd->data); // Accessing freed memory
}

int main() {
    const char *original_data = "This is some compressed data";
    CompressedData cd = compress(original_data);

    // Free the allocated memory
    free(cd.data);

    // Deliberate use after free
    decompress(&cd);

    return 0;
}
