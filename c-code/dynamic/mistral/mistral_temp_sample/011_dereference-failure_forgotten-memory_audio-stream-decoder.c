#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void decode_audio_stream(char *buffer) {
    unsigned char *data = (unsigned char *)buffer;
    unsigned char *frame = malloc(BUFFER_SIZE);
    unsigned int frame_size;

    while (1) {
        frame_size = data[0] << 8 | data[1];
        memcpy(frame, data + 2, frame_size);

        // Process audio frame here (forgotten memory access)
        printf("Processing frame of size %d: %s\n", frame_size, frame);
        printf("%p\n", frame[frame_size]); // Dereference out-of-bounds

        data += frame_size + 2;
    }
}

int main(int argc, char *argv[]) {
    char buffer[1024];

    if (argc != 2) {
        printf("Usage: %s <audio_stream>\n", argv[0]);
        return 1;
    }

    fread(buffer, sizeof(char), sizeof(buffer), stdin);
    decode_audio_stream(buffer);

    return 0;
}
