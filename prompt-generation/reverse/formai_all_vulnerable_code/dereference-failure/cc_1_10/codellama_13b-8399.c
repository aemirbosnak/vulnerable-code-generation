//Code Llama-13B DATASET v1.0 Category: Audio processing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Define constants
#define NUM_SAMPLES 1024
#define SAMPLE_RATE 44100
#define FREQ 440
#define AMP 0.5

// Define struct for audio sample
typedef struct {
    float left;
    float right;
} sample_t;

// Define function to generate sine wave
void generate_sine_wave(sample_t* samples, int num_samples, int sample_rate, float freq, float amp) {
    // Calculate phase increment
    float phase_inc = (2 * M_PI * freq) / (float)sample_rate;

    // Generate samples
    for (int i = 0; i < num_samples; i++) {
        // Calculate sample value
        float sample = amp * sin(phase_inc * i);

        // Assign sample to left and right channels
        samples[i].left = sample;
        samples[i].right = sample;
    }
}

// Define function to play audio
void play_audio(sample_t* samples, int num_samples) {
    // Play samples
    for (int i = 0; i < num_samples; i++) {
        // Get sample value
        float sample = samples[i].left;

        // Play sample
        printf("%f\n", sample);
    }
}

// Define main function
int main() {
    // Allocate memory for samples
    sample_t* samples = malloc(NUM_SAMPLES * sizeof(sample_t));

    // Generate sine wave
    generate_sine_wave(samples, NUM_SAMPLES, SAMPLE_RATE, FREQ, AMP);

    // Play audio
    play_audio(samples, NUM_SAMPLES);

    // Free memory
    free(samples);

    return 0;
}