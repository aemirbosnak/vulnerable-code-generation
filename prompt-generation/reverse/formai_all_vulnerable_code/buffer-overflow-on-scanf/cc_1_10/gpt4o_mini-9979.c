//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1) // Ensure the structures are packed without padding

typedef struct {
    char chunkID[4];      // "RIFF"
    uint32_t chunkSize;   // Size of the entire file - 8
    char format[4];       // "WAVE"
} RIFFHeader;

typedef struct {
    char subchunk1ID[4];  // "fmt "
    uint32_t subchunk1Size; // Size of the format data
    uint16_t audioFormat;  // Audio format (1 for PCM)
    uint16_t numChannels;   // Number of channels
    uint32_t sampleRate;    // Sample rate
    uint32_t byteRate;      // Bytes per second
    uint16_t blockAlign;    // Bytes per sample block
    uint16_t bitsPerSample;  // Bits per sample
} WAVFormat;

typedef struct {
    char subchunk2ID[4];     // "data"
    uint32_t subchunk2Size;  // Size of the data section
} WAVDataHeader;

#pragma pack(pop)

void processAudio(const char *inputFileName, const char *outputFileName, float gain) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Could not open input WAV file");
        return;
    }

    RIFFHeader riffHeader;
    fread(&riffHeader, sizeof(RIFFHeader), 1, inputFile);
    
    WAVFormat wavFormat;
    fread(&wavFormat, sizeof(WAVFormat), 1, inputFile);
    
    WAVDataHeader wavDataHeader;
    fread(&wavDataHeader, sizeof(WAVDataHeader), 1, inputFile);

    // Prepare to open the output file
    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Could not open output WAV file");
        fclose(inputFile);
        return;
    }

    // Write the header back to the output file
    fwrite(&riffHeader, sizeof(RIFFHeader), 1, outputFile);
    fwrite(&wavFormat, sizeof(WAVFormat), 1, outputFile);
    fwrite(&wavDataHeader, sizeof(WAVDataHeader), 1, outputFile);

    // Calculate number of samples
    int numSamples = wavDataHeader.subchunk2Size / (wavFormat.numChannels * (wavFormat.bitsPerSample / 8));
    int16_t *buffer = malloc(sizeof(int16_t) * numSamples * wavFormat.numChannels);
    
    if (buffer == NULL) {
        perror("Could not allocate memory for audio buffer");
        fclose(inputFile);
        fclose(outputFile);
        return;
    }

    fread(buffer, sizeof(int16_t), numSamples * wavFormat.numChannels, inputFile);
    
    // Process audio with gain
    for (int i = 0; i < numSamples * wavFormat.numChannels; i++) {
        float sample = (float) buffer[i];
        sample *= gain;

        // Clamp to 16-bit range
        if (sample > INT16_MAX) sample = INT16_MAX;
        if (sample < INT16_MIN) sample = INT16_MIN;

        buffer[i] = (int16_t) sample;
    }

    // Write modified samples to output file
    fwrite(buffer, sizeof(int16_t), numSamples * wavFormat.numChannels, outputFile);
    
    // Clean up and close files
    free(buffer);
    fclose(inputFile);
    fclose(outputFile);

    printf("Processing complete! Audio processed with a gain of %.2f.\n", gain);
}

int main() {
    char inputFileName[100], outputFileName[100];
    float gain;

    printf("Enter the input WAV file name: ");
    scanf("%99s", inputFileName);
    printf("Enter the output WAV file name: ");
    scanf("%99s", outputFileName);
    printf("Enter the gain value (e.g., 1.0 for no change, 2.0 for doubling volume): ");
    scanf("%f", &gain);

    if (gain < 0) {
        printf("Gain cannot be negative! Defaulting to 1.0.\n");
        gain = 1.0f;
    }

    processAudio(inputFileName, outputFileName, gain);
    
    return 0;
}