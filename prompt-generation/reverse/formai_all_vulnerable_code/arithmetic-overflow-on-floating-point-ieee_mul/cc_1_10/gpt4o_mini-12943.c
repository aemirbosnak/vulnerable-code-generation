//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    char     riff[4];        // RIFF Header
    uint32_t overall_size;   // File size minus 8 bytes
    char     wave[4];        // WAVE Header
    char     fmt[4];         // FMT header
    uint32_t fmt_length;     // Length of format data
    uint16_t format_type;    // Format type
    uint16_t channels;       // Number of channels
    uint32_t sample_rate;    // Sample rate
    uint32_t byte_rate;      // Bytes per second
    uint16_t block_align;    // 2 for 16-bit mono, 4 for 16-bit stereo
    uint16_t bits_per_sample; // Bits per sample
    char     data[4];        // DATA header
    uint32_t data_size;      // Size of data section
} WAVHeader;
#pragma pack(pop)

void change_volume(const char *input_filename, const char *output_filename, float volume_factor) {
    FILE *input_file = fopen(input_filename, "rb");
    if (!input_file) {
        perror("Could not open input file");
        return;
    }

    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, input_file);

    if (strncmp(header.riff, "RIFF", 4) != 0 ||
        strncmp(header.wave, "WAVE", 4) != 0 ||
        strncmp(header.fmt, "fmt ", 4) != 0 ||
        strncmp(header.data, "data", 4) != 0) {
        fprintf(stderr, "Not a valid WAV file.\n");
        fclose(input_file);
        return;
    }

    size_t audio_data_size = header.data_size;
    int16_t *audio_data = malloc(audio_data_size);
    fread(audio_data, audio_data_size, 1, input_file);
    fclose(input_file);

    // Adjust the volume
    for (size_t i = 0; i < audio_data_size / sizeof(int16_t); i++) {
        int32_t temp = (int32_t)(audio_data[i] * volume_factor);
        // Clipping the results to the 16-bit signed int limit
        if (temp > INT16_MAX) {
            audio_data[i] = INT16_MAX;
        } else if (temp < INT16_MIN) {
            audio_data[i] = INT16_MIN;
        } else {
            audio_data[i] = (int16_t)temp;
        }
    }

    FILE *output_file = fopen(output_filename, "wb");
    if (!output_file) {
        perror("Could not open output file");
        free(audio_data);
        return;
    }

    fwrite(&header, sizeof(WAVHeader), 1, output_file);
    fwrite(audio_data, audio_data_size, 1, output_file);
    fclose(output_file);
    free(audio_data);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <volume_factor>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    float volume_factor = atof(argv[3]);

    change_volume(input_filename, output_filename, volume_factor);

    printf("Volume changed successfully. Output saved to %s\n", output_filename);
    return EXIT_SUCCESS;
}