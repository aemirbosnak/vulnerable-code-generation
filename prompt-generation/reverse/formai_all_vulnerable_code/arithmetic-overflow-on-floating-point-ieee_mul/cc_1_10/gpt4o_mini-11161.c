//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1) // Ensure structures are packed

typedef struct {
    char chunkID[4];     // "RIFF"
    uint32_t chunkSize;
    char format[4];      // "WAVE"
    char subchunk1ID[4]; // "fmt "
    uint32_t subchunk1Size;
    uint16_t audioFormat; // 1 for PCM
    uint16_t numChannels;  // Mono = 1, Stereo = 2
    uint32_t sampleRate;   // Sample Rate
    uint32_t byteRate;     // SampleRate * numChannels * bitsPerSample/8
    uint16_t blockAlign;   // numChannels * bitsPerSample/8
    uint16_t bitsPerSample; // bits per sample (8, 16, 24, etc.)
    char subchunk2ID[4];   // "data"
    uint32_t subchunk2Size; // data size
} WAVHeader;

#pragma pack(pop)

void applyGain(int16_t* buffer, size_t samples, float gain) {
    for (size_t i = 0; i < samples; i++) {
        int32_t sample = (int32_t)(buffer[i] * gain);
        // Clamp the values to avoid overflow
        if (sample > INT16_MAX) {
            buffer[i] = INT16_MAX;
        } else if (sample < INT16_MIN) {
            buffer[i] = INT16_MIN;
        } else {
            buffer[i] = (int16_t)sample;
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input.wav> <output.wav> <gain>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* inputFileName = argv[1];
    const char* outputFileName = argv[2];
    float gain = atof(argv[3]);

    FILE* inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, inputFile);

    if (strncmp(header.chunkID, "RIFF", 4) != 0 || 
        strncmp(header.format, "WAVE", 4) != 0 || 
        header.audioFormat != 1) {
        fprintf(stderr, "Not a valid PCM WAV file.\n");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    size_t numSamples = header.subchunk2Size / sizeof(int16_t);
    int16_t* buffer = (int16_t*)malloc(header.subchunk2Size);
    if (!buffer) {
        perror("Unable to allocate buffer");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    fread(buffer, sizeof(int16_t), numSamples, inputFile);
    fclose(inputFile);

    applyGain(buffer, numSamples, gain);

    FILE* outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Error opening output file");
        free(buffer);
        return EXIT_FAILURE;
    }

    fwrite(&header, sizeof(WAVHeader), 1, outputFile);
    fwrite(buffer, sizeof(int16_t), numSamples, outputFile);

    fclose(outputFile);
    free(buffer);

    printf("Processed %zu samples with gain %.2f. Output written to %s.\n", numSamples, gain, outputFileName);
    
    return EXIT_SUCCESS;
}