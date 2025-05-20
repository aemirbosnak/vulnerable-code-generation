//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

#define BUFFER_SIZE 1024

void apply_gain(short *buffer, int frames, float gain) {
    for (int i = 0; i < frames; i++) {
        int sample = buffer[i] * gain;

        // Clamp the samples to avoid overflow
        if (sample > 32767) {
            buffer[i] = 32767;
        } else if (sample < -32768) {
            buffer[i] = -32768;
        } else {
            buffer[i] = sample;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float gain = atof(argv[3]);

    // Open the input WAV file
    SF_INFO sfinfo;
    SNDFILE *in_file = sf_open(input_file, SFM_READ, &sfinfo);
    if (!in_file) {
        fprintf(stderr, "Error opening input file: %s\n", sf_strerror(NULL));
        return 1;
    }

    // Check if the file is mono
    if (sfinfo.channels != 1) {
        fprintf(stderr, "Input file must be mono.\n");
        sf_close(in_file);
        return 1;
    }

    // Open the output WAV file
    SNDFILE *out_file = sf_open(output_file, SFM_WRITE, &sfinfo);
    if (!out_file) {
        fprintf(stderr, "Error opening output file: %s\n", sf_strerror(NULL));
        sf_close(in_file);
        return 1;
    }

    // Process audio data
    short buffer[BUFFER_SIZE];
    int readcount;
    while ((readcount = sf_readf_short(in_file, buffer, BUFFER_SIZE)) > 0) {
        apply_gain(buffer, readcount, gain);
        sf_writef_short(out_file, buffer, readcount);
    }

    // Cleanup
    sf_close(in_file);
    sf_close(out_file);

    printf("Processed %s with gain %.2f to %s\n", input_file, gain, output_file);
    return 0;
}