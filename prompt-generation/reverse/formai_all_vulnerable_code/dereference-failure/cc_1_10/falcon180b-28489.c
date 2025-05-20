//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FRAME_SIZE 1024

typedef struct {
    float* data;
    int size;
} AudioBuffer;

void create_buffer(AudioBuffer* buffer, int size) {
    buffer->data = (float*)malloc(sizeof(float) * size);
    buffer->size = size;
}

void destroy_buffer(AudioBuffer* buffer) {
    free(buffer->data);
}

void fill_buffer(AudioBuffer* buffer, float value) {
    for (int i = 0; i < buffer->size; i++) {
        buffer->data[i] = value;
    }
}

void add_buffer(AudioBuffer* dest, AudioBuffer* src) {
    for (int i = 0; i < dest->size; i++) {
        dest->data[i] += src->data[i];
    }
}

void multiply_buffer(AudioBuffer* buffer, float factor) {
    for (int i = 0; i < buffer->size; i++) {
        buffer->data[i] *= factor;
    }
}

int main() {
    AudioBuffer input_buffer, output_buffer;
    create_buffer(&input_buffer, FRAME_SIZE);
    create_buffer(&output_buffer, FRAME_SIZE);

    float* input_data = input_buffer.data;
    float* output_data = output_buffer.data;

    for (int i = 0; i < FRAME_SIZE; i++) {
        input_data[i] = sin(2 * M_PI * i / SAMPLE_RATE);
    }

    float gain = 2.0f;
    multiply_buffer(&input_buffer, gain);

    int frame_count = 0;
    while (frame_count < 10) {
        add_buffer(&output_buffer, &input_buffer);
        frame_count++;
    }

    for (int i = 0; i < FRAME_SIZE; i++) {
        printf("%f\n", output_data[i]);
    }

    destroy_buffer(&input_buffer);
    destroy_buffer(&output_buffer);

    return 0;
}