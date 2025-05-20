//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sndfile.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

void apply_reverb(float *input, float *output, int size, float decay) {
    for (int i = 0; i < size; i++) {
        output[i] = input[i];
        if (i > 22050) { // 0.5 seconds delay
            output[i] += decay * output[i - 22050];
        }
    }
}

void apply_distortion(float *input, float *output, int size, float gain) {
    for (int i = 0; i < size; i++) {
        output[i] = gain * input[i];
        if (output[i] > 1.0f) output[i] = 1.0f;
        if (output[i] < -1.0f) output[i] = -1.0f;
    }
}

void process_audio(const char *input_file, const char *output_file, float reverb_decay, float distortion_gain) {
    SNDFILE *in_file, *out_file;
    SF_INFO sfinfo;
    float buffer[BUFFER_SIZE];
    float processed_buffer[BUFFER_SIZE];

    // Open the input file
    in_file = sf_open(input_file, SFM_READ, &sfinfo);
    if (!in_file) {
        fprintf(stderr, "Error: could not open input file %s\n", input_file);
        return;
    }

    // Prepare the output file
    out_file = sf_open(output_file, SFM_WRITE, &sfinfo);
    if (!out_file) {
        fprintf(stderr, "Error: could not open output file %s\n", output_file);
        sf_close(in_file);
        return;
    }

    // Process the audio
    while (1) {
        int read_count = sf_readf_float(in_file, buffer, BUFFER_SIZE);
        if (read_count == 0) break;

        // Apply effects
        apply_reverb(buffer, processed_buffer, read_count, reverb_decay);
        apply_distortion(processed_buffer, buffer, read_count, distortion_gain);

        // Write processed audio to the output file
        sf_writef_float(out_file, buffer, read_count);
    }

    // Close files
    sf_close(in_file);
    sf_close(out_file);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <reverb_decay> <distortion_gain>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float reverb_decay = atof(argv[3]);
    float distortion_gain = atof(argv[4]);

    process_audio(input_file, output_file, reverb_decay, distortion_gain);
    
    printf("Audio processing complete. Output saved to %s\n", output_file);
    return 0;
}