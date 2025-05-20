#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Compressor {
    char *data;
    int capacity;
    int count;
} Compressor;

void compress(Compressor *compressor, char *input) {
    if (!compressor || !input) return;

    compressor->data = malloc(strlen(input) * 2);
    if (!compressor->data) return;

    compressor->capacity = strlen(input) * 2;
    compressor->count = 0;

    for (int i = 0; input[i]; i++) {
        compressor->data[compressor->count++] = input[i];
        compressor->data[compressor->count++] = input[i + 1];
        i++;
    }
}

int main() {
    Compressor myCompressor;
    char input[10] = "ababcd";

    compress(&myCompressor, input);

    for (int i = 0; i < myCompressor.count; i++) {
        printf("%c", myCompressor.data[i]);
    }

    free(myCompressor.data);

    return 0;
}
