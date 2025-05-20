//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint8_t riff[4];            // RIFF Header
    uint32_t overall_size;      // Overall size of audio file in bytes
    uint8_t wave[4];            // WAVE Header
    uint8_t fmt[4];             // FMT Header
    uint32_t fmt_length;        // Length of the fmt data
    uint16_t format_type;       // Format type
    uint16_t channels;          // Number of channels
    uint32_t samples_per_sec;   // Sampling Frequency in Hz
    uint32_t bytes_per_sec;     // bytes per second
    uint16_t block_align;       // 2=16-bit mono, 4=16-bit stereo
    uint16_t bits_per_sample;   // Number of bits per sample
    uint8_t data[4];            // DATA Header
    uint32_t data_size;         // Size of the data section
} WavHeader;
#pragma pack(pop)

void print_usage() {
    printf("Usage: volume_adjuster <input.wav> <output.wav> <volume_factor>\n");
}

int32_t adjust_volume(int32_t sample, float factor) {
    int32_t adjusted_sample = (int32_t)(sample * factor);
    if (adjusted_sample > 32767) {
        return 32767;
    } else if (adjusted_sample < -32768) {
        return -32768;
    }
    return adjusted_sample;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Could not open input file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        perror("Could not open output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    float volume_factor = atof(argv[3]);
    
    WavHeader header;
    fread(&header, sizeof(WavHeader), 1, input_file);
    
    if (header.bits_per_sample != 16 || header.channels != 1) {
        fprintf(stderr, "This program supports only 16-bit mono WAV files.\n");
        fclose(input_file);
        fclose(output_file);
        return EXIT_FAILURE;
    }

    fwrite(&header, sizeof(WavHeader), 1, output_file);
    
    int16_t sample;
    int32_t sample_count = header.data_size / sizeof(int16_t);

    for (int32_t i = 0; i < sample_count; i++) {
        fread(&sample, sizeof(int16_t), 1, input_file);
        sample = adjust_volume(sample, volume_factor);
        fwrite(&sample, sizeof(int16_t), 1, output_file);
    }

    fclose(input_file);
    fclose(output_file);
    printf("Volume adjustment completed. New file: %s\n", argv[2]);
    return EXIT_SUCCESS;
}