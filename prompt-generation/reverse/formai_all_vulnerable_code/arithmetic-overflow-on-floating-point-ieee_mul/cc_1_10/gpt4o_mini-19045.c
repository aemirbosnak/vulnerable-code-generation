//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// WAV file header structure
typedef struct {
    char riff[4];
    uint32_t overall_size;
    char wave[4];
    char fmt[4];
    uint32_t fmt_length;
    uint16_t format_type;
    uint16_t channels;
    uint32_t sample_rate;
    uint32_t byte_rate;
    uint16_t block_align;
    uint16_t bits_per_sample;
    char data[4];
    uint32_t data_size;
} WAVHeader;

// Function to adjust volume
void adjust_volume(uint16_t *samples, uint32_t num_samples, float volume) {
    for (uint32_t i = 0; i < num_samples; i++) {
        int32_t new_sample = (int32_t)(samples[i] * volume);
        if (new_sample > 65535) new_sample = 65535; // Clip if too high
        else if (new_sample < 0) new_sample = 0; // Clip if too low
        samples[i] = (uint16_t)new_sample;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s input.wav output.wav volume_factor\n", argv[0]);
        return 1;
    }

    // Open input WAV file
    FILE *in_file = fopen(argv[1], "rb");
    if (in_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Read the WAV header
    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, in_file);

    if (strncmp(header.riff, "RIFF", 4) != 0 || strncmp(header.wave, "WAVE", 4) != 0) {
        fprintf(stderr, "Not a valid WAV file.\n");
        fclose(in_file);
        return 1;
    }

    // Allocate memory for samples
    uint32_t num_samples = header.data_size / sizeof(uint16_t);
    uint16_t *samples = (uint16_t *)malloc(header.data_size);
    if (samples == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(in_file);
        return 1;
    }

    // Read audio samples
    fseek(in_file, sizeof(WAVHeader), SEEK_SET);
    fread(samples, sizeof(uint16_t), num_samples, in_file);
    fclose(in_file);

    // Get volume factor
    float volume = atof(argv[3]);
    if (volume < 0.0f) {
        fprintf(stderr, "Volume must be non-negative.\n");
        free(samples);
        return 1;
    }

    // Adjust the volume
    adjust_volume(samples, num_samples, volume);

    // Write to output WAV file
    FILE *out_file = fopen(argv[2], "wb");
    if (out_file == NULL) {
        perror("Error opening output file");
        free(samples);
        return 1;
    }

    // Write the WAV header
    fwrite(&header, sizeof(WAVHeader), 1, out_file);

    // Write modified samples
    fwrite(samples, sizeof(uint16_t), num_samples, out_file);

    // Clean up
    fclose(out_file);
    free(samples);

    printf("Processed audio saved to %s with volume factor %f.\n", argv[2], volume);
    return 0;
}