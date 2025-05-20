#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct WaveFile {
    char riff[4];
    char format[4];
    char data[4];
    int chunks[3];
    char channelData[BUFFER_SIZE];
} WaveFile;

void decode_wave(FILE *file, WaveFile *waveFile) {
    fread(waveFile, sizeof(WaveFile), 1, file);

    if (strcmp(waveFile->riff, "RIFF") != 0 ||
        strcmp(waveFile->format, "WAVE") != 0 ||
        strcmp(waveFile->data, "data") != 0) {
        printf("Invalid file format.\n");
        return;
    }

    for (int i = 0; i < 3; ++i) {
        fread(&(waveFile->chunks[i]), sizeof(int), 1, file);
    }

    int dataSize = waveFile->chunks[1] + waveFile->chunks[2];
    fread(waveFile->channelData, sizeof(char), dataSize, file);

    for (int i = 0; i < dataSize; ++i) {
        printf("%d ", (int)waveFile->channelData[i]); // Out of bounds read vulnerability
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <wave_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        printf("Unable to open file: %s\n", argv[1]);
        return 2;
    }

    WaveFile waveFile;
    decode_wave(file, &waveFile);

    fclose(file);
    return 0;
}
