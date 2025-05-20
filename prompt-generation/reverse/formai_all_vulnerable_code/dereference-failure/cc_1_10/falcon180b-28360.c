//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define SAMPLE_RATE 44100
#define SAMPLE_SIZE 1024
#define NUM_SAMPLES (SAMPLE_RATE / SAMPLE_SIZE)

typedef struct {
    int index;
    int max_index;
    float *buffer;
} DelayLine;

float *create_delay_line(int max_index) {
    float *buffer = (float *) malloc(sizeof(float) * max_index);
    for (int i = 0; i < max_index; i++) {
        buffer[i] = 0.0;
    }
    return buffer;
}

void destroy_delay_line(DelayLine *delay_line) {
    free(delay_line->buffer);
}

void process_audio(float *input_buffer, float *output_buffer, DelayLine *delay_line) {
    for (int i = 0; i < NUM_SAMPLES; i++) {
        float delayed_sample = delay_line->buffer[delay_line->index];
        float current_sample = input_buffer[i];
        float wet_sample = current_sample + delayed_sample;
        output_buffer[i] = wet_sample;
        delay_line->buffer[delay_line->index] = current_sample;
        delay_line->index++;
        if (delay_line->index >= delay_line->max_index) {
            delay_line->index = 0;
        }
    }
}

int main() {
    srand(time(NULL));
    float *input_buffer = (float *) malloc(sizeof(float) * SAMPLE_SIZE);
    float *output_buffer = (float *) malloc(sizeof(float) * SAMPLE_SIZE);
    DelayLine delay_line = {0, SAMPLE_SIZE / 2, create_delay_line(SAMPLE_SIZE / 2)};

    for (int i = 0; i < SAMPLE_SIZE; i++) {
        input_buffer[i] = rand() % 10000 / 10000.0;
    }

    process_audio(input_buffer, output_buffer, &delay_line);

    for (int i = 0; i < SAMPLE_SIZE; i++) {
        printf("%f\n", output_buffer[i]);
    }

    destroy_delay_line(&delay_line);
    free(input_buffer);
    free(output_buffer);

    return 0;
}