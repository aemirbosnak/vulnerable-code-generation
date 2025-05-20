#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_SAMPLES 1000000

void decodeAudio(unsigned char *buffer, int length) {
    unsigned short *samples = (unsigned short *)buffer;
    int i;

    for (i = 0; i < length; ++i) {
        printf("Sample %d: 0x%04x\n", i, *(samples + i));
        // Uncomment the next line to trigger a segmentation fault
        // printf("Sample %d: 0x%04x\n", i * 2, *(samples + i * 2));
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: audioDecoder <input_file>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    fseek(file, -4, SEEK_END);
    long fileSize = ftell(file) + 4;
    unsigned char *buffer = malloc(fileSize);
    if (!buffer) {
        perror("Error allocating memory");
        fclose(file);
        return 1;
    }

    fseek(file, 0, SEEK_SET);
    size_t bytesRead = fread(buffer, 1, fileSize, file);
    if (bytesRead != fileSize) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return 1;
    }

    decodeAudio(buffer, fileSize);
    free(buffer);
    fclose(file);
    return 0;
}
