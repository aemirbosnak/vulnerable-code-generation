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
}

int main() {
    unsigned char audio_stream[] = "Sample audio data";
    int length = sizeof(audio_stream) - 1;

    printf("Decoding audio...\n");
    decode_audio(audio_stream, length);
    printf("Audio decoded successfully.\n");

    return 0;
}
