//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

void process_audio(const char *input_file, const char *output_file, float amplification) {
    SF_INFO sfinfo;
    SNDFILE *infile, *outfile;

    // Open input file
    infile = sf_open(input_file, SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Could not open input file: %s\n", sf_strerror(NULL));
        return;
    }
    
    // Create output file
    outfile = sf_open(output_file, SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Could not open output file: %s\n", sf_strerror(infile));
        sf_close(infile);
        return;
    }
    
    // Allocate buffer based on the channels and frames
    size_t buffer_size = 1024;
    float *buffer = (float *)malloc(buffer_size * sizeof(float));
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed for buffer\n");
        sf_close(infile);
        sf_close(outfile);
        return;
    }
    
    // Read and process the audio
    sf_count_t read_count;
    while ((read_count = sf_readf_float(infile, buffer, buffer_size))) {
        // Amplify the audio by multiplying each sample
        for (sf_count_t i = 0; i < read_count * sfinfo.channels; i++) {
            buffer[i] *= amplification;
        }
        // Write the processed audio to the output file
        sf_writef_float(outfile, buffer, read_count);
    }
    
    // Clean up
    free(buffer);
    sf_close(infile);
    sf_close(outfile);
    
    printf("🎉 Audio processing completed! Enjoy your amplified sound! 🎉\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <amplification_factor>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float amplification = atof(argv[3]);

    if (amplification <= 0) {
        fprintf(stderr, "Amplification factor must be greater than 0!\n");
        return 1;
    }

    printf("✨ Welcome to the Audio Amplifier! ✨\n");
    printf("Input File: %s\n", input_file);
    printf("Output File: %s\n", output_file);
    printf("Amplification Factor: %.2f\n", amplification);
    
    process_audio(input_file, output_file, amplification);
    
    return 0;
}