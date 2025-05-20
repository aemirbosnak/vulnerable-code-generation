//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sndfile.h>

#define SAMPLE_RATE 44100
#define PI 3.14159265358979323846

void apply_reverb(float *input, float *output, int num_samples, float decay) {
    int delay_samples = SAMPLE_RATE / 10; // 100 ms delay
    for (int i = 0; i < num_samples; i++) {
        output[i] = input[i];
        if (i >= delay_samples) {
            output[i] += input[i - delay_samples] * decay;
        }
    }
}

void apply_fade_in(float *buffer, int num_samples, float fade_duration) {
    int fade_samples = (int)(fade_duration * SAMPLE_RATE);
    for (int i = 0; i < fade_samples && i < num_samples; i++) {
        buffer[i] *= (float)i / fade_samples;
    }
}

void apply_fade_out(float *buffer, int num_samples, float fade_duration) {
    int fade_samples = (int)(fade_duration * SAMPLE_RATE);
    for (int i = 0; i < fade_samples && (num_samples - i - 1) >= 0; i++) {
        buffer[num_samples - i - 1] *= (float)i / fade_samples;
    }
}

void generate_sine_wave(float *buffer, int num_samples, float frequency) {
    for (int i = 0; i < num_samples; i++) {
        buffer[i] = 0.5f * sinf(2 * PI * frequency * ((float)i / SAMPLE_RATE));
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // Open input file
    SF_INFO sf_info;
    SNDFILE *in_file = sf_open(argv[1], SFM_READ, &sf_info);
    if (!in_file) {
        fprintf(stderr, "Could not open input file: %s\n", sf_strerror(NULL));
        return 1;
    }

    // Prepare output file
    SNDFILE *out_file = sf_open(argv[2], SFM_WRITE, &sf_info);
    if (!out_file) {
        fprintf(stderr, "Could not open output file: %s\n", sf_strerror(NULL));
        sf_close(in_file);
        return 1;
    }

    // Allocate buffers
    int num_samples = sf_info.frames * sf_info.channels;
    float *input_buffer = malloc(num_samples * sizeof(float));
    float *output_buffer = malloc(num_samples * sizeof(float));

    // Read samples from input
    sf_readf_float(in_file, input_buffer, sf_info.frames);

    // Apply effects
    apply_fade_in(input_buffer, num_samples, 2.0f);  // 2 seconds fade-in
    apply_reverb(input_buffer, output_buffer, num_samples, 0.5f); // 50% decay
    apply_fade_out(output_buffer, num_samples, 2.0f); // 2 seconds fade-out

    // Write to output
    sf_writef_float(out_file, output_buffer, sf_info.frames);

    // Cleanup
    free(input_buffer);
    free(output_buffer);
    sf_close(in_file);
    sf_close(out_file);

    printf("Audio processing complete! Output saved to %s\n", argv[2]);
    return 0;
}