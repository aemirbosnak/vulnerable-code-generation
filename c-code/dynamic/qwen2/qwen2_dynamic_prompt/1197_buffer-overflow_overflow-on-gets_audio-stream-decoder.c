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
    // Vulnerability: Using gets() to read input into a fixed-size buffer
    gets(buffer);
    printf("Audio decoded successfully.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <audio_stream>\n", argv[0]);
        return 1;
    }
    decode_audio(argv[1]);
    return 0;
}
