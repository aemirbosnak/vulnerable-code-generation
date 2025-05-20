//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 512

typedef struct {
    float *buffer;
    int buffer_size;
    int buffer_index;
} Buffer;

void create_buffer(Buffer *buffer, int size) {
    buffer->buffer_size = size;
    buffer->buffer_index = 0;
    buffer->buffer = (float *)malloc(size * sizeof(float));
}

void destroy_buffer(Buffer *buffer) {
    free(buffer->buffer);
}

void add_sample(Buffer *buffer, float sample) {
    buffer->buffer[buffer->buffer_index++] = sample;
    if (buffer->buffer_index == buffer->buffer_size) {
        buffer->buffer_index = 0;
    }
}

void process_buffer(Buffer *buffer, float (*process_function)(float)) {
    int i;
    for (i = 0; i < buffer->buffer_size; i++) {
        buffer->buffer[i] = process_function(buffer->buffer[i]);
    }
}

float square(float x) {
    return x * x;
}

int main() {
    Buffer input_buffer, output_buffer;
    create_buffer(&input_buffer, BUFFER_SIZE);
    create_buffer(&output_buffer, BUFFER_SIZE);

    while (1) {
        float sample;
        printf("Enter a sample (or 'q' to quit): ");
        scanf("%f", &sample);

        if (sample == 'q') {
            break;
        }

        add_sample(&input_buffer, sample);

        process_buffer(&input_buffer, square);

        int i;
        for (i = 0; i < input_buffer.buffer_size; i++) {
            printf("%f ", input_buffer.buffer[i]);
        }
        printf("\n");
    }

    destroy_buffer(&input_buffer);
    destroy_buffer(&output_buffer);

    return 0;
}