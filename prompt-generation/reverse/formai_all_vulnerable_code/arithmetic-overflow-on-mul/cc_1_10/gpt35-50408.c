//FormAI DATASET v1.0 Category: Audio processing ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

/* function prototypes */
double *loadWAV(char *filename, int *dataSize, int *sampleRate, int *numChannels);
int saveWAV(double *data, int dataSize, int sampleRate, int numChannels, char *filename);
double *applyLowpassFilter(double *audioData, int dataSize, int sampleRate, double cutoffFreq);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: %s input.wav\n", argv[0]);
        return 1;
    }

    int dataSize, sampleRate, numChannels;
    double *audioData = loadWAV(argv[1], &dataSize, &sampleRate, &numChannels);

    if (audioData == NULL)
    {
        printf("Error loading WAV file\n");
        return 1;
    }

    double cutoffFreq = 22050.0; /* set the cutoff frequency in Hz */
    audioData = applyLowpassFilter(audioData, dataSize, sampleRate, cutoffFreq);

    char outputFilename[256];
    sprintf(outputFilename, "lowpass_%s", argv[1]);
    saveWAV(audioData, dataSize, sampleRate, numChannels, outputFilename);
    free(audioData);

    return 0;
}

/* The loadWAV function loads a WAV file and returns a pointer to the audio data. */
double *loadWAV(char *filename, int *dataSize, int *sampleRate, int *numChannels)
{
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("Error: could not open file %s\n", filename);
        return NULL;
    }

    /* read the WAV header */
    char chunkID[4], format[4], subchunk1ID[4], subchunk2ID[4];
    int chunkSize, formatSubchunk1Size, audioFormat, subchunk2Size, byteRate, blockAlign, bitsPerSample;
    short *audioDataShort; /* store the audio data as 16-bit integers */
    double *audioData;     /* temporary storage for 64-bit floating point conversion */

    fread(chunkID, sizeof(char), 4, fp);
    fread(&chunkSize, sizeof(int), 1, fp);
    fread(format, sizeof(char), 4, fp);

    fread(subchunk1ID, sizeof(char), 4, fp);
    fread(&formatSubchunk1Size, sizeof(int), 1, fp);
    fread(&audioFormat, sizeof(short), 1, fp);
    fread(numChannels, sizeof(short), 1, fp);
    fread(sampleRate, sizeof(int), 1, fp);
    fread(&byteRate, sizeof(int), 1, fp);
    fread(&blockAlign, sizeof(short), 1, fp);
    fread(&bitsPerSample, sizeof(short), 1, fp);

    fread(subchunk2ID, sizeof(char), 4, fp);
    fread(&subchunk2Size, sizeof(int), 1, fp);

    /* allocate memory to store the audio data */
    audioDataShort = (short *)malloc(subchunk2Size);
    audioData = (double *)malloc(subchunk2Size * sizeof(double));

    /* read the audio data into memory */
    fread(audioDataShort, sizeof(short), subchunk2Size / sizeof(short), fp);

    fclose(fp);

    /* convert the audio data from 16-bit integers to doubles */
    *dataSize = subchunk2Size / sizeof(short);
    for (int i = 0; i < *dataSize; i++)
    {
        audioData[i] = (double)audioDataShort[i] / (double)32768.0;
    }

    free(audioDataShort);
    return audioData;
}

/* The saveWAV function saves the audio data to a WAV file. */
int saveWAV(double *data, int dataSize, int sampleRate, int numChannels, char *filename)
{
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL)
    {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    /* write the WAV header */
    char chunkID[4] = {'R', 'I', 'F', 'F'};
    int chunkSize = 36 + dataSize * sizeof(short);
    char format[4] = {'W', 'A', 'V', 'E'};

    char subchunk1ID[4] = {'f', 'm', 't', ' '};
    int formatSubchunk1Size = 16;
    short audioFormat = 1;
    short bitsPerSample = 16;
    short blockAlign = numChannels * sizeof(short);
    int byteRate = sampleRate * blockAlign;
    short numChannelsShort = (short)numChannels;

    char subchunk2ID[4] = {'d', 'a', 't', 'a'};
    int subchunk2Size = dataSize * sizeof(short);

    fwrite(chunkID, sizeof(char), 4, fp);
    fwrite(&chunkSize, sizeof(int), 1, fp);
    fwrite(format, sizeof(char), 4, fp);

    fwrite(subchunk1ID, sizeof(char), 4, fp);
    fwrite(&formatSubchunk1Size, sizeof(int), 1, fp);
    fwrite(&audioFormat, sizeof(short), 1, fp);
    fwrite(&numChannelsShort, sizeof(short), 1, fp);
    fwrite(&sampleRate, sizeof(int), 1, fp);
    fwrite(&byteRate, sizeof(int), 1, fp);
    fwrite(&blockAlign, sizeof(short), 1, fp);
    fwrite(&bitsPerSample, sizeof(short), 1, fp);

    fwrite(subchunk2ID, sizeof(char), 4, fp);
    fwrite(&subchunk2Size, sizeof(int), 1, fp);

    /* convert the audio data from doubles to 16-bit integers */
    short *audioDataShort = (short *)malloc(subchunk2Size);
    for (int i = 0; i < dataSize; i++)
    {
        audioDataShort[i] = (short)(data[i] * 32768.0);
    }

    /* write the audio data to the file */
    fwrite(audioDataShort, sizeof(short), dataSize, fp);

    fclose(fp);
    free(audioDataShort);

    return 0;
}

/* The applyLowpassFilter function applies a recursive lowpass filter to the audio data. */
double *applyLowpassFilter(double *audioData, int dataSize, int sampleRate, double cutoffFreq)
{
    double RC = 1.0 / (cutoffFreq * 2.0 * PI);
    double dt = 1.0 / sampleRate;
    double alpha = RC / (RC + dt);
    double *filteredAudio = (double *)malloc(dataSize * sizeof(double));

    /* recursive lowpass filter implementation */
    filteredAudio[0] = audioData[0];
    for (int i = 1; i < dataSize; i++)
    {
        filteredAudio[i] = alpha * audioData[i] + (1 - alpha) * filteredAudio[i - 1];
    }

    return filteredAudio;
}