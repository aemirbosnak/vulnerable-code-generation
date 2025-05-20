//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BUFFER_SIZE 4096

// WAV header structure
typedef struct {
    char riff[4];        // RIFF
    uint32_t overall_size; // overall size of file in bytes
    char wave[4];        // WAVE
    char fmt[4];         // fmt
    uint32_t chunk_size; // size of this chunk (16 for PCM)
    uint16_t format_type; // format type (1 for PCM)
    uint16_t channels;    // number of channels
    uint32_t sample_rate; // sampling rate (blocks per second)
    uint32_t byterate;    // SampleRate * NumChannels * BitsPerSample/8
    uint16_t block_align; // NumChannels * BitsPerSample/8
    uint16_t bits_per_sample; // bits per sample (ex: 16 bits)
    char data[4];         // "data" string
    uint32_t data_size;   // Sampled data size
} WavHeader;

// Function to adjust volume
void adjust_volume(int16_t* buffer, size_t num_samples, float volume) {
    for (size_t i = 0; i < num_samples; i++) {
        int32_t sample = (int32_t)(buffer[i] * volume);
        // Clipping the values to be within int16_t range
        if (sample > INT16_MAX) {
            buffer[i] = INT16_MAX;
        } else if (sample < INT16_MIN) {
            buffer[i] = INT16_MIN;
        } else {
            buffer[i] = (int16_t)sample;
        }
    }
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <volume_factor>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE* input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE* output_file = fopen(argv[2], "wb");
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    float volume = atof(argv[3]);
    if (volume < 0.0f) {
        fprintf(stderr, "Volume factor must be non-negative\n");
        fclose(input_file);
        fclose(output_file);
        return EXIT_FAILURE;
    }

    WavHeader header;
    fread(&header, sizeof(WavHeader), 1, input_file);
    if (strncmp(header.riff, "RIFF", 4) != 0 || strncmp(header.wave, "WAVE", 4) != 0) {
        fprintf(stderr, "Error: Not a valid WAV file.\n");
        fclose(input_file);
        fclose(output_file);
        return EXIT_FAILURE;
    }

    fwrite(&header, sizeof(WavHeader), 1, output_file);

    size_t num_samples = header.data_size / sizeof(int16_t);
    int16_t* buffer = (int16_t*)malloc(num_samples * sizeof(int16_t));
    if (!buffer) {
        fprintf(stderr, "Memory allocation error\n");
        fclose(input_file);
        fclose(output_file);
        return EXIT_FAILURE;
    }

    fread(buffer, sizeof(int16_t), num_samples, input_file);
    adjust_volume(buffer, num_samples, volume);
    fwrite(buffer, sizeof(int16_t), num_samples, output_file);

    free(buffer);
    fclose(input_file);
    fclose(output_file);

    printf("Volume adjustment complete. Output saved to %s\n", argv[2]);

    return EXIT_SUCCESS;
}