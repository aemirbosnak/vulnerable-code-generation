//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FRAME_SIZE 1024
#define NUM_CHANNELS 2
#define NUM_SECONDS 5

typedef struct {
    float *data;
    int capacity;
    int size;
} AudioBuffer;

typedef struct {
    AudioBuffer input;
    AudioBuffer output;
} AudioContext;

void init_audio_buffer(AudioBuffer *buffer, int capacity) {
    buffer->data = (float *)malloc(capacity * sizeof(float));
    buffer->capacity = capacity;
    buffer->size = 0;
}

void destroy_audio_buffer(AudioBuffer *buffer) {
    free(buffer->data);
}

void push_audio_buffer(AudioBuffer *buffer, float sample) {
    if (buffer->size >= buffer->capacity) {
        fprintf(stderr, "Audio buffer overflow\n");
        exit(1);
    }
    buffer->data[buffer->size++] = sample;
}

void init_audio_context(AudioContext *context) {
    init_audio_buffer(&context->input, FRAME_SIZE * NUM_SECONDS * NUM_CHANNELS);
    init_audio_buffer(&context->output, FRAME_SIZE * NUM_SECONDS * NUM_CHANNELS);
}

void destroy_audio_context(AudioContext *context) {
    destroy_audio_buffer(&context->input);
    destroy_audio_buffer(&context->output);
}

void process_audio(AudioContext *context) {
    int i, j, k;
    float *input_data = context->input.data;
    float *output_data = context->output.data;
    for (i = 0; i < NUM_SECONDS * SAMPLE_RATE / FRAME_SIZE; i++) {
        for (j = 0; j < FRAME_SIZE; j++) {
            for (k = 0; k < NUM_CHANNELS; k++) {
                output_data[i * FRAME_SIZE * NUM_CHANNELS + j * NUM_CHANNELS + k] = input_data[i * FRAME_SIZE * NUM_CHANNELS + j * NUM_CHANNELS + k] * 2.0f;
            }
        }
        input_data += FRAME_SIZE * NUM_CHANNELS;
        output_data += FRAME_SIZE * NUM_CHANNELS;
    }
}

int main() {
    AudioContext context;
    init_audio_context(&context);
    process_audio(&context);
    destroy_audio_context(&context);
    return 0;
}