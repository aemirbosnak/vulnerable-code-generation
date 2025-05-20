//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define FRAME_SIZE 1024
#define NUM_BANDS 32

typedef struct {
    float freq;
    float gain;
} Band;

Band bands[NUM_BANDS];

float* applyEQ(float* input, int numSamples) {
    float* output = malloc(numSamples * sizeof(float));
    for (int i = 0; i < numSamples; i++) {
        float sum = 0;
        for (int j = 0; j < NUM_BANDS; j++) {
            float freq = (float)i * SAMPLE_RATE / FRAME_SIZE * bands[j].freq;
            float gain = pow(10, bands[j].gain / 20);
            sum += input[i] * gain * cos(2 * M_PI * freq);
        }
        output[i] = sum;
    }
    return output;
}

int main() {
    FILE* file;
    file = fopen("input.wav", "rb");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fseek(file, 44, SEEK_SET); // skip header
    int numSamples = 0;
    while (!feof(file)) {
        char buffer[4];
        fread(buffer, sizeof(char), 4, file);
        numSamples += (int)buffer[0] | (int)buffer[1] << 8 | (int)buffer[2] << 16 | (int)buffer[3] << 24;
    }

    float* input = malloc(numSamples * sizeof(float));
    rewind(file);
    fread(input, sizeof(float), numSamples, file);

    for (int i = 0; i < NUM_BANDS; i++) {
        bands[i].freq = (float)(i + 1) / NUM_BANDS;
        bands[i].gain = 0;
    }

    for (int i = 0; i < NUM_BANDS; i++) {
        printf("Band %d: ", i + 1);
        scanf("%f", &bands[i].gain);
    }

    float* output = applyEQ(input, numSamples);

    fclose(file);

    file = fopen("output.wav", "wb");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fwrite(output, sizeof(float), numSamples, file);

    fclose(file);

    printf("Done.\n");

    return 0;
}