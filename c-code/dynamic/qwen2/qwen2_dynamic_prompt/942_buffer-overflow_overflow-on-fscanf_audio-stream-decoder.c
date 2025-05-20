#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void decode_audio_stream() {
    char buffer[BUFFER_SIZE];
    FILE *audio_file = fopen("audio_stream.dat", "r");
    if (!audio_file) {
        printf("Failed to open audio file.\n");
        return;
    }

    while (1) {
        // Vulnerability: No bounds checking on fscanf
        fscanf(audio_file, "%s", buffer);
        printf("Decoded data: %s\n", buffer);
    }

    fclose(audio_file);
}

int main() {
    decode_audio_stream();
    return 0;
}
