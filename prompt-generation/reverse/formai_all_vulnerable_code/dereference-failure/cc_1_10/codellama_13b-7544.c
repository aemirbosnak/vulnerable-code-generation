//Code Llama-13B DATASET v1.0 Category: Audio processing ; Style: safe
// Safe C Audio Processing Example Program

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <float.h>
#include <string.h>
#include <time.h>
#include <assert.h>

#define BUFFER_SIZE 4096
#define SAMPLE_RATE 44100
#define FREQUENCY 440
#define SAMPLES_PER_FRAME 1024

typedef struct {
    float* buffer;
    int size;
} AudioBuffer;

void initAudioBuffer(AudioBuffer* buffer, int size) {
    buffer->buffer = malloc(size * sizeof(float));
    buffer->size = size;
}

void freeAudioBuffer(AudioBuffer* buffer) {
    free(buffer->buffer);
}

void fillBuffer(AudioBuffer* buffer, float value) {
    for (int i = 0; i < buffer->size; i++) {
        buffer->buffer[i] = value;
    }
}

void generateSineWave(AudioBuffer* buffer, float frequency, float sampleRate) {
    float radians = (2 * M_PI * frequency) / sampleRate;
    for (int i = 0; i < buffer->size; i++) {
        buffer->buffer[i] = sinf(i * radians);
    }
}

void generateSquareWave(AudioBuffer* buffer, float frequency, float sampleRate) {
    float radians = (2 * M_PI * frequency) / sampleRate;
    for (int i = 0; i < buffer->size; i++) {
        buffer->buffer[i] = (sinf(i * radians) > 0) ? 1.0 : -1.0;
    }
}

void generateSawtoothWave(AudioBuffer* buffer, float frequency, float sampleRate) {
    float radians = (2 * M_PI * frequency) / sampleRate;
    for (int i = 0; i < buffer->size; i++) {
        buffer->buffer[i] = (2 * i / buffer->size) - 1;
    }
}

void generateTriangleWave(AudioBuffer* buffer, float frequency, float sampleRate) {
    float radians = (2 * M_PI * frequency) / sampleRate;
    for (int i = 0; i < buffer->size; i++) {
        buffer->buffer[i] = (2 * fabs(sinf(i * radians)) - 1);
    }
}

void playAudio(AudioBuffer* buffer, float sampleRate) {
    for (int i = 0; i < buffer->size; i++) {
        printf("%f\n", buffer->buffer[i]);
    }
}

int main() {
    AudioBuffer buffer;
    initAudioBuffer(&buffer, BUFFER_SIZE);

    generateSineWave(&buffer, FREQUENCY, SAMPLE_RATE);
    playAudio(&buffer, SAMPLE_RATE);

    generateSquareWave(&buffer, FREQUENCY, SAMPLE_RATE);
    playAudio(&buffer, SAMPLE_RATE);

    generateSawtoothWave(&buffer, FREQUENCY, SAMPLE_RATE);
    playAudio(&buffer, SAMPLE_RATE);

    generateTriangleWave(&buffer, FREQUENCY, SAMPLE_RATE);
    playAudio(&buffer, SAMPLE_RATE);

    freeAudioBuffer(&buffer);

    return 0;
}