//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <sndfile.h>
#include <math.h>

#define MAX_BUFFER_SIZE 44100 // Assuming we're processing 1 second of audio at a sample rate of 44100 Hz

void applyGain(float *buffer, sf_count_t numFrames, float gain) {
    for (sf_count_t i = 0; i < numFrames; i++) {
        buffer[i] *= gain;
    }
}

void applyReverb(float *inputBuffer, float *outputBuffer, sf_count_t numFrames, float reverbLevel) {
    int delaySamples = 441; // Reverb delay (in samples)
    for (sf_count_t i = 0; i < numFrames; i++) {
        outputBuffer[i] = inputBuffer[i];
        if (i >= delaySamples) {
            outputBuffer[i] += inputBuffer[i - delaySamples] * reverbLevel;
        }
    }
}

void processAudio(const char *inputFile, const char *outputFile, float gain, float reverbLevel) {
    SNDFILE *inFile, *outFile;
    SF_INFO sfinfo;

    inFile = sf_open(inputFile, SFM_READ, &sfinfo);
    if (!inFile) {
        fprintf(stderr, "Error opening input file: %s\n", sf_strerror(NULL));
        return;
    }

    float *buffer = (float *)malloc(MAX_BUFFER_SIZE * sizeof(float));
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed.\n");
        sf_close(inFile);
        return;
    }

    sf_count_t numFramesRead = sf_readf_float(inFile, buffer, MAX_BUFFER_SIZE);
    sf_close(inFile);

    float *outputBuffer = (float *)malloc(numFramesRead * sizeof(float));
    if (!outputBuffer) {
        fprintf(stderr, "Memory allocation for output buffer failed.\n");
        free(buffer);
        return;
    }

    applyGain(buffer, numFramesRead, gain);
    applyReverb(buffer, outputBuffer, numFramesRead, reverbLevel);

    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
    outFile = sf_open(outputFile, SFM_WRITE, &sfinfo);
    if (!outFile) {
        fprintf(stderr, "Error opening output file: %s\n", sf_strerror(NULL));
        free(buffer);
        free(outputBuffer);
        return;
    }

    sf_writef_float(outFile, outputBuffer, numFramesRead);
    sf_close(outFile);

    free(buffer);
    free(outputBuffer);
    printf("Audio processing completed: %s -> %s\n", inputFile, outputFile);
}

void displayHelp() {
    printf("Usage: audio_processor <input_file> <output_file> <gain> <reverb_level>\n");
    printf("  <gain>: Multiplicative gain factor (e.g., 0.5, 1.0, 2.0)\n");
    printf("  <reverb_level>: Reverb level (0.0 to 1.0)\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        displayHelp();
        return EXIT_FAILURE;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    float gain = atof(argv[3]);
    float reverbLevel = atof(argv[4]);

    if (gain < 0 || reverbLevel < 0 || reverbLevel > 1) {
        fprintf(stderr, "Error: Gain must be non-negative and reverb level must be between 0.0 and 1.0.\n");
        return EXIT_FAILURE;
    }

    processAudio(inputFile, outputFile, gain, reverbLevel);
    return EXIT_SUCCESS;
}