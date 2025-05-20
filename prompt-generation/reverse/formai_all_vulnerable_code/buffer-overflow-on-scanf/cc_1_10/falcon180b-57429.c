//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FRAME_SIZE 1024
#define WINDOW_SIZE 4096
#define HOP_SIZE (FRAME_SIZE / 2)

typedef struct {
    float *data;
    int capacity;
    int size;
} Buffer;

void init_buffer(Buffer *buffer, int capacity) {
    buffer->data = (float *)malloc(capacity * sizeof(float));
    buffer->capacity = capacity;
    buffer->size = 0;
}

void push_sample(Buffer *buffer, float sample) {
    if (buffer->size == buffer->capacity) {
        buffer->capacity *= 2;
        buffer->data = (float *)realloc(buffer->data, buffer->capacity * sizeof(float));
    }
    buffer->data[buffer->size++] = sample;
}

void process_buffer(Buffer *buffer, float (*process_func)(float)) {
    for (int i = 0; i < buffer->size; i++) {
        buffer->data[i] = process_func(buffer->data[i]);
    }
}

float window_function(float x) {
    return 0.5 * (1 - cos(2 * M_PI * x / WINDOW_SIZE));
}

int main() {
    Buffer input_buffer, output_buffer;

    init_buffer(&input_buffer, FRAME_SIZE);
    init_buffer(&output_buffer, FRAME_SIZE);

    float (*window)(float) = &window_function;

    while (1) {
        for (int i = 0; i < FRAME_SIZE; i++) {
            float sample;
            scanf("%f", &sample);
            push_sample(&input_buffer, sample);
        }

        process_buffer(&input_buffer, window);

        for (int i = 0; i < FRAME_SIZE; i++) {
            float sample = input_buffer.data[(i * HOP_SIZE) % input_buffer.size];
            push_sample(&output_buffer, sample);
        }

        for (int i = 0; i < FRAME_SIZE; i++) {
            printf("%f\n", output_buffer.data[i]);
        }
    }

    return 0;
}