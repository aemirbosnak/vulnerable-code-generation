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
    gets(buffer); // Vulnerability: using gets() which does not check buffer size
    printf("Buffer contents: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <audio_stream>\n", argv[0]);
        return 1;
    }
    decode_audio_stream(argv[1]);
    return 0;
}
