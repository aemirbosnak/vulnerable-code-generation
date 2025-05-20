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
    free(cd->data);
    cd->data = NULL; // Freeing the memory
}

int main() {
    const char *original_data = "This is a test string to demonstrate a use-after-free vulnerability.";
    CompressedData compressed = compress(original_data);

    // Use after free vulnerability
    printf("Original data: %s\n", compressed.data); // Accessing freed memory

    decompress(&compressed);

    // Attempt to access freed memory again
    printf("Trying to access freed memory: %s\n", compressed.data); // Undefined behavior

    return 0;
}
