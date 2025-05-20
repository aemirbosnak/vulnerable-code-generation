//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    char riff[4];        // RIFF Header
    uint32_t size;      // file size
    char wave[4];       // WAVE Header
    char fmt[4];        // FMT header
    uint32_t fmtSize;   // size of format chunk
    uint16_t formatType; // format type
    uint16_t channels;   // number of channels
    uint32_t samplesPerSec; // sample rate
    uint32_t avgBytesPerSec; // bytes per second
    uint16_t blockAlign; // block alignment
    uint16_t bitsPerSample; // bits per sample
    char data[4];       // DATA header
    uint32_t dataSize;  // size of data
} WAVHeader;
#pragma pack(pop)

void process_audio(int16_t *samples, uint32_t numSamples, float gain) {
    for (uint32_t i = 0; i < numSamples; i++) {
        samples[i] = (int16_t)(samples[i] * gain);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        return 1;
    }

    float gain = atof(argv[3]);
    if (gain < 0) {
        printf("Gain must be a non-negative value.\n");
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "rb");
    if (!inputFile) {
        perror("Error opening input file");
        return 1;
    }

    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, inputFile);
    
    if (strncmp(header.riff, "RIFF", 4) != 0 || strncmp(header.wave, "WAVE", 4) != 0) {
        printf("Not a valid WAV file.\n");
        fclose(inputFile);
        return 1;
    }

    // Calculate number of samples based on data size and bits per sample
    uint32_t numSamples = header.dataSize / sizeof(int16_t);
    int16_t *samples = (int16_t *)malloc(header.dataSize);
    if (!samples) {
        perror("Memory allocation error");
        fclose(inputFile);
        return 1;
    }

    fseek(inputFile, sizeof(WAVHeader), SEEK_SET);
    fread(samples, sizeof(int16_t), numSamples, inputFile);
    fclose(inputFile);

    // Process audio samples
    process_audio(samples, numSamples, gain);

    // Write the output WAV file
    FILE *outputFile = fopen(argv[2], "wb");
    if (!outputFile) {
        perror("Error opening output file");
        free(samples);
        return 1;
    }

    fwrite(&header, sizeof(WAVHeader), 1, outputFile);
    fwrite(samples, sizeof(int16_t), numSamples, outputFile);
    fclose(outputFile);
    free(samples);

    printf("Processing completed! Output written to %s\n", argv[2]);
    return 0;
}