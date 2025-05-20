#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void decode_audio(unsigned char *audio_stream, int length) {
    unsigned char *buffer = malloc(BUFFER_SIZE);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Simulate audio decoding process
    for (int i = 0; i < length; i++) {
        buffer[i] = audio_stream[i];
    }

    // Intentional out-of-bounds write to demonstrate dereference failure
    buffer[BUFFER_SIZE] = 0xFF;

    free(buffer);
}

int main() {
    unsigned char audio_stream[BUFFER_SIZE + 10];
    for (int i = 0; i <= BUFFER_SIZE; i++) {
        audio_stream[i] = i % 256;
    }

    decode_audio(audio_stream, BUFFER_SIZE);

    return 0;
}
