//MISTRAL-7B DATASET v1.0 Category: Compression algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 1000
#define BUFFER_SIZE 10

typedef struct {
    unsigned char data;
    unsigned int count;
} run_length_encoding;

void compress(unsigned char *input, unsigned int input_size, unsigned char *output) {
    run_length_encoding *buffer = malloc(BUFFER_SIZE * sizeof(run_length_encoding));
    unsigned int buffer_index = 0;
    unsigned int i = 0;

    while (i < input_size) {
        if (buffer_index == BUFFER_SIZE) {
            *output++ = (unsigned char)(buffer_index | 128);
            *output++ = input[i];
            buffer_index = 0;
        }

        if (buffer[buffer_index].data == input[i]) {
            buffer[buffer_index].count++;
        } else {
            if (buffer[buffer_index].count > 0) {
                unsigned char count_bytes = (unsigned char)(buffer[buffer_index].count >> 1);
                *output++ = count_bytes | 128;
                *output++ = count_bytes + 1;
                *output++ = input[i];

                buffer[buffer_index].count = 0;
                buffer[buffer_index].data = input[i];
            } else {
                *output++ = input[i];
            }

            buffer_index++;
        }

        i++;
    }

    if (buffer_index > 0) {
        if (buffer[buffer_index - 1].count > 0) {
            unsigned char count_bytes = (unsigned char)(buffer[buffer_index - 1].count >> 1);
            *output++ = count_bytes | 128;
            *output++ = count_bytes + 1;
        }

        *output++ = buffer[buffer_index - 1].data;
    }

    free(buffer);
}

int main() {
    unsigned char input[MAX_INPUT_SIZE] = { 0 };
    unsigned char output[MAX_INPUT_SIZE * 2] = { 0 };
    unsigned int input_size = 0;

    // Read input data from stdin
    while (scanf("%hhu", &input[input_size]) != EOF) {
        input_size++;
    }

    compress(input, input_size, output);

    // Write compressed data to stdout
    for (unsigned int i = 0; i < input_size * 2; i++) {
        putchar(output[i]);
    }

    return 0;
}