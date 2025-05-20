//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024
#define NUM_CHANNELS 2

int main() {
    FILE* inputFile;
    FILE* outputFile;
    short* inputBuffer;
    short* outputBuffer;
    int numSamplesRead;
    int numSamplesWritten;
    int i;

    inputFile = fopen("input.wav", "rb");
    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    outputFile = fopen("output.wav", "wb");
    if (outputFile == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    inputBuffer = (short*) malloc(BUFFER_SIZE * sizeof(short));
    outputBuffer = (short*) malloc(BUFFER_SIZE * sizeof(short));

    while ((numSamplesRead = fread(inputBuffer, sizeof(short), BUFFER_SIZE, inputFile))!= 0) {
        for (i = 0; i < numSamplesRead; i++) {
            outputBuffer[i] = inputBuffer[i];
        }

        numSamplesWritten = fwrite(outputBuffer, sizeof(short), numSamplesRead, outputFile);
        if (numSamplesWritten!= numSamplesRead) {
            printf("Error: could not write to output file.\n");
            exit(1);
        }
    }

    free(inputBuffer);
    free(outputBuffer);
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}