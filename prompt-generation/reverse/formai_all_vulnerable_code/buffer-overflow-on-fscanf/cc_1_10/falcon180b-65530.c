//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SAMPLES 1000000
#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct {
    float *samples;
    int size;
} SampleBuffer;

void init_buffer(SampleBuffer *buffer) {
    buffer->samples = (float *) malloc(MAX_SAMPLES * sizeof(float));
    buffer->size = 0;
}

void add_sample(SampleBuffer *buffer, float sample) {
    if (buffer->size >= MAX_SAMPLES) {
        printf("Error: Buffer overflow\n");
        exit(1);
    }
    buffer->samples[buffer->size++] = sample;
}

void process_buffer(SampleBuffer *buffer, float (*process_func)(float)) {
    int i;
    for (i = 0; i < buffer->size; i++) {
        buffer->samples[i] = process_func(buffer->samples[i]);
    }
}

float square(float x) {
    return x * x;
}

float sine(float x) {
    return sin(x * M_PI / SAMPLE_RATE);
}

int main() {
    SampleBuffer input_buffer, output_buffer;
    init_buffer(&input_buffer);
    init_buffer(&output_buffer);

    float sample;
    while (fscanf(stdin, "%f", &sample)!= EOF) {
        add_sample(&input_buffer, sample);
    }

    process_buffer(&input_buffer, square);
    process_buffer(&input_buffer, sine);

    int i;
    for (i = 0; i < input_buffer.size; i += BUFFER_SIZE) {
        int j;
        for (j = i; j < i + BUFFER_SIZE && j < input_buffer.size; j++) {
            fprintf(stdout, "%f\n", input_buffer.samples[j]);
        }
    }

    return 0;
}