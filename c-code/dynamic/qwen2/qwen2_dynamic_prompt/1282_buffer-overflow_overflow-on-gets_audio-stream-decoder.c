#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void decode_audio_stream(char *stream) {
    char buffer[BUFFER_SIZE];
    gets(buffer); // Vulnerable to buffer overflow
}

int main() {
    char audio_stream[2048];
    printf("Enter audio stream: ");
    fgets(audio_stream, sizeof(audio_stream), stdin);
    decode_audio_stream(audio_stream);
    return 0;
}
