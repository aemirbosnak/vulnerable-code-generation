#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _CompressionModule {
    char* buffer;
    size_t size;
} CompressionModule;

CompressionModule* createCompressor(size_t bufferSize) {
    CompressionModule* cm = malloc(sizeof(CompressionModule));
    cm->buffer = malloc(bufferSize);
    cm->size = bufferSize;
    return cm;
}

void compress(CompressionModule* cm, const char* input) {
    memcpy(cm->buffer, input, strlen(input));
}

void freeCompressor(CompressionModule* cm) {
    free(cm->buffer);
    free(cm);
}

int main() {
    CompressionModule* cm = createCompressor(10);
    compress(cm, "A very long string that we forgot to allocate enough memory for");
    printf("%s\n", cm->buffer);
    freeCompressor(cm);

    CompressionModule* cm2 = createCompressor(5);
    compress(cm2, "A shorter string that should fit comfortably");
    printf("%s\n", cm2->buffer);
    freeCompressor(cm2);

    // Use the compressor again without freeing it first
    compress(cm, "Another string");
    printf("%s\n", cm->buffer);

    return 0;
}
