//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sndfile.h>

#define MAX_GAIN 2.0            // Maximum gain factor
#define BUFFER_SIZE 1024        // Size of the audio buffer

void apply_gain(float *buffer, sf_count_t frames, float gain) {
    for (sf_count_t i = 0; i < frames; i++) {
        buffer[i] *= gain;
        // Clamp the values to prevent overflow
        if (buffer[i] > 1.0f) {
            buffer[i] = 1.0f;
        } else if (buffer[i] < -1.0f) {
            buffer[i] = -1.0f;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <gain>\n", argv[0]);
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    float gain = atof(argv[3]);
    
    // Validate gain value
    if (gain < 0.0 || gain > MAX_GAIN) {
        printf("Gain must be between 0.0 and %.1f\n", MAX_GAIN);
        return 1;
    }

    // Open input audio file
    SF_INFO sfinfo;
    SNDFILE *infile = sf_open(input_filename, SFM_READ, &sfinfo);
    if (!infile) {
        printf("Failed to open input file: %s\n", sf_strerror(NULL));
        return 1;
    }

    // Prepare output audio file
    SNDFILE *outfile = sf_open(output_filename, SFM_WRITE, &sfinfo);
    if (!outfile) {
        printf("Failed to open output file: %s\n", sf_strerror(NULL));
        sf_close(infile);
        return 1;
    }

    // Buffer to hold audio samples
    float buffer[BUFFER_SIZE];
    sf_count_t read_frames;
    sf_count_t total_frames = 0;

    // Process audio data
    while ((read_frames = sf_readf_float(infile, buffer, BUFFER_SIZE)) > 0) {
        apply_gain(buffer, read_frames, gain);
        total_frames += read_frames;

        // Write processed audio to the output file
        sf_writef_float(outfile, buffer, read_frames);
    }

    printf("Processed %lld frames from '%s' with gain of %.2f.\n", total_frames, input_filename, gain);

    // Clean up
    sf_close(infile);
    sf_close(outfile);

    return 0;
}