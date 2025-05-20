//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

#define VOLUME_BOOST 2.0  // Factor to boost the audio volume

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <input_file> <output_file>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];

    SF_INFO sf_info;
    SNDFILE *in_file, *out_file;

    // Open input audio file
    in_file = sf_open(input_file, SFM_READ, &sf_info);
    if (!in_file) {
        fprintf(stderr, "Failed to open input file: %s\n", sf_strerror(NULL));
        return 1;
    }

    // Print the file info
    printf("Input File Info:\n");
    printf("  Sample Rate: %d\n", sf_info.samplerate);
    printf("  Channels: %d\n", sf_info.channels);
    printf("  Format: %d\n", sf_info.format);

    // Open output audio file
    out_file = sf_open(output_file, SFM_WRITE, &sf_info);
    if (!out_file) {
        fprintf(stderr, "Failed to open output file: %s\n", sf_strerror(NULL));
        sf_close(in_file);
        return 1;
    }

    // Allocate memory for a buffer to hold audio samples
    int buffer_size = 1024;
    float *buffer = (float *)malloc(buffer_size * sf_info.channels * sizeof(float));
    if (!buffer) {
        fprintf(stderr, "Failed to allocate memory for buffer.\n");
        sf_close(in_file);
        sf_close(out_file);
        return 1;
    }

    // Process the audio data
    sf_count_t num_frames;
    while ((num_frames = sf_readf_float(in_file, buffer, buffer_size)) > 0) {
        // Apply volume boost
        for (sf_count_t i = 0; i < num_frames * sf_info.channels; i++) {
            buffer[i] *= VOLUME_BOOST;  // Increase volume
        }

        // Write processed frames to output file
        sf_writef_float(out_file, buffer, num_frames);
    }

    // Cleanup and close files
    free(buffer);
    sf_close(in_file);
    sf_close(out_file);

    printf("Audio processing completed successfully.\n");
    return 0;
}