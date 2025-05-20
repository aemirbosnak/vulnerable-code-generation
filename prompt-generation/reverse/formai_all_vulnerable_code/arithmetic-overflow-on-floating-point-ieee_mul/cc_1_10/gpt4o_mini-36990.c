//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    char riff[4];           // RIFF
    uint32_t overall_size;  // file size - 8
    char wave[4];          // WAVE
    char fmt[4];           // fmt
    uint32_t fmt_length;   // length of format data
    uint16_t format_type;   // format type
    uint16_t channels;      // number of channels
    uint32_t sample_rate;   // sampling frequency
    uint32_t byte_rate;     // bytes per second
    uint16_t block_align;   // data block size
    uint16_t bits_per_sample; // bits per sample
    char data[4];           // DATA
    uint32_t data_size;     // size of the data section
} WavHeader;

void amplify_audio(const char *input_file, const char *output_file, float factor) {
    FILE *infile = fopen(input_file, "rb");
    if (!infile) {
        perror("Cannot open input file");
        return;
    }

    WavHeader header;
    fread(&header, sizeof(WavHeader), 1, infile);

    // Check for WAVE format
    if (strncmp(header.riff, "RIFF", 4) != 0 || strncmp(header.wave, "WAVE", 4) != 0) {
        fprintf(stderr, "Not a valid WAVE file.\n");
        fclose(infile);
        return;
    }

    // Create output file
    FILE *outfile = fopen(output_file, "wb");
    if (!outfile) {
        perror("Cannot create output file");
        fclose(infile);
        return;
    }

    // Write header to output file
    fwrite(&header, sizeof(WavHeader), 1, outfile);

    // Allocate buffer for audio data
    int16_t *buffer = (int16_t *)malloc(header.data_size);
    if (!buffer) {
        perror("Unable to allocate memory for audio data");
        fclose(infile);
        fclose(outfile);
        return;
    }

    // Read audio data
    fread(buffer, header.data_size, 1, infile);

    // Process audio data: amplify
    for (uint32_t i = 0; i < header.data_size / sizeof(int16_t); i++) {
        float amplified_value = buffer[i] * factor;
        if (amplified_value > INT16_MAX) {
            buffer[i] = INT16_MAX;
        } else if (amplified_value < INT16_MIN) {
            buffer[i] = INT16_MIN;
        } else {
            buffer[i] = (int16_t)amplified_value;
        }
    }

    // Write audio data to output file
    fwrite(buffer, header.data_size, 1, outfile);

    // Cleanup
    free(buffer);
    fclose(infile);
    fclose(outfile);

    printf("Audio processing complete. Output saved to %s\n", output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <amplification_factor>\n", argv[0]);
        return EXIT_FAILURE;
    }

    float amplification_factor = atof(argv[3]);
    if (amplification_factor <= 0) {
        fprintf(stderr, "Amplification factor must be greater than 0.\n");
        return EXIT_FAILURE;
    }

    amplify_audio(argv[1], argv[2], amplification_factor);

    return EXIT_SUCCESS;
}
#pragma pack(pop)