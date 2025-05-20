//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// WAV file header structure
#pragma pack(push, 1)
typedef struct {
    char riff[4];           // "RIFF"
    uint32_t overall_size;  // File size - 8
    char wave[4];          // "WAVE"
    char fmt[4];           // "fmt "
    uint32_t fmt_length;   // Format length (usually 16 for PCM)
    uint16_t format_type;   // Format type (1 for PCM)
    uint16_t channels;      // Number of channels
    uint32_t sample_rate;   // Sampling rate
    uint32_t byte_rate;     // (Sample Rate * Block Align)
    uint16_t block_align;   // Number of bytes per sample (data)
    uint16_t bits_per_sample; // Bits per sample
    char data[4];           // "data"
    uint32_t data_size;     // Size of the data section
} WAVHeader;
#pragma pack(pop)

// Function to process audio by applying a volume boost
void apply_volume_boost(int16_t *buffer, size_t num_samples, float boost_factor) {
    for (size_t i = 0; i < num_samples; i++) {
        int32_t temp = (int32_t)(buffer[i] * boost_factor);
        // Clamp to avoid overflow/underflow
        if (temp > INT16_MAX) {
            buffer[i] = INT16_MAX;
        } else if (temp < INT16_MIN) {
            buffer[i] = INT16_MIN;
        } else {
            buffer[i] = (int16_t)temp;
        }
    }
}

// Function to read a WAV file and return header and audio data
int read_wav(const char *filename, WAVHeader *header, int16_t **buffer, size_t *num_samples) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return -1;
    }

    fread(header, sizeof(WAVHeader), 1, file);

    // Check if this is a PCM format WAV
    if (header->format_type != 1) {
        fprintf(stderr, "Unsupported WAV format\n");
        fclose(file);
        return -1;
    }

    *num_samples = header->data_size / sizeof(int16_t);
    *buffer = malloc(header->data_size);
    if (*buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return -1;
    }

    fread(*buffer, sizeof(int16_t), *num_samples, file);
    fclose(file);
    return 0;
}

// Function to write a WAV file
int write_wav(const char *filename, const WAVHeader *header, const int16_t *buffer) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file");
        return -1;
    }

    fwrite(header, sizeof(WAVHeader), 1, file);
    fwrite(buffer, sizeof(int16_t), header->data_size / sizeof(int16_t), file);
    fclose(file);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <volume_boost_factor>\n", argv[0]);
        return -1;
    }

    WAVHeader header;
    int16_t *buffer;
    size_t num_samples;
    float boost_factor = atof(argv[3]);

    if (read_wav(argv[1], &header, &buffer, &num_samples) != 0) {
        return -1;
    }

    apply_volume_boost(buffer, num_samples, boost_factor);

    if (write_wav(argv[2], &header, buffer) != 0) {
        free(buffer);
        return -1;
    }

    free(buffer);
    printf("Audio processing completed. Output saved to %s\n", argv[2]);
    return 0;
}