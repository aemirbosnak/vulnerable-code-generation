#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    int size;
    char data[1];
} CompressedData;

void compress(CompressedData* data, const char* input) {
    int len = strlen(input);
    data->size = len;
    memcpy(data->data, input, len);
}

void decompress(const CompressedData* data) {
    printf("%s", data->data);
}

int main() {
    CompressedData myData;
    char input[] = "This is a simple compression algorithm example";
    compress(&myData, input);
    decompress(&myData);

    // Oops! Dereference a null pointer
    decompress(NULL);

    return 0;
}
