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

    // Out-of-bounds read
    printf("Decoded sample: %d\n", buffer[stream_size]);
}

int main() {
    unsigned char audio_stream[] = {0x01, 0x02, 0x03, 0x04, 0x05};
    int stream_size = sizeof(audio_stream);

    decode_audio(audio_stream, stream_size);

    return 0;
}
