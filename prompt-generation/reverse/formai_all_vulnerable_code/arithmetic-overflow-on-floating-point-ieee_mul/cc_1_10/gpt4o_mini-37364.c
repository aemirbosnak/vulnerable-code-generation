//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    char riff[4];              // RIFF Header
    uint32_t overall_size;     // Overall size of file in bytes
    char wave[4];              // WAVE Header
    char fmt[4];               // FMT header
    uint32_t fmt_length;       // Length of the format data
    uint16_t format_type;      // Format type: 1 for PCM
    uint16_t channels;         // Number of channels
    uint32_t sample_rate;      // Sampling frequency
    uint32_t byte_rate;        // Bytes per second
    uint16_t block_align;      // 2*(bits_per_sample/8)*channels
    uint16_t bits_per_sample;   // Bits per sample
    char data[4];              // DATA header
    uint32_t data_size;        // Size of the data section
} WAVHeader;

// Function to read WAV file header
void read_wav_header(FILE *file, WAVHeader *header) {
    fread(header, sizeof(WAVHeader), 1, file);
}

// Function to write WAV file header
void write_wav_header(FILE *file, WAVHeader *header) {
    fwrite(header, sizeof(WAVHeader), 1, file);
}

// Function to apply a volume boost
void boost_volume(int16_t *buffer, int size, float boost_factor) {
    for (int i = 0; i < size; i++) {
        int32_t boosted_sample = (int32_t)(buffer[i] * boost_factor);
        buffer[i] = (int16_t)(boosted_sample > INT16_MAX ? INT16_MAX : (boosted_sample < INT16_MIN ? INT16_MIN : boosted_sample));
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <input.wav> <output.wav> <boost_factor>\n", argv[0]);
        return 1;
    }

    float boost_factor = atof(argv[3]);
    if (boost_factor <= 0) {
        printf("Boost factor must be greater than 0.\n");
        return 1;
    }

    // Open input WAV file
    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Error opening input file");
        return 1;
    }

    WAVHeader header;
    read_wav_header(input_file, &header);
    
    // Check if the WAV file is valid
    if (strncmp(header.riff, "RIFF", 4) != 0 || strncmp(header.wave, "WAVE", 4) != 0) {
        printf("Not a valid WAV file.\n");
        fclose(input_file);
        return 1;
    }

    // Buffer to hold audio samples
    int16_t *buffer = malloc(header.data_size);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(input_file);
        return 1;
    }

    // Read audio samples
    fread(buffer, header.data_size, 1, input_file);
    fclose(input_file);

    // Apply volume boost
    boost_volume(buffer, header.data_size / sizeof(int16_t), boost_factor);

    // Open output WAV file
    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        perror("Error opening output file");
        free(buffer);
        return 1;
    }

    // Write modified WAV header and audio samples
    write_wav_header(output_file, &header);
    fwrite(buffer, header.data_size, 1, output_file);

    // Clean up
    fclose(output_file);
    free(buffer);

    printf("Successfully boosted volume and saved to %s!\n", argv[2]);
    
    return 0;
}