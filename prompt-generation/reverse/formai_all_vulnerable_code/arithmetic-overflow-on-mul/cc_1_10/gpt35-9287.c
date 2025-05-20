//FormAI DATASET v1.0 Category: Audio processing ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WAV_HEADER_SIZE 44

// Function to read the header data from WAV file
void readWavHeader(FILE *file, int* channels, int* sampleRate, int* bitsPerSample){

    char chunkId[4];
    int chunkSize;
    char format[4];
    char subchunk1Id[4];
    int subchunk1Size;
    short audioFormat;
    short numChannels;
    int sampleRateVal;
    int byteRate;
    short blockAlign;
    short bitsPerSampleVal;

    fread(chunkId, sizeof(char), 4, file);
    fread(&chunkSize, sizeof(int), 1, file);
    fread(format, sizeof(char), 4, file);
    fread(subchunk1Id, sizeof(char), 4, file);
    fread(&subchunk1Size, sizeof(int), 1, file);
    fread(&audioFormat, sizeof(short), 1, file);
    fread(&numChannels, sizeof(short), 1, file);
    fread(&sampleRateVal, sizeof(int), 1, file);
    fread(&byteRate, sizeof(int), 1, file);
    fread(&blockAlign, sizeof(short), 1, file);
    fread(&bitsPerSampleVal, sizeof(short), 1, file);

    *channels = (int)numChannels;
    *sampleRate = sampleRateVal;
    *bitsPerSample = (int)bitsPerSampleVal;
}

// Function to write the header data to WAV file
void writeWavHeader(FILE *file, int numChannels, int sampleRate, int bitsPerSample){

    char chunkId[] = "RIFF";
    int chunkSize = 0;
    char format[] = "WAVE";
    char subchunk1Id[] = "fmt ";
    int subchunk1Size = 16;
    short audioFormat = 1;
    short numChannelsVal = (short)numChannels;
    int sampleRateVal = sampleRate;
    int byteRate = sampleRate * numChannels * bitsPerSample/8;
    short blockAlign = numChannels * bitsPerSample/8;
    short bitsPerSampleVal = (short)bitsPerSample;
    char subchunk2Id[] = "data";
    int subchunk2Size = 0;

    fwrite(chunkId, sizeof(char), 4, file);
    fwrite(&chunkSize, sizeof(int), 1, file);
    fwrite(format, sizeof(char), 4, file);
    fwrite(subchunk1Id, sizeof(char), 4, file);
    fwrite(&subchunk1Size, sizeof(int), 1, file);
    fwrite(&audioFormat, sizeof(short), 1, file);
    fwrite(&numChannelsVal, sizeof(short), 1, file);
    fwrite(&sampleRateVal, sizeof(int), 1, file);
    fwrite(&byteRate, sizeof(int), 1, file);
    fwrite(&blockAlign, sizeof(short), 1, file);
    fwrite(&bitsPerSampleVal, sizeof(short), 1, file);
    fwrite(subchunk2Id, sizeof(char), 4, file);
    fwrite(&subchunk2Size, sizeof(int), 1, file);    

}

int main(){

    char inputFileName[100];
    char outputFileName[100];
    int delayInMs;

    printf("Enter the input file name:\n");
    fgets(inputFileName, 100, stdin);
    inputFileName[strlen(inputFileName)-1] = '\0';

    printf("Enter the output file name:\n");
    fgets(outputFileName, 100, stdin);
    outputFileName[strlen(outputFileName)-1] = '\0';

    printf("Enter delay time in ms:\n");
    scanf("%d", &delayInMs);

    FILE* inputFile = fopen(inputFileName, "rb");
    FILE* outputFile = fopen(outputFileName, "wb");

    int channels, sampleRate, bitsPerSample;
    readWavHeader(inputFile, &channels, &sampleRate, &bitsPerSample);

    writeWavHeader(outputFile, channels, sampleRate, bitsPerSample);

    // Calculate delay time in samples
    int delayInSamples = sampleRate * delayInMs / 1000;

    // Allocate memory for temporary buffer to store the samples
    short* buffer = (short*)malloc(delayInSamples * channels * sizeof(short));

    // Read the samples from input file
    short sample;
    int sampleCount = 0;
    while(fread(&sample, sizeof(short), 1, inputFile)){

        // Write the sample to output file with some delay
        if(sampleCount < delayInSamples){
            fwrite(&sample, sizeof(short), 1, outputFile);
            buffer[sampleCount*channels] = sample;
        }
        else{
            fwrite(&buffer[(sampleCount%delayInSamples)*channels], sizeof(short), 1, outputFile);
            buffer[(sampleCount%delayInSamples)*channels] = sample;
        }

        sampleCount++;
    }

    // Write remaining samples from buffer to output file
    int i;
    for(i=0; i<delayInSamples; i++){
        fwrite(&buffer[(sampleCount%delayInSamples)*channels], sizeof(short), 1, outputFile);
        sampleCount++;
    }

    free(buffer);

    fclose(inputFile);
    fclose(outputFile);

    return 0;

}