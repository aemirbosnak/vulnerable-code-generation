//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BUFFER_SIZE 4096

// Structure to hold WAV file header
#pragma pack(push, 1)
typedef struct {
    char riff[4];        // "RIFF"
    uint32_t overall_size; // file size minus 8 bytes for RIFF and size
    char wave[4];       // "WAVE"
    char fmt[4];        // "fmt "
    uint32_t fmt_length; // length of fmt data
    uint16_t format_type; // format type
    uint16_t channels;   // channels: 1=mono, 2=stereo
    uint32_t sample_rate; // sampling frequency
    uint32_t bytes_per_second; // bytes per second
    uint16_t block_size; // number of bytes for one sample including all channels
    uint16_t bits_per_sample; // bits per sample
    char data[4];        // "data"
    uint32_t data_size;  // size of the data
} WavHeader;
#pragma pack(pop)

// Function to modify volume
void adjust_volume(int16_t *buffer, size_t samples, float volume) {
    for (size_t i = 0; i < samples; i++) {
        buffer[i] = (int16_t)(buffer[i] * volume);
        // Clamp the values to the allowed range for int16_t
        if (buffer[i] > INT16_MAX) {
            buffer[i] = INT16_MAX;
        } else if (buffer[i] < INT16_MIN) {
            buffer[i] = INT16_MIN;
        }
    }
}

void process_wav(const char *input_file, const char *output_file, float volume) {
    FILE *input = fopen(input_file, "rb");
    if (!input) {
        perror("Error opening input WAV file");
        exit(EXIT_FAILURE);
    }

    WavHeader header;
    fread(&header, sizeof(WavHeader), 1, input);

    // Check if it's a supported format
    if (strncmp(header.riff, "RIFF", 4) != 0 || strncmp(header.wave, "WAVE", 4) != 0) {
        fclose(input);
        fprintf(stderr, "Not a valid WAV file.\n");
        exit(EXIT_FAILURE);
    }

    // Print original WAV info
    printf("Original WAV Info:\n");
    printf("Channels: %d\n", header.channels);
    printf("Sample Rate: %d Hz\n", header.sample_rate);
    printf("Bits per Sample: %d\n", header.bits_per_sample);
    printf("Data Size: %d bytes\n", header.data_size);

    size_t samples = header.data_size / (header.bits_per_sample / 8);
    int16_t *buffer = malloc(BUFFER_SIZE);
    if (!buffer) {
        fprintf(stderr, "Memory allocation error.\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    // Open output file
    FILE *output = fopen(output_file, "wb");
    if (!output) {
        perror("Error opening output WAV file");
        free(buffer);
        fclose(input);
        exit(EXIT_FAILURE);
    }

    fwrite(&header, sizeof(WavHeader), 1, output);

    // Read, process, and write data
    size_t total_read = 0;
    while (total_read < samples) {
        size_t to_read = (samples - total_read > BUFFER_SIZE / sizeof(int16_t)) ?
                         BUFFER_SIZE / sizeof(int16_t) : (samples - total_read);
        size_t read = fread(buffer, sizeof(int16_t), to_read, input);
        if (read == 0) {
            break; // End of file or error
        }

        // Adjust volume
        adjust_volume(buffer, read, volume);

        // Write processed data to the output file
        fwrite(buffer, sizeof(int16_t), read, output);
        total_read += read;
    }

    // Clean up
    free(buffer);
    fclose(input);
    fclose(output);
    printf("Processed WAV file written to: %s\n", output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <volume_multiplier>\n", argv[0]);
        return EXIT_FAILURE;
    }

    float volume = atof(argv[3]);
    if (volume < 0.0) {
        fprintf(stderr, "Volume multiplier must be non-negative.\n");
        return EXIT_FAILURE;
    }

    process_wav(argv[1], argv[2], volume);
    printf("All done! Happy listening!\n");
    return EXIT_SUCCESS;
}