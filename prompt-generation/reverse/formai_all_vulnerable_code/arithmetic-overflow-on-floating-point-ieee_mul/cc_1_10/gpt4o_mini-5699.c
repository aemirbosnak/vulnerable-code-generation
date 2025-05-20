//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

void apply_gain(float *buffer, size_t frames, float gain) {
    for (size_t i = 0; i < frames; i++) {
        buffer[i] *= gain;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input-file> <output-file> <gain>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float gain = atof(argv[3]);

    SF_INFO sfinfo;
    SNDFILE *infile, *outfile;

    infile = sf_open(input_file, SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Failed to open input file: %s\n", sf_strerror(NULL));
        return 1;
    }

    outfile = sf_open(output_file, SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Failed to open output file: %s\n", sf_strerror(NULL));
        sf_close(infile);
        return 1;
    }

    size_t buffer_size = 1024;
    float *buffer = malloc(buffer_size * sfinfo.channels * sizeof(float));
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        sf_close(infile);
        sf_close(outfile);
        return 1;
    }

    while (1) {
        sf_count_t readcount = sf_readf_float(infile, buffer, buffer_size);
        if (readcount == 0) break;
        
        apply_gain(buffer, readcount * sfinfo.channels, gain);
        sf_writef_float(outfile, buffer, readcount);
    }

    free(buffer);
    sf_close(infile);
    sf_close(outfile);
    
    printf("Processed '%s' with gain of %.2f, saved to '%s'\n", input_file, gain, output_file);
    
    return 0;
}