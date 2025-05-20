//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(1) // Ensuring no padding is added

// WAV header structure
typedef struct {
    char chunkID[4];
    uint32_t chunkSize;
    char format[4];
    char subchunk1ID[4];
    uint32_t subchunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    char subchunk2ID[4];
    uint32_t subchunk2Size;
} WaveHeader;

// Function to apply a volume boost
void apply_volume_boost(int16_t *buffer, size_t num_samples, float boost_factor) {
    for (size_t i = 0; i < num_samples; i++) {
        int32_t temp = (int32_t)(buffer[i] * boost_factor);
        if (temp > INT16_MAX) temp = INT16_MAX; // Clipping
        if (temp < INT16_MIN) temp = INT16_MIN; // Clipping
        buffer[i] = (int16_t)temp;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <boost_factor>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Failed to open input file");
        return EXIT_FAILURE;
    }
    
    float boost_factor = atof(argv[3]);
    if (boost_factor <= 0) {
        fprintf(stderr, "Boost factor must be greater than 0\n");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    // Read the header
    WaveHeader header;
    fread(&header, sizeof(WaveHeader), 1, input_file);

    // Ensure the file is a PCM WAV file
    if (strncmp(header.chunkID, "RIFF", 4) != 0 || strncmp(header.format, "WAVE", 4) != 0 || header.audioFormat != 1) {
        fprintf(stderr, "Unsupported file format!\n");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    size_t num_samples = header.subchunk2Size / sizeof(int16_t);
    int16_t *buffer = malloc(header.subchunk2Size);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    // Read the audio data
    fread(buffer, sizeof(int16_t), num_samples, input_file);
    fclose(input_file);
    
    // Apply the volume boost
    apply_volume_boost(buffer, num_samples, boost_factor);

    // Create the output file
    FILE *output_file = fopen(argv[2], "wb");
    if (!output_file) {
        perror("Failed to open output file");
        free(buffer);
        return EXIT_FAILURE;
    }

    // Write the header back
    fwrite(&header, sizeof(WaveHeader), 1, output_file);
    // Write the modified audio data
    fwrite(buffer, sizeof(int16_t), num_samples, output_file);

    // Clean up
    fclose(output_file);
    free(buffer);

    printf("Volume boost applied successfully! Check the output file: %s\n", argv[2]);
    return EXIT_SUCCESS;
}