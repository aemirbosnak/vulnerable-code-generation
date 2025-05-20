//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

void print_usage() {
    printf("Usage: audio_processor <input_file> <output_file> <volume>\n");
    printf("   <input_file>: Path to the input audio file (WAV format).\n");
    printf("   <output_file>: Path to the output audio file to be created.\n");
    printf("   <volume>: Volume adjustment factor (0.0 to increase or < 0.0 to decrease).\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float volume = atof(argv[3]);

    // Open the input audio file
    SNDFILE *infile;
    SF_INFO sfinfo;
    infile = sf_open(input_file, SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Could not open file %s: %s\n", input_file, sf_strerror(infile));
        return 1;
    }

    // Prepare to write to the output file
    SNDFILE *outfile;
    outfile = sf_open(output_file, SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Could not open file %s: %s\n", output_file, sf_strerror(outfile));
        sf_close(infile);
        return 1;
    }

    // Allocate buffer for audio data
    int num_frames = sfinfo.frames;
    int num_channels = sfinfo.channels;
    float *buffer = malloc(num_frames * num_channels * sizeof(float));
    if (!buffer) {
        fprintf(stderr, "Could not allocate memory for audio buffer.\n");
        sf_close(infile);
        sf_close(outfile);
        return 1;
    }

    // Read audio data into buffer
    sf_count_t read_count = sf_readf_float(infile, buffer, num_frames);
    if (read_count < 0) {
        fprintf(stderr, "Error reading from file %s: %s\n", input_file, sf_strerror(infile));
        free(buffer);
        sf_close(infile);
        sf_close(outfile);
        return 1;
    }

    // Process the audio data (volume adjustment)
    for (int i = 0; i < read_count * num_channels; i++) {
        buffer[i] *= volume; // Adjust volume by the factor provided
    }

    // Write modified audio data to output file
    sf_count_t write_count = sf_writef_float(outfile, buffer, read_count);
    if (write_count < 0) {
        fprintf(stderr, "Error writing to file %s: %s\n", output_file, sf_strerror(outfile));
        free(buffer);
        sf_close(infile);
        sf_close(outfile);
        return 1;
    }

    // Clean up
    free(buffer);
    sf_close(infile);
    sf_close(outfile);

    printf("Processed audio file saved as %s with volume factor: %.2f\n", output_file, volume);
    return 0;
}