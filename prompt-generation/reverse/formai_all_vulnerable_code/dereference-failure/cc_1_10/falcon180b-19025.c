//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024
#define PI 3.14159265358979323846

typedef struct {
    float *data;
    int size;
} Buffer;

void init_buffer(Buffer *buffer, int size) {
    buffer->data = (float *)malloc(size * sizeof(float));
    buffer->size = size;
    for (int i = 0; i < size; i++) {
        buffer->data[i] = 0.0f;
    }
}

void free_buffer(Buffer *buffer) {
    free(buffer->data);
}

void fill_buffer(Buffer *buffer) {
    for (int i = 0; i < buffer->size; i++) {
        buffer->data[i] = sin(2 * PI * i / SAMPLE_RATE);
    }
}

void print_buffer(Buffer *buffer) {
    for (int i = 0; i < buffer->size; i++) {
        printf("%f ", buffer->data[i]);
    }
    printf("\n");
}

int main() {
    Buffer input_buffer, output_buffer;
    init_buffer(&input_buffer, BUFFER_SIZE);
    init_buffer(&output_buffer, BUFFER_SIZE);

    fill_buffer(&input_buffer);

    float *input_data = input_buffer.data;
    float *output_data = output_buffer.data;

    for (int i = 0; i < BUFFER_SIZE; i++) {
        output_data[i] = input_data[i] * 2.0f;
    }

    print_buffer(&input_buffer);
    print_buffer(&output_buffer);

    free_buffer(&input_buffer);
    free_buffer(&output_buffer);

    return 0;
}