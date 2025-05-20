//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

void reverse_audio(const char *input_file, const char *output_file) {
    SF_INFO sf_info;
    SNDFILE *infile, *outfile;
    
    // Open the input audio file
    infile = sf_open(input_file, SFM_READ, &sf_info);
    if (!infile) {
        fprintf(stderr, "Could not open input file: %s\n", input_file);
        return;
    }

    // Open the output audio file for writing
    outfile = sf_open(output_file, SFM_WRITE, &sf_info);
    if (!outfile) {
        fprintf(stderr, "Could not open output file: %s\n", output_file);
        sf_close(infile);
        return;
    }

    // Allocate memory for the audio samples
    int num_samples = sf_info.frames * sf_info.channels;
    float *buffer = malloc(num_samples * sizeof(float));
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        sf_close(infile);
        sf_close(outfile);
        return;
    }

    // Read samples from the input file
    sf_readf_float(infile, buffer, sf_info.frames);

    // Reverse the samples
    for (int i = 0; i < sf_info.frames / 2; i++) {
        for (int channel = 0; channel < sf_info.channels; channel++) {
            float temp = buffer[i * sf_info.channels + channel];
            buffer[i * sf_info.channels + channel] = buffer[(sf_info.frames - 1 - i) * sf_info.channels + channel];
            buffer[(sf_info.frames - 1 - i) * sf_info.channels + channel] = temp;
        }
    }

    // Write the reversed samples to the output file
    sf_writef_float(outfile, buffer, sf_info.frames);

    // Cleanup
    free(buffer);
    sf_close(infile);
    sf_close(outfile);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    reverse_audio(argv[1], argv[2]);
    printf("Audio reversed successfully from %s to %s\n", argv[1], argv[2]);
    
    return 0;
}