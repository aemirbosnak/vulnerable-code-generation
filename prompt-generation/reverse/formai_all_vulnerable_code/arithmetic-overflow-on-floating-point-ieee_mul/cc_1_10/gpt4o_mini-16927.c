//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    char riff[4];        // RIFF Header       (4 bytes)
    uint32_t fileSize;  // File size         (4 bytes)
    char wave[4];       // WAVE Header       (4 bytes)
    char fmt[4];        // FMT Header        (4 bytes)
    uint32_t fmtSize;   // FMT size         (4 bytes)
    uint16_t audioFormat; // Audio format     (2 bytes)
    uint16_t numChannels; // Channels        (2 bytes)
    uint32_t sampleRate;  // Sample rate     (4 bytes)
    uint32_t byteRate;   // Byte rate        (4 bytes)
    uint16_t blockAlign; // Block align      (2 bytes)
    uint16_t bitsPerSample; // Bits per sample (2 bytes)
    char data[4];       // DATA Header       (4 bytes)
    uint32_t dataSize;  // File size of data (4 bytes)
} WAVHeader;

void applyGain(int16_t *buffer, size_t frames, float gain) {
    for (size_t i = 0; i < frames; i++) {
        int32_t temp = (int32_t)(buffer[i] * gain);
        buffer[i] = (int16_t)(temp > INT16_MAX ? INT16_MAX : (temp < INT16_MIN ? INT16_MIN : temp)); // Clamp values
    }
}

void processAudioFile(const char *inputFile, const char *outputFile, float gain) {
    FILE *inFile = fopen(inputFile, "rb");
    if (!inFile) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    WAVHeader header;
    fread(&header, sizeof(WAVHeader), 1, inFile);
    
    if (header.audioFormat != 1) {
        fprintf(stderr, "Error: Unsupported audio format, only PCM supported.\n");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    size_t frames = header.dataSize / sizeof(int16_t);
    int16_t *buffer = malloc(header.dataSize);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    fread(buffer, sizeof(int16_t), frames, inFile);
    fclose(inFile);

    // Apply gain processing
    applyGain(buffer, frames, gain);

    FILE *outFile = fopen(outputFile, "wb");
    if (!outFile) {
        perror("Error opening output file");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    fwrite(&header, sizeof(WAVHeader), 1, outFile);
    fwrite(buffer, sizeof(int16_t), frames, outFile);

    fclose(outFile);
    free(buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input WAV file> <output WAV file> <gain factor>\n", argv[0]);
        return EXIT_FAILURE;
    }

    float gain = atof(argv[3]);
    if (gain <= 0) {
        fprintf(stderr, "Gain factor must be a positive number.\n");
        return EXIT_FAILURE;
    }

    processAudioFile(argv[1], argv[2], gain);
    printf("Audio processing complete. Output saved to %s\n", argv[2]);

    return EXIT_SUCCESS;
}