//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(1) // Ensure no padding occurs in the struct

typedef struct {
    char riff[4];          // RIFF string
    uint32_t overall_size; // overall size of file in bytes
    char wave[4];         // WAVE string
    char fmt[4];          // FMT string
    uint32_t fmt_length;  // length of the format data
    uint16_t format_type; // format type
    uint16_t channels;     // number of channels
    uint32_t sample_rate; // sampling rate
    uint32_t byte_rate;   // bytes per second
    uint16_t block_align; // 2=16-bit mono, 4=16-bit stereo
    uint16_t bits_per_sample; // bits per sample
    char data[4];         // DATA string
    uint32_t data_size;   // size of the data section
} WavHeader;

void apply_gain(int16_t *samples, size_t num_samples, float gain) {
    for (size_t i = 0; i < num_samples; i++) {
        // Apply gain ensuring clipping does not occur
        int32_t sample = (int32_t)(samples[i] * gain);
        if (sample > INT16_MAX) {
            samples[i] = INT16_MAX;
        } else if (sample < INT16_MIN) {
            samples[i] = INT16_MIN;
        } else {
            samples[i] = (int16_t)sample;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input wav> <output wav> <gain>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    float gain = atof(argv[3]);

    FILE *in = fopen(input_file, "rb");
    if (!in) {
        perror("Could not open input file");
        return 1;
    }

    WavHeader header;
    fread(&header, sizeof(WavHeader), 1, in);
    
    // Ensure this is a valid WAV file
    if (memcmp(header.riff, "RIFF", 4) != 0 || memcmp(header.wave, "WAVE", 4) != 0) {
        fprintf(stderr, "Not a valid WAV file.\n");
        fclose(in);
        return 1;
    }

    size_t num_samples = header.data_size / sizeof(int16_t);
    int16_t *samples = (int16_t *)malloc(header.data_size);
    if (!samples) {
        fprintf(stderr, "Failed to allocate memory for samples.\n");
        fclose(in);
        return 1;
    }

    fseek(in, sizeof(WavHeader), SEEK_SET);
    fread(samples, sizeof(int16_t), num_samples, in);
    fclose(in);

    // Apply gain
    apply_gain(samples, num_samples, gain);

    FILE *out = fopen(output_file, "wb");
    if (!out) {
        perror("Could not open output file");
        free(samples);
        return 1;
    }

    fwrite(&header, sizeof(WavHeader), 1, out);
    fwrite(samples, sizeof(int16_t), num_samples, out);
    fclose(out);

    free(samples);
    printf("Processed %zu samples with a gain of %.2f\n", num_samples, gain);
    return 0;
}