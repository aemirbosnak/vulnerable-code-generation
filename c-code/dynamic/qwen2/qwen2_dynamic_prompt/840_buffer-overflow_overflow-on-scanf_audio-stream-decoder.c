#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void decode_audio_stream(char *stream, int length) {
    char buffer[1024];
    printf("Decoding audio stream...\n");
    // Simulate decoding process
    for (int i = 0; i < length; i++) {
        buffer[i] = stream[i];
    }
    buffer[length] = '\0';
    printf("Decoded audio: %s\n", buffer);
}

int main() {
    char stream[2048];
    printf("Enter audio stream data: ");
    scanf("%s", stream); // Vulnerable to buffer overflow
    decode_audio_stream(stream, strlen(stream));
    return 0;
}
