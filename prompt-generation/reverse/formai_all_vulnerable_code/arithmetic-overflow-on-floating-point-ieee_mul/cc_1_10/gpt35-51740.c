//FormAI DATASET v1.0 Category: Audio processing ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 4096

void readWaveFile(char* filename, float* sampleBuffer);
void writeWaveFile(char* filename, float* sampleBuffer);
void echo(float* sampleBuffer, float delay, float attenuation);
void chorus(float* sampleBuffer, float depth, float rate, float mix);

int main() {
    float sampleBuffer[BUFFER_SIZE];
    char filename[256];
    int choice;
    float delay, attenuation, depth, rate, mix;

    printf("Enter the name of the wave file to process: ");
    scanf("%s", filename);

    printf("\n1. Add echo\n2. Add chorus\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("\nEnter delay (in seconds): ");
            scanf("%f", &delay);
            printf("Enter attenuation (0 to 1): ");
            scanf("%f", &attenuation);
            echo(sampleBuffer, delay, attenuation);
            strcat(filename, "_echo.wav");
            break;
        case 2:
            printf("\nEnter depth (in seconds): ");
            scanf("%f", &depth);
            printf("Enter rate (in Hz): ");
            scanf("%f", &rate);
            printf("Enter mix (0 to 1): ");
            scanf("%f", &mix);
            chorus(sampleBuffer, depth, rate, mix);
            strcat(filename, "_chorus.wav");
            break;
        default:
            printf("\nInvalid choice.");
            return 1;
    }

    writeWaveFile(filename, sampleBuffer);

    return 0;
}

void readWaveFile(char* filename, float* sampleBuffer) {
    FILE* file;
    char header[44];
    int dataSize;

    file = fopen(filename, "rb");
    if (!file) {
        printf("Error: failed to open file %s\n", filename);
        exit(1);
    }

    fread(header, sizeof(char), 44, file);
    dataSize = *(int*)&header[40];

    fread(sampleBuffer, sizeof(float), dataSize/4, file);

    fclose(file);
}

void writeWaveFile(char* filename, float* sampleBuffer) {
    FILE* file;
    char header[44] = {
        'R', 'I', 'F', 'F', // ChunkID
        0, 0, 0, 0, // ChunkSize (to be filled in later)
        'W', 'A', 'V', 'E', // Format
        'f', 'm', 't', ' ', // Subchunk1ID
        16, 0, 0, 0, // Subchunk1Size
        3, 0, // Audio format
        1, 0, // Num channels
        68, 172, 0, 0, // Sample rate (44100)
        136, 88, 1, 0, // Byte rate (Sample rate * Num channels * Bits per sample / 8)
        2, 0, // Block align
        16, 0, // Bits per sample
        'd', 'a', 't', 'a', // Subchunk2ID
        0, 0, 0, 0, // Subchunk2Size (to be filled in later)
    };
    int dataSize = BUFFER_SIZE * sizeof(float);

    file = fopen(filename, "wb");
    if (!file) {
        printf("Error: failed to create file %s\n", filename);
        exit(1);
    }

    *(int*)&header[4] = 36 + dataSize;
    *(int*)&header[40] = dataSize;

    fwrite(header, sizeof(char), 44, file);
    fwrite(sampleBuffer, sizeof(float), BUFFER_SIZE, file);

    fclose(file);
}

void echo(float* sampleBuffer, float delay, float attenuation) {
    int delaySamples = delay * SAMPLE_RATE;
    int i;

    for (i = delaySamples; i < BUFFER_SIZE; i++) {
        sampleBuffer[i] += attenuation * sampleBuffer[i-delaySamples];
    }
}

void chorus(float* sampleBuffer, float depth, float rate, float mix) {
    float dMin = 0.001;
    float dMax = depth;
    int delaySamples;
    float d, x, y;
    int i, j;

    for (i = 0; i < BUFFER_SIZE; i++) {
        d = (dMax - dMin) * sin(2 * M_PI * rate * i / SAMPLE_RATE) / 2 + (dMax + dMin) / 2;
        delaySamples = d * SAMPLE_RATE;

        x = sampleBuffer[i];
        y = 0;

        for (j = 0; j < 2; j++) {
            y += mix * sampleBuffer[i-delaySamples+j];
        }

        sampleBuffer[i] = (1-mix)*x + y;
    }
}