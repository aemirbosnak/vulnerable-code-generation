//GPT-4o-mini DATASET v1.0 Category: Digital signal processing ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

#define BUFFER_SIZE 1024
#define DISTORTION_FACTOR 5.0

// Function to apply distortion to the audio samples
void applyDistortion(float *samples, sf_count_t num_samples) {
    for (sf_count_t i = 0; i < num_samples; i++) {
        // Distortion effect
        samples[i] *= DISTORTION_FACTOR;
        // Clipping to prevent overflow
        if (samples[i] > 1.0f) samples[i] = 1.0f;
        if (samples[i] < -1.0f) samples[i] = -1.0f;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    SNDFILE *infile, *outfile;
    SF_INFO sfinfo;
    float samples[BUFFER_SIZE];
    sf_count_t read_count;

    // Open input audio file
    if (!(infile = sf_open(argv[1], SFM_READ, &sfinfo))) {
        fprintf(stderr, "Unable to open input file: %s\n", sf_strerror(NULL));
        return 1;
    }

    // Open output audio file
    if (!(outfile = sf_open(argv[2], SFM_WRITE, &sfinfo))) {
        fprintf(stderr, "Unable to open output file: %s\n", sf_strerror(NULL));
        sf_close(infile);
        return 1;
    }

    // Process the audio file in chunks
    while ((read_count = sf_readf_float(infile, samples, BUFFER_SIZE)) > 0) {
        // Apply distortion to the read samples
        applyDistortion(samples, read_count);

        // Write the distorted samples to the output file
        sf_writef_float(outfile, samples, read_count);
    }

    // Close the files
    sf_close(infile);
    sf_close(outfile);

    printf("Finished processing the audio file: %s -> %s\n", argv[1], argv[2]);
    return 0;
}