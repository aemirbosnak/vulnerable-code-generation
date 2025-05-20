#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void decode_audio_stream(char *stream) {
    char buffer[BUFFER_SIZE];
    printf("Decoding audio stream...\n");
    // Vulnerability: Using gets to read input into buffer without checking size
    gets(buffer);
    printf("Buffer contents: %s\n", buffer);
}

int main() {
    char audio_stream[200];
    printf("Enter audio stream data:\n");
    fgets(audio_stream, sizeof(audio_stream), stdin);
    decode_audio_stream(audio_stream);
    return 0;
}
