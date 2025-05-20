//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    char chunkId[4];
    uint32_t chunkSize;
    char format[4];
    char subchunk1Id[4];
    uint32_t subchunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    char subchunk2Id[4];
    uint32_t subchunk2Size;
} WAVHeader;

void adjustVolume(int16_t *buffer, size_t length, float volume) {
    for (size_t i = 0; i < length; i++) {
        int32_t sample = (int32_t)(buffer[i] * volume);
        if (sample > INT16_MAX) {
            buffer[i] = INT16_MAX;
        } else if (sample < INT16_MIN) {
            buffer[i] = INT16_MIN;
        } else {
            buffer[i] = (int16_t)sample;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <volume>\n", argv[0]);
        return EXIT_FAILURE;
    }

    float volume = atof(argv[3]);
    if (volume < 0) {
        fprintf(stderr, "Volume must be a positive value.\n");
        return EXIT_FAILURE;
    }

    FILE *inputFile = fopen(argv[1], "rb");
    if (!inputFile) {
        perror("Failed to open input file");
        return EXIT_FAILURE;
    }

    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, inputFile);
    
    if (strncmp(header.chunkId, "RIFF", 4) != 0 || strncmp(header.format, "WAVE", 4) != 0) {
        fprintf(stderr, "Unsupported file format.\n");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    size_t numSamples = header.subchunk2Size / sizeof(int16_t);
    int16_t *buffer = malloc(header.subchunk2Size);
    if (!buffer) {
        perror("Failed to allocate memory for audio data");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    fread(buffer, sizeof(int16_t), numSamples, inputFile);
    fclose(inputFile);

    adjustVolume(buffer, numSamples, volume);

    FILE *outputFile = fopen(argv[2], "wb");
    if (!outputFile) {
        perror("Failed to open output file");
        free(buffer);
        return EXIT_FAILURE;
    }

    fwrite(&header, sizeof(WAVHeader), 1, outputFile);
    fwrite(buffer, sizeof(int16_t), numSamples, outputFile);
    fclose(outputFile);

    free(buffer);
    printf("Successfully adjusted volume and wrote to %s\n", argv[2]);
    
    return EXIT_SUCCESS;
}