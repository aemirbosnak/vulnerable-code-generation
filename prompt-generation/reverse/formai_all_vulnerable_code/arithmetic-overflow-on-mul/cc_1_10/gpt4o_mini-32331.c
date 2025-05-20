//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

#define GAIN 1.5f  // Let's boost the audio by 50%! 

void apply_gain(float *buffer, sf_count_t num_samples) {
    for (sf_count_t i = 0; i < num_samples; i++) {
        buffer[i] *= GAIN;
    }
}

void process_audio(const char *input_file, const char *output_file) {
    SF_INFO sfinfo;
    SNDFILE *infile = sf_open(input_file, SFM_READ, &sfinfo);
    
    if (!infile) {
        printf("Could not open input file: %s\n", sf_strerror(NULL));
        return;
    }

    SNDFILE *outfile = sf_open(output_file, SFM_WRITE, &sfinfo);
    
    if (!outfile) {
        printf("Could not open output file: %s\n", sf_strerror(NULL));
        sf_close(infile);
        return;
    }

    sf_count_t num_samples = sfinfo.frames * sfinfo.channels;
    float *buffer = malloc(num_samples * sizeof(float));

    // Read the input samples
    sf_count_t num_read = sf_readf_float(infile, buffer, sfinfo.frames);
    printf("Read %ld samples from %s!\n", num_read, input_file);

    // Apply gain effect
    apply_gain(buffer, num_read * sfinfo.channels);
    
    // Write to output file
    sf_count_t num_written = sf_writef_float(outfile, buffer, num_read);
    printf("Wrote %ld samples to %s!\n", num_written, output_file);

    free(buffer);
    sf_close(infile);
    sf_close(outfile);
    printf("Audio processing completed successfully! 🎶\n");
}

int main(int argc, char *argv[]) {
    // Checking for correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];

    printf("Let's process some audio!\n");
    printf("Input File: %s\nOutput File: %s\n", input_file, output_file);

    process_audio(input_file, output_file);
    printf("All done! Enjoy your boosted audio! 🎉\n");
    return EXIT_SUCCESS;
}