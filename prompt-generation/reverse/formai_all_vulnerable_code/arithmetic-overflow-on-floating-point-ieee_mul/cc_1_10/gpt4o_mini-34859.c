//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sndfile.h>

#define FRAME_SIZE 1024
#define SAMPLE_RATE 44100

// Function prototypes
void apply_gain(float *buffer, int frames, float gain);
void print_waveform(float *buffer, int frames);
void process_audio(const char *input_file, const char *output_file, float gain);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        return EXIT_FAILURE;
    }

    float gain = atof(argv[3]);
    process_audio(argv[1], argv[2], gain);
    
    return EXIT_SUCCESS;
}

// Apply gain to the audio buffer
void apply_gain(float *buffer, int frames, float gain) {
    for (int i = 0; i < frames; i++) {
        buffer[i] *= gain;
    }
}

// Print waveform to console (first 10 samples)
void print_waveform(float *buffer, int frames) {
    printf("Waveform Preview:\n");
    for (int i = 0; i < frames && i < 10; i++) {
        printf("Sample %d: %f\n", i, buffer[i]);
    }
}

// Process the audio file
void process_audio(const char *input_file, const char *output_file, float gain) {
    SNDFILE *infile, *outfile;
    SF_INFO sfinfo;
    float *buffer;
    int frames;

    infile = sf_open(input_file, SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Error opening input file '%s': %s\n", input_file, sf_strerror(NULL));
        return;
    }

    outfile = sf_open(output_file, SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Error opening output file '%s': %s\n", output_file, sf_strerror(NULL));
        sf_close(infile);
        return;
    }

    buffer = (float *)malloc(FRAME_SIZE * sizeof(float));
    if (!buffer) {
        fprintf(stderr, "Error allocating memory for buffer\n");
        sf_close(infile);
        sf_close(outfile);
        return;
    }

    while ((frames = sf_readf_float(infile, buffer, FRAME_SIZE)) > 0) {
        apply_gain(buffer, frames, gain);
        print_waveform(buffer, frames);
        sf_writef_float(outfile, buffer, frames);
    }

    free(buffer);
    sf_close(infile);
    sf_close(outfile);

    printf("Processing complete. Output written to '%s'\n", output_file);
}