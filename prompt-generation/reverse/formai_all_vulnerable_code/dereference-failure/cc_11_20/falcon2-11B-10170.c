//Falcon2-11B DATASET v1.0 Category: Digital signal processing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define N 4096

int main(int argc, char **argv)
{
    FILE *audioFile;
    short int *audioData;
    float *fftData;
    int i;
    int j;
    int k;

    if (argc!= 2) {
        printf("Usage: %s <audio_file>\n", argv[0]);
        return 1;
    }

    audioFile = fopen(argv[1], "rb");
    if (audioFile == NULL) {
        printf("Could not open audio file %s.\n", argv[1]);
        return 1;
    }

    audioData = (short int *) malloc(N * sizeof(short int));
    if (audioData == NULL) {
        printf("Could not allocate memory for audio data.\n");
        return 1;
    }

    fread(audioData, N, 1, audioFile);
    fclose(audioFile);

    fftData = (float *) malloc(N * sizeof(float));
    if (fftData == NULL) {
        printf("Could not allocate memory for FFT data.\n");
        return 1;
    }

    for (i = 0; i < N; i++) {
        fftData[i] = (float) audioData[i];
    }

    for (i = 0; i < N / 2; i++) {
        for (j = 0; j < N - i - 1; j++) {
            k = i + j;
            fftData[j] += fftData[k] * (-1.0);
        }
    }

    for (i = N / 2; i < N; i++) {
        fftData[i] = fftData[i - N / 2];
    }

    for (i = 0; i < N / 2; i++) {
        fftData[i] /= N;
        for (j = 0; j < N - i - 1; j++) {
            fftData[j] += fftData[i] * (-1.0);
        }
    }

    for (i = 0; i < N; i++) {
        printf("%.3f", fftData[i]);
        if (i % 40 == 39) {
            printf("\n");
        }
    }

    printf("\n");

    free(audioData);
    free(fftData);

    return 0;
}