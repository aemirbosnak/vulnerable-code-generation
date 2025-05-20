//FormAI DATASET v1.0 Category: Audio processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main() {
    int sampleRate, numSamples;

    printf("Enter sample rate (Hz): ");
    scanf("%d", &sampleRate);

    printf("Enter number of samples: ");
    scanf("%d", &numSamples);

    double frequency1, frequency2, amplitude1, amplitude2;
    int i;

    printf("Enter frequency (Hz) for first sine wave: ");
    scanf("%lf", &frequency1);

    printf("Enter amplitude for first sine wave (0 to 1): ");
    scanf("%lf", &amplitude1);

    printf("Enter frequency (Hz) for second sine wave: ");
    scanf("%lf", &frequency2);

    printf("Enter amplitude for second sine wave (0 to 1): ");
    scanf("%lf", &amplitude2);

    double *buffer = (double*) malloc(numSamples * sizeof(double));

    if (buffer == NULL) {
        printf("Error: could not allocate memory.\n");
        return 1;
    }

    for (i = 0; i < numSamples; i++) {
        buffer[i] = amplitude1 * sin(2 * PI * frequency1 * i / sampleRate) + 
                    amplitude2 * sin(2 * PI * frequency2 * i / sampleRate);
    }

    FILE *outputFile = fopen("output.pcm", "wb");

    if (outputFile == NULL) {
        printf("Error: could not open file for writing.\n");
        return 1;
    }

    fwrite(buffer, sizeof(double), numSamples, outputFile);
    fclose(outputFile);

    printf("Successfully wrote %d samples to output.pcm.\n", numSamples);

    free(buffer);

    return 0;
}