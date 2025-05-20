#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define HEADER_SIZE 18

void parse_header(unsigned char *buffer) {
    int channels, sampleRate, bitDepth;

    // Extract header information
    channels = buffer[1] & 0x0F;
    sampleRate = ((buffer[2] << 8) | buffer[3]);
    bitDepth = buffer[4] & 0xF0;

    // Buffer for sample data
    unsigned char *samples;
    samples = (unsigned char *)malloc(BUFFER_SIZE * (channels * (bitDepth / 8)));

    // Read sample data
    fread(samples, 1, BUFFER_SIZE * channels * (bitDepth / 8), stdin);

    // Process samples (Intentionally accessing past the end of the buffer to induce a segmentation fault)
    for (int i = BUFFER_SIZE * channels * (bitDepth / 8); i < BUFFER_SIZE * channels * (bitDepth / 8) * 2; i++) {
        printf("%d\n", samples[i]);
    }

    free(samples);
}

int main(int argc, char *argv[]) {
    unsigned char buffer[HEADER_SIZE];

    // Read header from input stream
    fread(buffer, 1, HEADER_SIZE, stdin);

    parse_header(buffer);

    return 0;
}
