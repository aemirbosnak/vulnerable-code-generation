//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    char riff[4];        // RIFF Header
    uint32_t fileSize;   // File size
    char wave[4];        // WAVE Header
    char fmt[4];         // FMT header
    uint32_t fmtSize;    // Format size
    uint16_t audioFormat; // Audio format
    uint16_t numChannels; // Number of channels
    uint32_t sampleRate;  // Sampling frequency
    uint32_t byteRate;    // Bytes per second
    uint16_t blockAlign;  // Block alignment
    uint16_t bitsPerSample; // Bits per sample
    char data[4];         // DATA header
    uint32_t dataSize;    // Size of the data
} WAVHeader;

void processAudio(const char *inputFile, const char *outputFile, float volumeFactor) {
    FILE *input = fopen(inputFile, "rb");
    if (!input) {
        printf("Could not open input file %s\n", inputFile);
        return;
    }

    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, input);

    // Check if the file is a valid WAV file
    if (strncmp(header.riff, "RIFF", 4) != 0 ||
        strncmp(header.wave, "WAVE", 4) != 0) {
        printf("Not a valid WAV file.\n");
        fclose(input);
        return;
    }

    // Open output file
    FILE *output = fopen(outputFile, "wb");
    if (!output) {
        printf("Could not open output file %s\n", outputFile);
        fclose(input);
        return;
    }

    // Write the header to the output file
    fwrite(&header, sizeof(WAVHeader), 1, output);

    // Determine the size of each sample
    int16_t *buffer = malloc(header.dataSize);
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        fclose(input);
        fclose(output);
        return;
    }

    // Read audio data
    fread(buffer, header.dataSize, 1, input);

    // Process audio samples
    for (uint32_t i = 0; i < header.dataSize / sizeof(int16_t); i++) {
        // Apply volume factor
        int32_t sample = (int32_t)(buffer[i] * volumeFactor);
        if (sample > INT16_MAX) sample = INT16_MAX;
        if (sample < INT16_MIN) sample = INT16_MIN;
        buffer[i] = (int16_t)sample;
    }

    // Write processed data to output file
    fwrite(buffer, header.dataSize, 1, output);

    // Free allocated memory and close files
    free(buffer);
    fclose(input);
    fclose(output);

    printf("Processed audio and saved to %s\n", outputFile);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input.wav> <output.wav> <volume_factor>\n", argv[0]);
        return 1;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    float volumeFactor = atof(argv[3]);

    if (volumeFactor < 0) {
        printf("Volume factor must be non-negative.\n");
        return 1;
    }

    processAudio(inputFile, outputFile, volumeFactor);

    return 0;
}