//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

#define ECHO_DELAY   0.2   // delay in seconds
#define ECHO_DECAY   0.5   // decay factor for the echo

void apply_echo(float *buffer, sf_count_t frames, int channels) {
    int delay_frames = (int)(ECHO_DELAY * 44100); // assuming 44100 Hz sample rate
    for (sf_count_t i = delay_frames; i < frames; i++) {
        for (int channel = 0; channel < channels; channel++) {
            buffer[i * channels + channel] += buffer[(i - delay_frames) * channels + channel] * ECHO_DECAY;
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav>\n", argv[0]);
        return 1;
    }

    SF_INFO sfinfo;
    SNDFILE *infile = sf_open(argv[1], SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Error reading input file: %s\n", sf_strerror(NULL));
        return 1;
    }

    // Prepare buffer to hold audio data
    sf_count_t frames = sfinfo.frames;
    int channels = sfinfo.channels;
    float *buffer = (float *)malloc(frames * channels * sizeof(float));
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        sf_close(infile);
        return 1;
    }

    // Read the audio data
    sf_count_t read_frames = sf_readf_float(infile, buffer, frames);
    if (read_frames != frames) {
        fprintf(stderr, "Error reading audio data\n");
        free(buffer);
        sf_close(infile);
        return 1;
    }
    sf_close(infile);

    // Apply echo effect
    apply_echo(buffer, frames, channels);

    // Write output
    SNDFILE *outfile = sf_open(argv[2], SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Error opening output file: %s\n", sf_strerror(NULL));
        free(buffer);
        return 1;
    }

    sf_count_t write_frames = sf_writef_float(outfile, buffer, frames);
    if (write_frames != frames) {
        fprintf(stderr, "Error writing audio data\n");
        sf_close(outfile);
        free(buffer);
        return 1;
    }
    sf_close(outfile);
    free(buffer);

    printf("Echo effect applied successfully.\n");
    return 0;
}