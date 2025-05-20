//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FRAME_SIZE 1024
#define NUM_FRAMES 44100/FRAME_SIZE

typedef struct {
    float *data;
    int size;
} Frame;

void generate_sine_wave(float *buffer, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        float t = (float)i / SAMPLE_RATE;
        buffer[i] = sin(2 * M_PI * 440 * t);
    }
}

void apply_lowpass_filter(float *buffer, int num_samples) {
    for (int i = 0; i < num_samples; i++) {
        float b0 = 1.0f;
        float b1 = -2.0f;
        float a1 = 1.0f;
        float y1 = buffer[i] + (b0 * buffer[i]) - (b1 * buffer[i-1]) + (a1 * y1);
        buffer[i] = y1;
    }
}

int main() {
    Frame *input_frames = (Frame*)malloc(NUM_FRAMES * sizeof(Frame));
    Frame *output_frames = (Frame*)malloc(NUM_FRAMES * sizeof(Frame));

    for (int i = 0; i < NUM_FRAMES; i++) {
        input_frames[i].data = (float*)malloc(FRAME_SIZE * sizeof(float));
        input_frames[i].size = FRAME_SIZE;
        output_frames[i].data = (float*)malloc(FRAME_SIZE * sizeof(float));
        output_frames[i].size = FRAME_SIZE;
    }

    for (int i = 0; i < NUM_FRAMES; i++) {
        generate_sine_wave(input_frames[i].data, FRAME_SIZE);
        apply_lowpass_filter(input_frames[i].data, FRAME_SIZE);
    }

    for (int i = 0; i < NUM_FRAMES; i++) {
        free(input_frames[i].data);
        free(output_frames[i].data);
    }

    free(input_frames);
    free(output_frames);

    return 0;
}