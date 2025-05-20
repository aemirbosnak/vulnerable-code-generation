//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sndfile.h>

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024
#define PI 3.14159265358979323846

void applyReverb(float *inputBuffer, float *outputBuffer, int numFrames, float decayFactor) {
    for (int i = 0; i < numFrames; i++) {
        outputBuffer[i] = inputBuffer[i];
        if (i > 0) {
            outputBuffer[i] += decayFactor * outputBuffer[i - 1];
        }
    }
}

void processAudio(const char *inputFile, const char *outputFile, float decayFactor) {
    SF_INFO sfinfo;
    SNDFILE *infile, *outfile;

    infile = sf_open(inputFile, SFM_READ, &sfinfo);
    if (!infile) {
        fprintf(stderr, "Error opening input file: %s\n", sf_strerror(NULL));
        return;
    }

    outfile = sf_open(outputFile, SFM_WRITE, &sfinfo);
    if (!outfile) {
        fprintf(stderr, "Error opening output file: %s\n", sf_strerror(NULL));
        sf_close(infile);
        return;
    }

    float *inputBuffer = (float *)malloc(FRAMES_PER_BUFFER * sfinfo.channels * sizeof(float));
    float *outputBuffer = (float *)malloc(FRAMES_PER_BUFFER * sfinfo.channels * sizeof(float));

    if (!inputBuffer || !outputBuffer) {
        fprintf(stderr, "Memory allocation failed!\n");
        sf_close(infile);
        sf_close(outfile);
        return;
    }

    int readCount;
    while ((readCount = sf_readf_float(infile, inputBuffer, FRAMES_PER_BUFFER)) > 0) {
        for (int ch = 0; ch < sfinfo.channels; ch++) {
            // Apply reverb on a per-channel basis
            float *channelInput = inputBuffer + ch;
            float *channelOutput = outputBuffer + ch;
            applyReverb(channelInput, channelOutput, readCount, decayFactor);
        }
        sf_writef_float(outfile, outputBuffer, readCount);
    }

    free(inputBuffer);
    free(outputBuffer);
    sf_close(infile);
    sf_close(outfile);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input wav file> <output wav file> <decay factor (0-1)>\n", argv[0]);
        return EXIT_FAILURE;
    }

    float decayFactor = atof(argv[3]);
    if (decayFactor < 0.0 || decayFactor > 1.0) {
        fprintf(stderr, "Decay factor must be between 0 and 1.\n");
        return EXIT_FAILURE;
    }

    processAudio(argv[1], argv[2], decayFactor);
    printf("Reverb effect applied! Output saved to %s\n", argv[2]);

    return EXIT_SUCCESS;
}