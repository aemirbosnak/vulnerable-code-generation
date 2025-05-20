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
    for (i = 0; i <= length; i++) { // Out-of-bounds write vulnerability
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
    int length = sizeof(audio_stream) - 1;

    decode_audio(audio_stream, length);

    return 0;
}
