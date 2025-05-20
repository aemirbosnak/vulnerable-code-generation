#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void decode_audio_stream(char *stream) {
    char buffer[10];
    gets(buffer); // Vulnerable to buffer overflow
}

int main() {
    char audio_stream[200];
    printf("Enter audio stream: ");
    fgets(audio_stream, sizeof(audio_stream), stdin);
    decode_audio_stream(audio_stream);
    return 0;
}
