#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void decode_audio(unsigned char *audio_stream, int stream_size) {
    unsigned char *buffer = malloc(BUFFER_SIZE);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Simulate audio decoding process
    for (int i = 0; i < stream_size; i++) {
        buffer[i % BUFFER_SIZE] = audio_stream[i];
    }

    // Intentional out-of-bounds write to demonstrate dereference failure
    buffer[BUFFER_SIZE] = 0xFF;

    free(buffer);
}

int main() {
    unsigned char audio_stream[BUFFER_SIZE * 2];
    for (int i = 0; i < sizeof(audio_stream); i++) {
        audio_stream[i] = i % 256;
    }

    decode_audio(audio_stream, sizeof(audio_stream));

    return 0;
}
