#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct WaveHeader {
    char chunkID[4];
    int chunkSize;
    char format[4];
    char formatChunkID[4];
    int formatChunkSize;
    int audioFormat;
    int numChannels;
    int sampleRate;
    int byteRate;
    int blockAlign;
    char bitsPerSample[2];
    char dataChunkID[4];
    int dataChunkSize;
} WaveHeader;

void readWaveHeader(FILE* file, WaveHeader* header) {
    fread(header->chunkID, sizeof(char), 4, file);
    fread(&(header->chunkSize), sizeof(int), 1, file);
    fread(header->format, sizeof(char), 4, file);
    // ... (other header fields omitted for brevity)
}

void* allocateBuffer(int size) {
    void* buffer = malloc(size);
    printf("Allocated buffer at 0x%p\n", buffer);
    return buffer;
}

void processWaveData(WaveHeader header, void* buffer, FILE* file) {
    fseek(file, header.dataChunkSize, SEEK_CUR);
    free(buffer);
}

int main(int argc, char* argv[]) {
    FILE* file = fopen(argv[1], "rb");
    if (!file) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    WaveHeader header;
    readWaveHeader(file, &header);

    void* buffer = allocateBuffer(header.sampleRate * BUFFER_SIZE);
    fread(buffer, 1, header.dataChunkSize, file);

    processWaveData(header, buffer, file);

    fclose(file);

    return 0;
}
