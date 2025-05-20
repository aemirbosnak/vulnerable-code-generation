//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

void fade_in(float *buffer, sf_count_t frames, float fade_duration, float sample_rate) {
    size_t fade_samples = (size_t)(fade_duration * sample_rate);
    if (fade_samples > frames) {
        fade_samples = frames;
    }

    for (size_t i = 0; i < fade_samples; i++) {
        float fade_factor = (float)i / (float)fade_samples;
        buffer[i] *= fade_factor;
    }
}

void process_audio(const char *input_file, const char *output_file, float fade_duration) {
    SF_INFO sfinfo;
    SNDFILE *infile = sf_open(input_file, SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Failed to open input file: %s\n", sf_strerror(NULL));
        return;
    }

    // Allocate buffer for reading and processing
    float *buffer = (float *)malloc(sfinfo.frames * sfinfo.channels * sizeof(float));
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        sf_close(infile);
        return;
    }

    // Read the entire audio file into the buffer
    sf_count_t read_count = sf_readf_float(infile, buffer, sfinfo.frames);
    if (read_count < 0) {
        fprintf(stderr, "Error reading audio file: %s\n", sf_strerror(infile));
    }

    // Apply fade in effect
    fade_in(buffer, read_count, fade_duration, sfinfo.samplerate);

    // Create output file
    SNDFILE *outfile = sf_open(output_file, SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Failed to open output file: %s\n", sf_strerror(NULL));
        free(buffer);
        sf_close(infile);
        return;
    }

    // Write processed audio to the output file
    sf_count_t write_count = sf_writef_float(outfile, buffer, read_count);
    if (write_count < 0) {
        fprintf(stderr, "Error writing audio file: %s\n", sf_strerror(outfile));
    }

    // Cleanup
    sf_close(infile);
    sf_close(outfile);
    free(buffer);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <fade_duration_in_seconds>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float fade_duration = atof(argv[3]);

    if (fade_duration < 0) {
        fprintf(stderr, "Fade duration must be non-negative.\n");
        return 1;
    }

    // Process the audio with a peaceful intention
    process_audio(input_file, output_file, fade_duration);
    printf("Processing completed gracefully. Enjoy the sounds of your audio journey!\n");

    return 0;
}