//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define MAX_FRAMES 1024

void apply_reverb(float *input, float *output, int frames, float reverb_level) {
    float *delay_line = (float *)calloc(MAX_FRAMES, sizeof(float));
    int delay_samples = (int)(0.2 * SAMPLE_RATE); // 200ms delay
    for (int i = 0; i < frames; i++) {
        float input_sample = input[i];
        float delayed_sample = delay_line[(i - delay_samples + MAX_FRAMES) % MAX_FRAMES];
        
        output[i] = input_sample + (delayed_sample * reverb_level);

        // Update delay line
        delay_line[i % MAX_FRAMES] = input_sample + (delayed_sample * 0.5f);
    }
    free(delay_line);
}

void process_audio(const char *input_file, const char *output_file, float reverb_level) {
    SNDFILE *infile, *outfile;
    SF_INFO sfinfo;

    // Open input file
    infile = sf_open(input_file, SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Error opening input file: %s\n", sf_strerror(NULL));
        return;
    }

    // Prepare output file info
    SF_INFO outinfo = sfinfo;
    outfile = sf_open(output_file, SFM_WRITE, &outinfo);
    if (!outfile) {
        fprintf(stderr, "Error opening output file: %s\n", sf_strerror(outfile));
        sf_close(infile);
        return;
    }

    float *input_buffer = (float *)malloc(MAX_FRAMES * sizeof(float));
    float *output_buffer = (float *)malloc(MAX_FRAMES * sizeof(float));

    int frames_read;
    while ((frames_read = sf_readf_float(infile, input_buffer, MAX_FRAMES)) > 0) {
        apply_reverb(input_buffer, output_buffer, frames_read, reverb_level);
        sf_writef_float(outfile, output_buffer, frames_read);
    }

    // Cleaning up
    free(input_buffer);
    free(output_buffer);
    sf_close(infile);
    sf_close(outfile);
    printf("Processing complete! Output saved to %s\n", output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <reverb_level>\n", argv[0]);
        return 1;
    }

    float reverb_level = atof(argv[3]);
    if (reverb_level < 0.0 || reverb_level > 1.0) {
        fprintf(stderr, "Reverb level must be between 0.0 and 1.0\n");
        return 1;
    }

    process_audio(argv[1], argv[2], reverb_level);
    return 0;
}