//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

// Function to apply gain to audio samples
void apply_gain(float *samples, int num_samples, float gain) {
    for (int i = 0; i < num_samples; i++) {
        samples[i] *= gain;
    }
}

// Main function, processes the audio file
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <gain>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float gain = atof(argv[3]);

    // Open input file
    SNDFILE *input_sndfile;
    SF_INFO input_info;
    input_sndfile = sf_open(input_file, SFM_READ, &input_info);
    if (!input_sndfile) {
        fprintf(stderr, "Failed to open input file: %s\n", sf_strerror(NULL));
        return EXIT_FAILURE;
    }

    // Allocate buffer for audio samples
    int num_samples = input_info.frames * input_info.channels;
    float *samples = (float *) malloc(num_samples * sizeof(float));
    if (!samples) {
        fprintf(stderr, "Memory allocation failed\n");
        sf_close(input_sndfile);
        return EXIT_FAILURE;
    }

    // Read samples from the input file
    sf_count_t read_count = sf_readf_float(input_sndfile, samples, input_info.frames);
    if (read_count != input_info.frames) {
        fprintf(stderr, "Failed to read audio samples: %s\n", sf_strerror(input_sndfile));
        free(samples);
        sf_close(input_sndfile);
        return EXIT_FAILURE;
    }

    // Apply gain to samples
    apply_gain(samples, num_samples, gain);

    // Open output file
    SNDFILE *output_sndfile;
    output_sndfile = sf_open(output_file, SFM_WRITE, &input_info);
    if (!output_sndfile) {
        fprintf(stderr, "Failed to open output file: %s\n", sf_strerror(NULL));
        free(samples);
        sf_close(input_sndfile);
        return EXIT_FAILURE;
    }

    // Write modified samples to the output file
    sf_count_t write_count = sf_writef_float(output_sndfile, samples, read_count);
    if (write_count != read_count) {
        fprintf(stderr, "Failed to write audio samples: %s\n", sf_strerror(output_sndfile));
        free(samples);
        sf_close(input_sndfile);
        sf_close(output_sndfile);
        return EXIT_FAILURE;
    }

    // Clean up
    free(samples);
    sf_close(input_sndfile);
    sf_close(output_sndfile);

    printf("Audio processing completed successfully. Output saved to: %s\n", output_file);
    return EXIT_SUCCESS;
}