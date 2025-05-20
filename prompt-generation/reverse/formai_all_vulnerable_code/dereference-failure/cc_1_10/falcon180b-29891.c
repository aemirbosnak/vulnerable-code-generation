//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct {
    float *buffer;
    int buffer_size;
    int buffer_index;
} AudioBuffer;

AudioBuffer create_buffer(int size) {
    AudioBuffer buffer = {
       .buffer = (float *)malloc(size * sizeof(float)),
       .buffer_size = size,
       .buffer_index = 0
    };
    for (int i = 0; i < size; i++) {
        buffer.buffer[i] = 0.0;
    }
    return buffer;
}

void destroy_buffer(AudioBuffer *buffer) {
    free(buffer->buffer);
}

void process_buffer(AudioBuffer *buffer, float (*process)(float)) {
    for (int i = 0; i < buffer->buffer_size; i++) {
        buffer->buffer[i] = process(buffer->buffer[i]);
    }
}

float sine_wave(float x) {
    return sin(2 * M_PI * x * SAMPLE_RATE / BUFFER_SIZE);
}

int main() {
    AudioBuffer buffer = create_buffer(BUFFER_SIZE);

    for (int i = 0; i < BUFFER_SIZE; i++) {
        process_buffer(&buffer, sine_wave);
    }

    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%f\n", buffer.buffer[i]);
    }

    destroy_buffer(&buffer);

    return 0;
}