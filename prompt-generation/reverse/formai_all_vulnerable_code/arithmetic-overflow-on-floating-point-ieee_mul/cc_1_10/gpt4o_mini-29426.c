//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    char riff[4];
    uint32_t fileSize;
    char wave[4];
    char fmt[4];
    uint32_t fmtSize;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    char data[4];
    uint32_t dataSize;
} WavHeader;

void process_audio(int16_t *samples, uint32_t numSamples, float amplitudeFactor) {
    for (uint32_t i = 0; i < numSamples; i++) {
        int32_t sample = (int32_t)(samples[i] * amplitudeFactor);
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
        printf("Usage: %s <input.wav> <output.wav> <amplitude_factor>\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "rb");
    if (!inputFile) {
        perror("Error opening input file");
        return 1;
    }

    WavHeader header;
    fread(&header, sizeof(WavHeader), 1, inputFile);
    
    if (strncmp(header.riff, "RIFF", 4) != 0 || strncmp(header.wave, "WAVE", 4) != 0) {
        printf("Error: Not a valid WAV file\n");
        fclose(inputFile);
        return 1;
    }

    if (header.bitsPerSample != 16) {
        printf("Error: This program only supports 16-bit WAV files\n");
        fclose(inputFile);
        return 1;
    }

    uint32_t numSamples = header.dataSize / sizeof(int16_t);
    int16_t *samples = malloc(header.dataSize);
    if (!samples) {
        perror("Error allocating memory for samples");
        fclose(inputFile);
        return 1;
    }

    fseek(inputFile, sizeof(WavHeader), SEEK_SET);
    fread(samples, sizeof(int16_t), numSamples, inputFile);
    fclose(inputFile);

    float amplitudeFactor = atof(argv[3]);
    process_audio(samples, numSamples, amplitudeFactor);

    FILE *outputFile = fopen(argv[2], "wb");
    if (!outputFile) {
        perror("Error opening output file");
        free(samples);
        return 1;
    }

    fwrite(&header, sizeof(WavHeader), 1, outputFile);
    fwrite(samples, sizeof(int16_t), numSamples, outputFile);
    fclose(outputFile);
    free(samples);

    printf("Audio processing complete. New file saved as %s\n", argv[2]);
    return 0;
}