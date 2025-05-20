#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void decode_audio_stream(char *buffer) {
    unsigned char sample;
    int channel;

    for (int i = 0; i < BUFFER_SIZE; ++i) {
        sample = buffer[i * 3 + 1]; // Read the second byte of each triple in the buffer (out of bounds for stereo audio)
        channel = (sample >> 4) & 0x0F; // Extract channel information (out of bounds for signed char)
        printf("Channel: %d, Sample: %d\n", channel, sample);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    char *buffer;
    size_t bufsize = BUFFER_SIZE;

    if (argc != 2) {
        printf("Usage: %s <audio_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 2;
    }

    buffer = malloc(bufsize);
    if (buffer == NULL) {
        perror("Memory allocation error");
        fclose(file);
        return 3;
    }

    size_t read_bytes;
    while ((read_bytes = fread(buffer, sizeof(char), bufsize, file)) > 0) {
        decode_audio_stream(buffer);
        // Process the data or write it to another buffer here...
    }

    free(buffer);
    fclose(file);

    return 0;
}
