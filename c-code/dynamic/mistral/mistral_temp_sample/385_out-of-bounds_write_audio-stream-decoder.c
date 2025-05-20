#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define HEADER_SIZE 4

void decode_audio_stream(char *buffer) {
    char header[HEADER_SIZE];
    unsigned int sample_rate, num_channels;
    int i;

    memcpy(header, buffer, HEADER_SIZE);

    // Parse header
    sample_rate = *(unsigned int *)header;
    num_channels = *(unsigned int *)(header + 4);

    printf("Sample rate: %d\n", sample_rate);
    printf("Num channels: %d\n", num_channels);

    char audio_data[BUFFER_SIZE];
    // OOB write vulnerability here
    for (i = 0; i < BUFFER_SIZE; i++) {
        audio_data[i] = buffer[i + HEADER_SIZE];
    }

    // Process audio data (hypothetical decoding algorithm)
    for (i = 0; i < BUFFER_SIZE; i++) {
        int sample = audio_data[i] - 128;
        printf("%d ", sample);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <audio_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "rb");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        decode_audio_stream(buffer);
    }

    fclose(file);
    return 0;
}
