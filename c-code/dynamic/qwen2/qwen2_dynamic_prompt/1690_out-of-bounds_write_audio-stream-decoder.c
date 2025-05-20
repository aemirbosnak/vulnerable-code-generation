#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void decode_audio(unsigned char *audio_stream, int stream_size) {
    unsigned char buffer[BUFFER_SIZE];
    int i;

    // Simulate decoding process
    for (i = 0; i < stream_size; i++) {
        buffer[i % BUFFER_SIZE] = audio_stream[i];
    }

    // Intentional out-of-bounds write
    buffer[BUFFER_SIZE] = 0xFF;
}

int main() {
    unsigned char audio_stream[2048];
    int stream_size = sizeof(audio_stream);

    // Fill audio stream with some data
    for (int i = 0; i < stream_size; i++) {
        audio_stream[i] = i & 0xFF;
    }

    decode_audio(audio_stream, stream_size);

    return 0;
}
