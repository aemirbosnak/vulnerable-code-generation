//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct {
    float *buffer;
    int bufferSize;
    int readIndex;
    int writeIndex;
} AudioBuffer;

AudioBuffer *createAudioBuffer(int size) {
    AudioBuffer *buffer = (AudioBuffer *)malloc(sizeof(AudioBuffer));
    buffer->buffer = (float *)malloc(sizeof(float) * size);
    buffer->bufferSize = size;
    buffer->readIndex = 0;
    buffer->writeIndex = 0;
    return buffer;
}

void destroyAudioBuffer(AudioBuffer *buffer) {
    free(buffer->buffer);
    free(buffer);
}

void writeSample(AudioBuffer *buffer, float sample) {
    buffer->buffer[buffer->writeIndex] = sample;
    buffer->writeIndex = (buffer->writeIndex + 1) % buffer->bufferSize;
}

float readSample(AudioBuffer *buffer) {
    float sample = buffer->buffer[buffer->readIndex];
    buffer->readIndex = (buffer->readIndex + 1) % buffer->bufferSize;
    return sample;
}

void processAudio(AudioBuffer *inputBuffer, AudioBuffer *outputBuffer, int numSamples) {
    for (int i = 0; i < numSamples; i++) {
        float sample = readSample(inputBuffer);
        sample *= 2.0f;
        writeSample(outputBuffer, sample);
    }
}

int main() {
    AudioBuffer *inputBuffer = createAudioBuffer(BUFFER_SIZE);
    AudioBuffer *outputBuffer = createAudioBuffer(BUFFER_SIZE);

    for (int i = 0; i < SAMPLE_RATE * 5; i++) {
        float sample = sin(2 * M_PI * i / SAMPLE_RATE);
        writeSample(inputBuffer, sample);
    }

    processAudio(inputBuffer, outputBuffer, SAMPLE_RATE * 5);

    for (int i = 0; i < SAMPLE_RATE * 5; i++) {
        float sample = readSample(outputBuffer);
        printf("%f\n", sample);
    }

    destroyAudioBuffer(inputBuffer);
    destroyAudioBuffer(outputBuffer);

    return 0;
}