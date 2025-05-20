#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct WaveHeader {
    char chunkId[4];
    int chunkSize;
    char format[4];
    char formatSubType[4];
    int audioFormat;
    int numChannels;
    int sampleRate;
    int byteRate;
    int blockAlign;
    int bitsPerSample;
    char dataId[4];
    int dataSize;
} WaveHeader;

WaveHeader *loadWave(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    WaveHeader *header = malloc(sizeof(WaveHeader));
    fread(header, sizeof(WaveHeader), 1, file);

    free(header); // UAF example
    return header;
}

void decodeWave(WaveHeader *header) {
    // Decode the wave data...
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <wavefile>\n", argv[0]);
        return 1;
    }

    WaveHeader *header = loadWave(argv[1]);
    if (!header) return 1;

    decodeWave(header);

    return 0;
}
