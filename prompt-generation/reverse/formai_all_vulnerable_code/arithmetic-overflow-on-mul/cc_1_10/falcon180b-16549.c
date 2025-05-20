//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define PI 3.14159265358979323846
#define MAX_SAMPLES 100000

typedef struct {
    float freq;
    float amp;
    float phase;
} SineWave;

SineWave* createSineWave(float freq, float amp) {
    SineWave* wave = malloc(sizeof(SineWave));
    wave->freq = freq;
    wave->amp = amp;
    wave->phase = 0.0;
    return wave;
}

float generateSine(SineWave* wave, float t) {
    float sample = sin(2.0 * PI * wave->freq * t + wave->phase);
    wave->phase += 2.0 * PI * wave->freq * t;
    if (wave->phase >= 2.0 * PI) {
        wave->phase -= 2.0 * PI;
    }
    return sample * wave->amp;
}

int main() {
    FILE* inputFile;
    FILE* outputFile;
    char inputFileName[50];
    char outputFileName[50];
    float sampleRate;
    int numChannels;
    int numSamples;
    float* inputBuffer;
    float* outputBuffer;
    SineWave* noiseWave;

    // Get input file name from user
    printf("Enter input file name: ");
    scanf("%s", inputFileName);

    // Open input file
    inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read header information from input file
    fseek(inputFile, 0, SEEK_SET);
    fread(&sampleRate, sizeof(float), 1, inputFile);
    fread(&numChannels, sizeof(int), 1, inputFile);
    fread(&numSamples, sizeof(int), 1, inputFile);

    // Allocate input and output buffers
    inputBuffer = malloc(numSamples * numChannels * sizeof(float));
    outputBuffer = malloc(numSamples * numChannels * sizeof(float));

    // Read input data from file
    fseek(inputFile, 44, SEEK_SET);
    fread(inputBuffer, sizeof(float), numSamples * numChannels, inputFile);

    // Close input file
    fclose(inputFile);

    // Create noise wave
    noiseWave = createSineWave(440.0, 0.5);

    // Process audio
    for (int i = 0; i < numSamples; i++) {
        for (int j = 0; j < numChannels; j++) {
            float sample = inputBuffer[(i * numChannels) + j];
            sample += generateSine(noiseWave, i / sampleRate);
            outputBuffer[(i * numChannels) + j] = sample;
        }
    }

    // Write output data to file
    sprintf(outputFileName, "%s_noise.wav", inputFileName);
    outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    fwrite(&sampleRate, sizeof(float), 1, outputFile);
    fwrite(&numChannels, sizeof(int), 1, outputFile);
    fwrite(&numSamples, sizeof(int), 1, outputFile);

    fwrite(outputBuffer, sizeof(float), numSamples * numChannels, outputFile);

    fclose(outputFile);

    printf("Done.\n");

    return 0;
}