#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void decode_audio_stream(char *stream) {
    char buffer[128];
    printf("Decoding audio stream...\n");
    gets(buffer); // Vulnerable to buffer overflow
    printf("Buffer contents: %s\n", buffer);
}

int main() {
    char *audio_stream = "This is a test audio stream.";
    decode_audio_stream(audio_stream);
    return 0;
}
