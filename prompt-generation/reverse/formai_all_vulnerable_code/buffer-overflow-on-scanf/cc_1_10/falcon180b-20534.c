//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SAMPLES 100000
#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

typedef struct {
    double* samples;
    int num_samples;
} AudioBuffer;

AudioBuffer* create_buffer() {
    AudioBuffer* buffer = malloc(sizeof(AudioBuffer));
    buffer->samples = malloc(MAX_SAMPLES * sizeof(double));
    buffer->num_samples = 0;
    return buffer;
}

void add_sample(AudioBuffer* buffer, double sample) {
    if (buffer->num_samples >= MAX_SAMPLES) {
        printf("Buffer is full!\n");
        return;
    }
    buffer->samples[buffer->num_samples] = sample;
    buffer->num_samples++;
}

void process_buffer(AudioBuffer* buffer, double (*process_func)(double)) {
    for (int i = 0; i < buffer->num_samples; i++) {
        buffer->samples[i] = process_func(buffer->samples[i]);
    }
}

double sine_wave(double t) {
    return sin(2 * PI * SAMPLE_RATE * t);
}

int main() {
    AudioBuffer* buffer = create_buffer();
    int choice;
    double sample;

    while (1) {
        printf("1. Add sample\n");
        printf("2. Process buffer\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter sample value: ");
                scanf("%lf", &sample);
                add_sample(buffer, sample);
                break;
            case 2:
                process_buffer(buffer, sine_wave);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}