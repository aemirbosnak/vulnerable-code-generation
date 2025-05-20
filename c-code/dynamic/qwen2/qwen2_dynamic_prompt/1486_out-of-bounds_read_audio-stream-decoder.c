#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void decode_audio(unsigned char *audio_stream, int length) {
    unsigned char buffer[BUFFER_SIZE];
    int i;

    // Simulate decoding process
    for (i = 0; i < length; i++) {
        buffer[i % BUFFER_SIZE] = audio_stream[i];
    }

    // Out-of-bounds read
    printf("Decoded data: %c\n", buffer[length]);
}

int main() {
    unsigned char audio_stream[] = "Example audio stream";
    int length = sizeof(audio_stream) - 1;

    decode_audio(audio_stream, length);

    return 0;
}
