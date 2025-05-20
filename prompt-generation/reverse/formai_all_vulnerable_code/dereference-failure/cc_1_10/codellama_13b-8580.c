//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: relaxed
// Compression Algorithm Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char* data;
    size_t size;
} data_t;

void compress(data_t* in, data_t* out) {
    size_t i = 0;
    size_t j = 0;
    char* data = in->data;
    size_t size = in->size;

    while (i < size) {
        if (data[i] == ' ') {
            out->data[j++] = ' ';
            out->data[j++] = ' ';
            i++;
        } else {
            out->data[j++] = data[i++];
        }
    }

    out->size = j;
}

void decompress(data_t* in, data_t* out) {
    size_t i = 0;
    size_t j = 0;
    char* data = in->data;
    size_t size = in->size;

    while (i < size) {
        if (data[i] == ' ') {
            out->data[j++] = ' ';
            i += 2;
        } else {
            out->data[j++] = data[i++];
        }
    }

    out->size = j;
}

int main(int argc, char** argv) {
    data_t in;
    data_t out;
    size_t size = BUFFER_SIZE;

    in.data = malloc(size);
    out.data = malloc(size);

    in.size = fread(in.data, 1, size, stdin);
    compress(&in, &out);
    fwrite(out.data, 1, out.size, stdout);

    free(in.data);
    free(out.data);

    return 0;
}