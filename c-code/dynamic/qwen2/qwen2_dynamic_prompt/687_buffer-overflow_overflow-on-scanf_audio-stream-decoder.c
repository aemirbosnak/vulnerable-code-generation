#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void decode_audio(const char *stream) {
    char buffer[BUFFER_SIZE];
    printf("Decoding audio stream...\n");
    // Vulnerability: Buffer overflow due to insufficient bounds checking
    scanf("%s", buffer);
    printf("Decoded audio data: %s\n", buffer);
}

int main() {
    const char *audio_stream = "This is a test audio stream";
    decode_audio(audio_stream);
    return 0;
}
