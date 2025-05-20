//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>
#include <math.h>

void apply_gain(float *buffer, long frames, float gain) {
    for (long i = 0; i < frames; i++) {
        buffer[i] *= gain;
        // Saturate to ensure the values remain within the [-1, 1] range
        if (buffer[i] > 1.0f) buffer[i] = 1.0f;
        else if (buffer[i] < -1.0f) buffer[i] = -1.0f;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float gain = strtof(argv[3], NULL);

    SF_INFO sfinfo;
    SNDFILE *infile = sf_open(input_file, SFM_READ, &sfinfo);
    if (infile == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", sf_strerror(NULL));
        return EXIT_FAILURE;
    }

    SNDFILE *outfile = sf_open(output_file, SFM_WRITE, &sfinfo);
    if (outfile == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", sf_strerror(NULL));
        sf_close(infile);
        return EXIT_FAILURE;
    }

    // Allocate buffer for reading audio data
    long buffer_size = 1024; // Size of buffer for reading
    float *buffer = (float *) malloc(buffer_size * sfinfo.channels * sizeof(float));
    if (buffer == NULL) {
        fprintf(stderr, "Error allocating memory for audio buffer.\n");
        sf_close(infile);
        sf_close(outfile);
        return EXIT_FAILURE;
    }

    long readcount;
    while ((readcount = sf_readf_float(infile, buffer, buffer_size)) > 0) {
        // Apply gain to the buffer
        apply_gain(buffer, readcount * sfinfo.channels, gain);
        // Write the modified data to output file
        sf_writef_float(outfile, buffer, readcount);
    }

    free(buffer);
    sf_close(infile);
    sf_close(outfile);

    printf("Audio processing completed successfully.\n");
    return EXIT_SUCCESS;
}