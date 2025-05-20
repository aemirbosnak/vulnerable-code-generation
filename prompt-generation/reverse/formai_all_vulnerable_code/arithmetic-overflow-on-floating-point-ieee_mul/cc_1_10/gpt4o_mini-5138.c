//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1) // Ensuring packed structure which is critical for reading WAV header correctly
typedef struct {
    char chunkID[4];      // "RIFF"
    uint32_t chunkSize;   // size of the chunk
    char format[4];       // "WAVE"
    char subchunk1ID[4];  // "fmt "
    uint32_t subchunk1Size; // size of subchunk1
    uint16_t audioFormat;  // 1 for PCM
    uint16_t numChannels;   // number of channels
    uint32_t sampleRate;    // sample rate
    uint32_t byteRate;      // bytes per second
    uint16_t blockAlign;    // block align
    uint16_t bitsPerSample;  // bits per sample
    char subchunk2ID[4];    // "data"
    uint32_t subchunk2Size;  // size of data
} WAVHeader;
#pragma pack(pop)

void increaseVolume(int16_t *data, size_t dataSize, float volumeFactor) {
    for (size_t i = 0; i < dataSize / sizeof(int16_t); i++) {
        int32_t sample = (int32_t)data[i] * volumeFactor; // Increase volume
        if (sample > INT16_MAX) sample = INT16_MAX; // Clamp
        else if (sample < INT16_MIN) sample = INT16_MIN; // Clamp
        data[i] = (int16_t)sample; // Cast back to int16_t
    }
}

void processWavFile(const char *inputFile, const char *outputFile, float volumeFactor) {
    FILE *input = fopen(inputFile, "rb");
    if (!input) {
        fprintf(stderr, "Could not open input file %s\n", inputFile);
        exit(EXIT_FAILURE);
    }

    WAVHeader header;
    fread(&header, sizeof(header), 1, input);
    if (strncmp(header.chunkID, "RIFF", 4) != 0 || strncmp(header.format, "WAVE", 4) != 0) {
        fprintf(stderr, "Not a valid WAV file\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }
    
    size_t dataSize = header.subchunk2Size;
    int16_t *audioData = malloc(dataSize);
    if (!audioData) {
        fprintf(stderr, "Failed to allocate memory for audio data\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }
    
    fread(audioData, dataSize, 1, input);
    fclose(input);
    
    // Increase volume
    increaseVolume(audioData, dataSize, volumeFactor);
    
    // Write to output file
    FILE *output = fopen(outputFile, "wb");
    if (!output) {
        fprintf(stderr, "Could not open output file %s\n", outputFile);
        free(audioData);
        exit(EXIT_FAILURE);
    }
    
    fwrite(&header, sizeof(header), 1, output);
    fwrite(audioData, dataSize, 1, output);
    
    fclose(output);
    free(audioData);
    
    printf("Hooray! Volume increased and saved to %s\n", outputFile);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input.wav> <output.wav> <volumeFactor>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    float volumeFactor = atof(argv[3]);
    
    if (volumeFactor < 0) {
        fprintf(stderr, "Volume factor must be a positive number!\n");
        return EXIT_FAILURE;
    }
    
    printf("🎶 Let's increase the volume of your favorite WAV file! 🎶\n");
    processWavFile(inputFile, outputFile, volumeFactor);
    
    return EXIT_SUCCESS;
}