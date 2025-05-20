//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024
#define PI 3.14159265358979323846

typedef struct {
    int index;
    int count;
    float *buffer;
} Buffer;

void create_buffer(Buffer *buffer) {
    buffer->index = 0;
    buffer->count = 0;
    buffer->buffer = (float *) malloc(BUFFER_SIZE * sizeof(float));
}

void destroy_buffer(Buffer *buffer) {
    free(buffer->buffer);
}

void push_sample(Buffer *buffer, float sample) {
    buffer->buffer[buffer->index] = sample;
    buffer->index = (buffer->index + 1) % BUFFER_SIZE;
    buffer->count++;
}

float pop_sample(Buffer *buffer) {
    float sample = buffer->buffer[buffer->index];
    buffer->index = (buffer->index + 1) % BUFFER_SIZE;
    buffer->count--;
    return sample;
}

void process_buffer(Buffer *buffer, float (*processor)(float)) {
    int i;
    for (i = 0; i < buffer->count; i++) {
        buffer->buffer[i] = processor(buffer->buffer[i]);
    }
}

float square(float x) {
    return x * x;
}

float sawtooth(float x) {
    return 2 * x - 1;
}

float triangle(float x) {
    return 2 * x - 1;
}

float sine(float x) {
    return sin(x * PI * 2);
}

float noise(float x) {
    return rand() / RAND_MAX;
}

int main() {
    Buffer input_buffer, output_buffer;
    create_buffer(&input_buffer);
    create_buffer(&output_buffer);

    float frequency = 440;
    float amplitude = 0.5;
    float phase = 0;

    int i;
    for (i = 0; i < SAMPLE_RATE * 5; i++) {
        float sample = sine(frequency * phase);
        push_sample(&input_buffer, sample * amplitude);
        phase += frequency / SAMPLE_RATE;
    }

    process_buffer(&input_buffer, square);
    process_buffer(&input_buffer, sawtooth);
    process_buffer(&input_buffer, triangle);
    process_buffer(&input_buffer, sine);
    process_buffer(&input_buffer, noise);

    destroy_buffer(&input_buffer);
    destroy_buffer(&output_buffer);

    return 0;
}