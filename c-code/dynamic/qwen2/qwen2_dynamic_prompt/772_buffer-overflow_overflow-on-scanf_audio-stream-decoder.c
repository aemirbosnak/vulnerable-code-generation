#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void decode_audio_stream(char *stream) {
    char buffer[16];
    printf("Decoding audio stream...\n");
    // Vulnerability: No bounds checking on the input to buffer
    scanf("%s", buffer);
    printf("Decoded data: %s\n", buffer);
}

int main() {
    char audio_stream[256];
    printf("Enter audio stream data: ");
    fgets(audio_stream, sizeof(audio_stream), stdin);
    decode_audio_stream(audio_stream);
    return 0;
}
