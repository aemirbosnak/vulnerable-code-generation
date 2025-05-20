//FormAI DATASET v1.0 Category: Compression algorithms ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR 256

typedef struct {
    unsigned char byte;
    int bit_count;
} bit_buffer;

void initialize_buffer(bit_buffer *buffer) {
    buffer->byte = 0;
    buffer->bit_count = 0;
}

void write_bit(bit_buffer *buffer, int bit) {
    buffer->byte |= (bit << (7 - buffer->bit_count++));
    if (buffer->bit_count == 8) {
        putchar(buffer->byte);
        initialize_buffer(buffer);
    }
}

void flush_buffer(bit_buffer *buffer) {
    if (buffer->bit_count > 0) {
        putchar(buffer->byte);
    }
}

void compress(FILE *input_file) {
    int frequencies[MAX_CHAR] = {0};
    int c;
    while ((c = fgetc(input_file)) != EOF) {
        frequencies[c]++;
    }

    rewind(input_file);

    int i, j;
    int total_chars = 0;
    for (i = 0; i < MAX_CHAR; i++) {
        total_chars += frequencies[i];
    }

    float probabilities[MAX_CHAR] = {0.0};
    for (i = 0; i < MAX_CHAR; i++) {
        probabilities[i] = (float) frequencies[i] / (float) total_chars;
    }

    float cumulative_probabilities[MAX_CHAR] = {0.0};
    cumulative_probabilities[0] = probabilities[0];
    for (i = 1; i < MAX_CHAR; i++) {
        cumulative_probabilities[i] = cumulative_probabilities[i - 1] + probabilities[i];
    }

    bit_buffer buffer;
    initialize_buffer(&buffer);

    while ((c = fgetc(input_file)) != EOF) {
        for (i = 0; i < MAX_CHAR; i++) {
            if (c == i) {
                break;
            }
        }
        for (j = 0; j < 8; j++) {
            if (cumulative_probabilities[i] < (j + 1) * 0.125) {
                write_bit(&buffer, 0);
            } else {
                write_bit(&buffer, 1);
            }
        }
    }

    flush_buffer(&buffer);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s [input file]\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Could not open input file %s\n", argv[1]);
        return 1;
    }

    compress(input_file);

    fclose(input_file);
    return 0;
}