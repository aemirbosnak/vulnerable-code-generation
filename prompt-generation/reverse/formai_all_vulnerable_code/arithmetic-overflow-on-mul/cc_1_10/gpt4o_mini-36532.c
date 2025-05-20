//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

void normalize_volume(double* buffer, size_t frames, size_t channels) {
    double max_amplitude = 0.0;

    // Find the maximum sample amplitude in the buffer
    for (size_t i = 0; i < frames * channels; i++) {
        if (fabs(buffer[i]) > max_amplitude) {
            max_amplitude = fabs(buffer[i]);
        }
    }

    // Normalize the audio samples
    if (max_amplitude > 0.0) {
        double normalization_factor = 1.0 / max_amplitude;
        for (size_t i = 0; i < frames * channels; i++) {
            buffer[i] *= normalization_factor;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav>\n", argv[0]);
        return EXIT_FAILURE;
    }

    SNDFILE* infile;
    SNDFILE* outfile;
    SF_INFO sfinfo;
    sf_count_t num_frames;

    // Open the input WAV file
    infile = sf_open(argv[1], SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Error opening input file: %s\n", sf_strerror(NULL));
        return EXIT_FAILURE;
    }

    // Create the output WAV file
    outfile = sf_open(argv[2], SFM_WRITE, &sfinfo);
    if (!outfile) {
        sf_close(infile);
        fprintf(stderr, "Error creating output file: %s\n", sf_strerror(NULL));
        return EXIT_FAILURE;
    }

    // Allocate memory for audio data
    size_t num_samples = sfinfo.frames * sfinfo.channels;
    double* buffer = (double*)malloc(num_samples * sizeof(double));
    if (!buffer) {
        sf_close(infile);
        sf_close(outfile);
        fprintf(stderr, "Memory allocation error.\n");
        return EXIT_FAILURE;
    }

    // Read the audio data from the input file
    num_frames = sf_readf_double(infile, buffer, sfinfo.frames);
    if (num_frames < 0) {
        free(buffer);
        sf_close(infile);
        sf_close(outfile);
        fprintf(stderr, "Error reading audio data: %s\n", sf_strerror(infile));
        return EXIT_FAILURE;
    }

    // Normalize the audio volume
    normalize_volume(buffer, (size_t)num_frames, sfinfo.channels);

    // Write the processed audio data to the output file
    sf_count_t written_frames = sf_writef_double(outfile, buffer, num_frames);
    if (written_frames < 0) {
        free(buffer);
        sf_close(infile);
        sf_close(outfile);
        fprintf(stderr, "Error writing audio data: %s\n", sf_strerror(outfile));
        return EXIT_FAILURE;
    }

    // Clean up and close files
    free(buffer);
    sf_close(infile);
    sf_close(outfile);

    printf("Audio normalization completed successfully.\n");
    return EXIT_SUCCESS;
}