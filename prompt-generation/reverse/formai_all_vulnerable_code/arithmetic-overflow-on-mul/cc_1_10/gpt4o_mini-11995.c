//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

#define GAIN_FACTOR 1.5 // Volume gain factor (1.0 = no change, >1.0 = amplification)

void apply_gain(float *samples, sf_count_t num_samples, float gain) {
    for (sf_count_t i = 0; i < num_samples; i++) {
        samples[i] *= gain;
        // Clipping prevention
        if (samples[i] > 1.0f) samples[i] = 1.0f;
        else if (samples[i] < -1.0f) samples[i] = -1.0f;
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav>\n", argv[0]);
        return 1;
    }

    SNDFILE *infile, *outfile;
    SF_INFO sfinfo;

    // Open the input file
    infile = sf_open(argv[1], SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Error opening input file: %s\n", sf_strerror(NULL));
        return 1;
    }

    // Print input file info
    printf("Input file: %s\n", argv[1]);
    printf("Sample Rate: %d\n", sfinfo.samplerate);
    printf("Channels: %d\n", sfinfo.channels);
    printf("Frames: %lld\n", sfinfo.frames);
    
    // Allocate memory for samples
    float *samples = (float *)malloc(sfinfo.frames * sfinfo.channels * sizeof(float));
    if (!samples) {
        fprintf(stderr, "Memory allocation failed\n");
        sf_close(infile);
        return 1;
    }

    // Read samples from the input file
    sf_count_t num_samples = sf_readf_float(infile, samples, sfinfo.frames);
    if (num_samples < 0) {
        fprintf(stderr, "Error reading samples: %s\n", sf_strerror(infile));
        free(samples);
        sf_close(infile);
        return 1;
    }

    // Apply gain effect
    apply_gain(samples, num_samples * sfinfo.channels, GAIN_FACTOR);

    // Open the output file
    outfile = sf_open(argv[2], SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Error opening output file: %s\n", sf_strerror(NULL));
        free(samples);
        sf_close(infile);
        return 1;
    }

    // Write processed samples to the output file
    sf_count_t written_samples = sf_writef_float(outfile, samples, num_samples);
    if (written_samples < 0) {
        fprintf(stderr, "Error writing samples: %s\n", sf_strerror(outfile));
        free(samples);
        sf_close(infile);
        sf_close(outfile);
        return 1;
    }

    // Clean up
    printf("Processed %lld samples and wrote to %s\n", written_samples, argv[2]);
    free(samples);
    sf_close(infile);
    sf_close(outfile);
    return 0;
}