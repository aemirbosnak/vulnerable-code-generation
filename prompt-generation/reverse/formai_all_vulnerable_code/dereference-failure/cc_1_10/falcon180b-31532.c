//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024
#define PI 3.14159265358979323846

// Function prototypes
void generate_sine_wave(float *buffer, int buffer_size);
void add_reverb(float *buffer, int buffer_size);

int main() {
    float *input_buffer = (float *) malloc(BUFFER_SIZE * sizeof(float));
    float *output_buffer = (float *) malloc(BUFFER_SIZE * sizeof(float));

    // Initialize input buffer with random values
    for (int i = 0; i < BUFFER_SIZE; i++) {
        input_buffer[i] = rand() % 1000;
    }

    // Process input buffer
    generate_sine_wave(output_buffer, BUFFER_SIZE);
    add_reverb(output_buffer, BUFFER_SIZE);

    // Write output buffer to file
    FILE *output_file = fopen("output.wav", "wb");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    fwrite(output_buffer, sizeof(float), BUFFER_SIZE, output_file);

    fclose(output_file);
    free(input_buffer);
    free(output_buffer);

    return 0;
}

void generate_sine_wave(float *buffer, int buffer_size) {
    float frequency = 440; // Hz
    float amplitude = 0.5;
    float phase = 0;

    for (int i = 0; i < buffer_size; i++) {
        float t = (float) i / SAMPLE_RATE;
        float sample = amplitude * sin(2 * PI * frequency * t + phase);
        buffer[i] = sample;
        phase += 2 * PI * frequency / SAMPLE_RATE;
    }
}

void add_reverb(float *buffer, int buffer_size) {
    float decay = 0.5;
    float wet_dry_mix = 0.5;

    float *reverb_buffer = (float *) malloc(BUFFER_SIZE * sizeof(float));
    memset(reverb_buffer, 0, BUFFER_SIZE * sizeof(float));

    for (int i = 0; i < buffer_size; i++) {
        float dry_sample = buffer[i];
        float wet_sample = reverb_buffer[i] * decay;
        float mix = wet_sample + dry_sample * (1 - wet_dry_mix);
        buffer[i] = mix;

        // Update reverb buffer
        for (int j = 0; j < 4; j++) {
            int index = (i - j * 8) % BUFFER_SIZE;
            if (index < 0) {
                index += BUFFER_SIZE;
            }
            reverb_buffer[index] += wet_sample * 0.05;
        }
    }

    free(reverb_buffer);
}