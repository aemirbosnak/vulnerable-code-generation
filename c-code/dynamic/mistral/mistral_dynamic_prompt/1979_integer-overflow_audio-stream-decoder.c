#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct WaveHeader {
    char chunkId[4];
    int chunkSize;
    char format[4];
    char subChunk1Id[4];
    int subChunk1Size;
    short audioFormat;
    short numChannels;
    int sampleRate;
    short byteResolution;
    int bytesPerSecond;
    short frameSize;
    char subChunk2Id[4];
    int subChunk2Size;
    char dataId[4];
} WaveHeader;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <wave file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Failed to open file");
        return 2;
    }

    WaveHeader header;
    fread(&header, sizeof(WaveHeader), 1, file);

    char buffer[BUFFER_SIZE];
    int read;

    // Vulnerable line with intentional integer overflow
    int i = 0;
    while ((read = fread(buffer, sizeof(char), header.bytesPerSecond, file)) > 0) {
        // Here we are not checking the size of buffer and reading data in a loop using header.bytesPerSecond
        // This may overflow if bytesPerSecond is larger than the size of the buffer
        for (int j = 0; j < read; j++) {
            printf("%c", buffer[j]);
        }
        i++;
    }

    fclose(file);
    return 0;
}
