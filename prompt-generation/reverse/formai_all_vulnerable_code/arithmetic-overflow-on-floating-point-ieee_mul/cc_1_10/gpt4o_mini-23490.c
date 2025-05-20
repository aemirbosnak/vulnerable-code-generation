//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define WAV_HEADER_SIZE 44

typedef struct {
    char chunkID[4];       // "RIFF"
    uint32_t chunkSize;
    char format[4];        // "WAVE"
    char subchunk1ID[4];   // "fmt "
    uint32_t subchunk1Size;
    uint16_t audioFormat;  // PCM = 1
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    char subchunk2ID[4];   // "data"
    uint32_t subchunk2Size;
} WAVHeader;

void apply_gain(int16_t* audioData, int32_t numSamples, float gain) {
    for (int32_t i = 0; i < numSamples; i++) {
        int32_t temp = (int32_t)(audioData[i] * gain);
        audioData[i] = (int16_t)(temp > INT16_MAX ? INT16_MAX : (temp < INT16_MIN ? INT16_MIN : temp));
    }
}

void print_wav_header(WAVHeader* header) {
    printf("WAV File Info:\n");
    printf("Chunk ID: %.4s\n", header->chunkID);
    printf("Chunk Size: %u\n", header->chunkSize);
    printf("Format: %.4s\n", header->format);
    printf("Subchunk1 ID: %.4s\n", header->subchunk1ID);
    printf("Subchunk1 Size: %u\n", header->subchunk1Size);
    printf("Audio Format: %u\n", header->audioFormat);
    printf("Num Channels: %u\n", header->numChannels);
    printf("Sample Rate: %u\n", header->sampleRate);
    printf("Byte Rate: %u\n", header->byteRate);
    printf("Block Align: %u\n", header->blockAlign);
    printf("Bits per Sample: %u\n", header->bitsPerSample);
    printf("Subchunk2 ID: %.4s\n", header->subchunk2ID);
    printf("Subchunk2 Size: %u\n", header->subchunk2Size);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <gain_factor>\n", argv[0]);
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
    
    if (strncmp(header.chunkID, "RIFF", 4) != 0 || strncmp(header.format, "WAVE", 4) != 0) {
        fprintf(stderr, "Error: Not a valid WAV file.\n");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    print_wav_header(&header);

    int32_t numSamples = header.subchunk2Size / sizeof(int16_t);
    int16_t* audioData = (int16_t*)malloc(header.subchunk2Size);
    if (!audioData) {
        fprintf(stderr, "Memory allocation failed.\n");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    fread(audioData, sizeof(int16_t), numSamples, inputFile);
    fclose(inputFile);

    apply_gain(audioData, numSamples, gain);

    FILE* outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Error opening output file");
        free(audioData);
        return EXIT_FAILURE;
    }

    fwrite(&header, sizeof(WAVHeader), 1, outputFile);
    fwrite(audioData, sizeof(int16_t), numSamples, outputFile);

    fclose(outputFile);
    free(audioData);

    printf("Processed audio saved to '%s' with gain factor: %f\n", outputFileName, gain);
    return EXIT_SUCCESS;
}