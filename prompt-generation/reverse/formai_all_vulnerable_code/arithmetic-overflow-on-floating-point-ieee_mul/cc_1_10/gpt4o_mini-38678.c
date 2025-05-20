//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

#define MAX_BUFFER_SIZE 1024

void handle_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

void process_audio(const char *input_file, const char *output_file, double gain) {
    SF_INFO sfinfo;
    SNDFILE *infile, *outfile;

    infile = sf_open(input_file, SFM_READ, &sfinfo);
    if (!infile) {
        handle_error("Could not open input file");
    }

    outfile = sf_open(output_file, SFM_WRITE, &sfinfo);
    if (!outfile) {
        sf_close(infile);
        handle_error("Could not open output file");
    }

    float buffer[MAX_BUFFER_SIZE];
    sf_count_t num_read;
    
    while ((num_read = sf_readf_float(infile, buffer, MAX_BUFFER_SIZE)) > 0) {
        for (sf_count_t i = 0; i < num_read; i++) {
            buffer[i] *= gain;  // Apply gain to the audio signal
        }
        sf_writef_float(outfile, buffer, num_read);
    }

    sf_close(infile);
    sf_close(outfile);

    printf("Audio processed successfully: %s -> %s with gain %.2f\n", input_file, output_file, gain);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <gain>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    double gain = atof(argv[3]);

    if (gain < 0) {
        handle_error("Gain must be a non-negative value");
    }

    process_audio(input_file, output_file, gain);
    return EXIT_SUCCESS;
}