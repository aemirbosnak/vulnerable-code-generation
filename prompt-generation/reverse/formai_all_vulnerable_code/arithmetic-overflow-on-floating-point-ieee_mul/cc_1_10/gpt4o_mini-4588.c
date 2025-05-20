//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    char riff[4];        // "RIFF"
    uint32_t overall_size; // File size minus 8 bytes
    char wave[4];       // "WAVE"
    char fmt[4];        // "fmt "
    uint32_t fmt_length; // Format length
    uint16_t format_type; // Format type (1 for PCM)
    uint16_t channels;   // Number of channels
    uint32_t sample_rate; // Sample rate
    uint32_t byte_rate;  // Byte rate
    uint16_t block_align; // Block align
    uint16_t bits_per_sample; // Bits per sample
    char data[4];        // "data"
    uint32_t data_size;  // Size of data
} WavHeader;
#pragma pack(pop)

void apply_volume_scaling(int16_t *data, uint32_t num_samples, float scale) {
    for (uint32_t i = 0; i < num_samples; i++) {
        int32_t sample = data[i] * scale;
        // Clamp to valid PCM range
        if (sample > INT16_MAX) {
            sample = INT16_MAX;
        } else if (sample < INT16_MIN) {
            sample = INT16_MIN;
        }
        data[i] = (int16_t)sample;
    }
}

void process_wav(const char *input_file, const char *output_file, float volume_scale) {
    FILE *in = fopen(input_file, "rb");
    if (!in) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    WavHeader header;
    fread(&header, sizeof(WavHeader), 1, in);

    if (strncmp(header.riff, "RIFF", 4) != 0 || strncmp(header.wave, "WAVE", 4) != 0) {
        fprintf(stderr, "Not a valid WAV file\n");
        fclose(in);
        exit(EXIT_FAILURE);
    }

    uint32_t num_samples = header.data_size / (header.bits_per_sample / 8);
    int16_t *audio_data = malloc(header.data_size);
    if (!audio_data) {
        perror("Memory allocation failed");
        fclose(in);
        exit(EXIT_FAILURE);
    }

    fread(audio_data, header.data_size, 1, in);
    fclose(in);

    apply_volume_scaling(audio_data, num_samples, volume_scale);

    FILE *out = fopen(output_file, "wb");
    if (!out) {
        perror("Error opening output file");
        free(audio_data);
        exit(EXIT_FAILURE);
    }

    fwrite(&header, sizeof(WavHeader), 1, out);
    fwrite(audio_data, header.data_size, 1, out);
    fclose(out);

    free(audio_data);
    printf("Processing complete. Output written to %s\n", output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <volume_scale>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float volume_scale = atof(argv[3]);

    process_wav(input_file, output_file, volume_scale);

    return EXIT_SUCCESS;
}