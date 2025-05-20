//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct {
    float *data;
    int size;
} AudioBuffer;

void init_buffer(AudioBuffer *buffer, int size) {
    buffer->data = (float *)malloc(size * sizeof(float));
    buffer->size = size;
}

void free_buffer(AudioBuffer *buffer) {
    free(buffer->data);
}

void fill_buffer(AudioBuffer *buffer, float value) {
    int i;
    for (i = 0; i < buffer->size; i++) {
        buffer->data[i] = value;
    }
}

void generate_sine_wave(AudioBuffer *buffer, float frequency, float amplitude) {
    int i;
    float phase = 0;
    for (i = 0; i < buffer->size; i++) {
        buffer->data[i] = amplitude * sin(2 * M_PI * frequency * i / SAMPLE_RATE + phase);
        phase += 2 * M_PI * frequency / SAMPLE_RATE;
    }
}

void apply_gain(AudioBuffer *buffer, float gain) {
    int i;
    for (i = 0; i < buffer->size; i++) {
        buffer->data[i] *= gain;
    }
}

int main() {
    AudioBuffer input_buffer, output_buffer;
    init_buffer(&input_buffer, BUFFER_SIZE);
    init_buffer(&output_buffer, BUFFER_SIZE);

    generate_sine_wave(&input_buffer, 440, 0.5);

    apply_gain(&input_buffer, 0.5);

    int i;
    for (i = 0; i < input_buffer.size; i++) {
        printf("%f\n", input_buffer.data[i]);
    }

    free_buffer(&input_buffer);
    free_buffer(&output_buffer);

    return 0;
}