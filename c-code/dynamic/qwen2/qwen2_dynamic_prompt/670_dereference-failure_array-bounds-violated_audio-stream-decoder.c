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
    for (i = 0; i <= stream_size; i++) { // Dereference failure here: out-of-bounds access
        buffer[i] = audio_stream[i];
    }

    // Print decoded data
    for (i = 0; i < BUFFER_SIZE; i++) {
        printf("%02x ", buffer[i]);
    }
    printf("\n");
}

int main() {
    unsigned char audio_stream[] = "Sample audio data";
    int stream_size = sizeof(audio_stream) - 1;

    decode_audio(audio_stream, stream_size);

    return 0;
}
