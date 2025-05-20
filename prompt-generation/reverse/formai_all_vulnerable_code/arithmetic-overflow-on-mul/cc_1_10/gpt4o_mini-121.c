//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sndfile.h>

// Function to apply a simple gain effect to audio samples
void apply_gain(float *samples, long num_samples, float gain) {
    for (long i = 0; i < num_samples; i++) {
        samples[i] *= gain;
    }
}

// Function to create a delay effect
void apply_delay(float *samples, long num_samples, float delay_time, float feedback) {
    int delay_samples = (int)(delay_time * 44100); // Assuming a sample rate of 44100 Hz
    float *delay_buffer = (float *)calloc(delay_samples, sizeof(float));
    for (long i = 0; i < num_samples; i++) {
        float delayed_sample = (i >= delay_samples) ? delay_buffer[i % delay_samples] : 0.0f;
        delay_buffer[i % delay_samples] = samples[i] + (delayed_sample * feedback);
        samples[i] += delayed_sample;
    }
    free(delay_buffer);
}

// Function to write the processed samples to a new audio file
void write_audio(const char *filename, float *samples, long num_samples, SF_INFO *sfinfo) {
    SNDFILE *outfile = sf_open(filename, SFM_WRITE, sfinfo);
    if (!outfile) {
        printf("Error opening output file %s: %s\n", filename, sf_strerror(NULL));
        exit(1);
    }
    sf_write_float(outfile, samples, num_samples);
    sf_close(outfile);
}

// Main function to read, process, and write audio
int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <input_file> <output_file> <gain> <delay_time> <feedback>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float gain = atof(argv[3]);
    float delay_time = atof(argv[4]);
    float feedback = atof(argv[5]);
    
    SF_INFO sfinfo;
    SNDFILE *infile = sf_open(input_file, SFM_READ, &sfinfo);
    if (!infile) {
        printf("Error opening input file %s: %s\n", input_file, sf_strerror(NULL));
        return 1;
    }

    long num_samples = sfinfo.frames * sfinfo.channels;
    float *samples = (float *)malloc(num_samples * sizeof(float));
    sf_read_float(infile, samples, num_samples);
    sf_close(infile);

    // Apply gain
    apply_gain(samples, num_samples, gain);
    
    // Apply delay
    apply_delay(samples, num_samples, delay_time, feedback);

    // Write processed samples to output file
    write_audio(output_file, samples, num_samples, &sfinfo);

    free(samples);
    printf("Processed audio written to %s\n", output_file);
    return 0;
}