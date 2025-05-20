//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>

#define GAIN_FACTOR 2.0   // Gain factor to amplify the audio
#define BUFFER_SIZE 1024   // Size of audio buffer for processing

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];

    SF_INFO sfinfo;
    SNDFILE *input_sf, *output_sf;
    
    // Open input audio file
    input_sf = sf_open(input_file, SFM_READ, &sfinfo);
    if (!input_sf) {
        fprintf(stderr, "Error opening file %s: %s\n", input_file, sf_strerror(NULL));
        return 1;
    }
    
    // Open output audio file
    output_sf = sf_open(output_file, SFM_WRITE, &sfinfo);
    if (!output_sf) {
        fprintf(stderr, "Error opening file %s: %s\n", output_file, sf_strerror(NULL));
        sf_close(input_sf);
        return 1;
    }

    // Buffer for audio processing
    float buffer[BUFFER_SIZE];
    sf_count_t read_count;

    // Process audio
    while ((read_count = sf_readf_float(input_sf, buffer, BUFFER_SIZE)) > 0) {
        for (sf_count_t i = 0; i < read_count; i++) {
            buffer[i] *= GAIN_FACTOR;  // Apply gain
        }
        sf_writef_float(output_sf, buffer, read_count);
    }

    // Close audio files
    sf_close(input_sf);
    sf_close(output_sf);

    printf("Audio processing complete: %s -> %s\n", input_file, output_file);
    return 0;
}