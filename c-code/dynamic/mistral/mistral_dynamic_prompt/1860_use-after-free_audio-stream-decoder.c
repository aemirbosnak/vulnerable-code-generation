#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define HEADER_SIZE 18

typedef struct {
    unsigned char id[4];
    unsigned int sample_rate;
    unsigned int channel_count;
    unsigned int bit_depth;
    unsigned int data_size;
} WaveHeader;

void decode_wave(FILE* file, unsigned char* buffer) {
    WaveHeader header;
    fread(&header, sizeof(WaveHeader), 1, file);

    if (memcmp(header.id, "RIFF", 4) != 0 ||
        memcmp(header.id + 8, "data", 4) <= 0) {
        return;
    }

    unsigned char* data = malloc(header.data_size);
    fread(data, header.data_size, 1, file);

    // Process the audio data
    free(buffer);
    buffer = data;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "rb");
    if (!file) {
        perror("Failed to open file");
        return 2;
    }

    unsigned char* buffer = malloc(BUFFER_SIZE);
    decode_wave(file, buffer);

    // Do something with the buffer

    fclose(file);
    free(buffer);

    return 0;
}
