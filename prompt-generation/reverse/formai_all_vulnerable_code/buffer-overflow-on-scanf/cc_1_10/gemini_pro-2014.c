//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    int size;
} Buffer;

Buffer *newBuffer(int size) {
    Buffer *buffer = malloc(sizeof(Buffer));
    buffer->data = malloc(size);
    buffer->size = size;
    return buffer;
}

void freeBuffer(Buffer *buffer) {
    free(buffer->data);
    free(buffer);
}

void compress(Buffer *input, Buffer *output) {
    int count = 0;
    char last = 0;
    for (int i = 0; i < input->size; i++) {
        char c = input->data[i];
        if (c == last) {
            count++;
        } else {
            if (count > 0) {
                output->data[output->size++] = count + '0';
            }
            output->data[output->size++] = c;
            last = c;
            count = 1;
        }
    }
    if (count > 0) {
        output->data[output->size++] = count + '0';
    }
}

void decompress(Buffer *input, Buffer *output) {
    int count = 0;
    for (int i = 0; i < input->size; i++) {
        char c = input->data[i];
        if (c >= '0' && c <= '9') {
            count = count * 10 + c - '0';
        } else {
            for (int j = 0; j < count; j++) {
                output->data[output->size++] = c;
            }
            count = 0;
        }
    }
}

int main() {
    Buffer *input = newBuffer(100);
    scanf("%s", input->data);
    input->size = strlen(input->data);

    Buffer *output = newBuffer(100);
    compress(input, output);

    printf("%s", output->data);

    Buffer *decompressed = newBuffer(100);
    decompress(output, decompressed);

    printf("\n%s", decompressed->data);

    freeBuffer(input);
    freeBuffer(output);
    freeBuffer(decompressed);

    return 0;
}