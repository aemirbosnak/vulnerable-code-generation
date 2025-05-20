//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

#define FILTER_CUTOFF 0.1 // Cutoff frequency for the low-pass filter
#define MAX_SAMPLES 48000 // Increase or decrease as needed

void apply_low_pass_filter(float *input, float *output, int num_samples, float alpha) {
    output[0] = input[0]; // First sample is the same

    for (int i = 1; i < num_samples; i++) {
        output[i] = (alpha * input[i]) + ((1.0 - alpha) * output[i - 1]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav>\n", argv[0]);
        return 1;
    }

    SNDFILE *infile, *outfile;
    SF_INFO sfinfo;
    float *buffer;
    float *filtered_buffer;
    int num_samples;

    // Open the input WAV file
    infile = sf_open(argv[1], SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Could not open input file: %s\n", sf_strerror(NULL));
        return 1;
    }

    // Allocate memory for audio data
    num_samples = sfinfo.frames * sfinfo.channels;
    buffer = (float *)malloc(num_samples * sizeof(float));
    filtered_buffer = (float *)malloc(num_samples * sizeof(float));
    if (!buffer || !filtered_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        sf_close(infile);
        return 1;
    }

    // Read audio samples from the input file
    sf_readf_float(infile, buffer, sfinfo.frames);

    // Calculate alpha based on desired cutoff frequency
    float alpha = FILTER_CUTOFF;

    // Apply the low-pass filter
    apply_low_pass_filter(buffer, filtered_buffer, num_samples, alpha);

    // Open the output WAV file
    outfile = sf_open(argv[2], SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Could not open output file: %s\n", sf_strerror(NULL));
        free(buffer);
        free(filtered_buffer);
        sf_close(infile);
        return 1;
    }

    // Write the filtered audio samples to the output file
    sf_writef_float(outfile, filtered_buffer, sfinfo.frames);

    // Cleanup
    free(buffer);
    free(filtered_buffer);
    sf_close(infile);
    sf_close(outfile);

    printf("Audio processing complete. Filtered audio saved to: %s\n", argv[2]);
    return 0;
}