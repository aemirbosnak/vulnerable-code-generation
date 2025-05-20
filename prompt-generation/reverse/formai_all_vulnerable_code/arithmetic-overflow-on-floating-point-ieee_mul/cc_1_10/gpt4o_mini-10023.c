//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
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
} WAVHeader;
#pragma pack(pop)

void amplifyAudio(int16_t* buffer, size_t numSamples, float amplificationFactor) {
    for (size_t i = 0; i < numSamples; i++) {
        int32_t amplifiedSample = (int32_t)(buffer[i] * amplificationFactor);
        // Clamp the value to prevent overflow
        if (amplifiedSample > INT16_MAX) {
            buffer[i] = INT16_MAX;
        } else if (amplifiedSample < INT16_MIN) {
            buffer[i] = INT16_MIN;
        } else {
            buffer[i] = (int16_t)amplifiedSample;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <amplification_factor>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* inputFileName = argv[1];
    const char* outputFileName = argv[2];
    float amplificationFactor = atof(argv[3]);

    FILE* inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Failed to open input file");
        return EXIT_FAILURE;
    }

    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, inputFile);

    // Validate WAV header
    if (header.audioFormat != 1) { // Only PCM
        fprintf(stderr, "Unsupported audio format: %u\n", header.audioFormat);
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    size_t numSamples = header.chunkSize / (header.bitsPerSample / 8);
    size_t bufferSize = numSamples * sizeof(int16_t);
    int16_t* buffer = (int16_t*)malloc(bufferSize);
    if (!buffer) {
        perror("Failed to allocate memory for audio buffer");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    fread(buffer, sizeof(int16_t), numSamples, inputFile);
    fclose(inputFile);

    amplifyAudio(buffer, numSamples, amplificationFactor);

    FILE* outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Failed to open output file");
        free(buffer);
        return EXIT_FAILURE;
    }

    fwrite(&header, sizeof(WAVHeader), 1, outputFile);
    fwrite(buffer, sizeof(int16_t), numSamples, outputFile);

    fclose(outputFile);
    free(buffer);
    printf("Audio amplification complete. Output written to %s\n", outputFileName);
    
    return EXIT_SUCCESS;
}