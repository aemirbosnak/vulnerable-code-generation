//FormAI DATASET v1.0 Category: Audio processing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BUFFER_SIZE 1024

/* function to normalize the audio signal */
void normalize(float *samples, int sampleCount)
{
    int i;
    float max = 0.0f;

    /* iterate through the samples to find the maximum sample value */
    for (i = 0; i < sampleCount; i++)
    {
        if (fabs(samples[i]) > max)
        {
            max = fabs(samples[i]);
        }
    }

    /* divide every sample by the maximum sample value */
    for (i = 0; i < sampleCount; i++)
    {
        samples[i] /= max;
    }
}

/* function to apply a low-pass filter to the audio signal */
void low_pass_filter(float *samples, int sampleCount, float cutoffFrequency, float sampleRate)
{
    int i;
    float RC = 1.0f / (2.0f * M_PI * cutoffFrequency);
    float dt = 1.0f / sampleRate;
    float alpha = dt / (RC + dt);
    float prevSample = 0.0f;

    /* iterate through the samples and apply the filter */
    for (i = 0; i < sampleCount; i++)
    {
        float currentSample = samples[i];
        float filteredSample = (alpha * currentSample) + ((1.0f - alpha) * prevSample);
        samples[i] = filteredSample;
        prevSample = filteredSample;
    }
}

int main()
{
    FILE *inputFile, *outputFile;
    char inputFileName[BUFFER_SIZE], outputFileName[BUFFER_SIZE];
    float cutoffFrequency, sampleRate;
    int i, sampleCount;

    /* read in the file names from the user */
    printf("Enter input file name: ");
    scanf("%s", inputFileName);

    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    /* read in the filter parameters from the user */
    printf("Enter cutoff frequency: ");
    scanf("%f", &cutoffFrequency);

    printf("Enter sample rate: ");
    scanf("%f", &sampleRate);

    /* open the input file for reading */
    inputFile = fopen(inputFileName, "rb");
    if (!inputFile)
    {
        printf("Error: failed to open input file\n");
        return 1;
    }

    /* open the output file for writing */
    outputFile = fopen(outputFileName, "wb");
    if (!outputFile)
    {
        printf("Error: failed to open output file\n");
        fclose(inputFile);
        return 1;
    }

    /* allocate memory for the audio samples */
    float *samples = (float *)malloc(BUFFER_SIZE * sizeof(float));

    /* read in the audio samples in chunks */
    while ((sampleCount = fread(samples, sizeof(float), BUFFER_SIZE, inputFile)) > 0)
    {
        /* apply normalization */
        normalize(samples, sampleCount);

        /* apply low-pass filter */
        low_pass_filter(samples, sampleCount, cutoffFrequency, sampleRate);

        /* write the filtered samples to the output file */
        fwrite(samples, sizeof(float), sampleCount, outputFile);
    }

    /* free the memory allocated for the audio samples */
    free(samples);

    /* close the input and output files */
    fclose(inputFile);
    fclose(outputFile);

    printf("Successfully filtered the audio file!\n");

    return 0;
}