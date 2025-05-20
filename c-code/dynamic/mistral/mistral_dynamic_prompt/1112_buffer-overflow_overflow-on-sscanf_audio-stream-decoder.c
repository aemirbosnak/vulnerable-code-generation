#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define HEADER_SIZE 50

typedef struct AudioStream {
    char header[HEADER_SIZE];
    char data[BUFFER_SIZE];
} AudioStream;

void decode_audio_stream(AudioStream* stream) {
    int i;
    char temp[12];

    printf("Decoding audio stream...\n");

    // Buffer overflow occurs here when user input exceeds size of 'temp'
    if (sscanf(stream->header, "%11s %s", temp, stream->data) != 2) {
        printf("Invalid audio stream format.\n");
        return;
    }

    // Assume data starts with 'W', 'A', 'V', 'E'
    if (strncmp(temp, "WAVE", 4)) {
        printf("Unsupported audio format.\n");
        return;
    }

    // Pseudocode for actual decoding
    for (i = 0; i < BUFFER_SIZE; ++i) {
        if (stream->data[i] == 0) {
            printf("Silence detected at position %d.\n", i);
        } else {
            printf("Data value at position %d: %c\n", i, stream->data[i]);
        }
    }
}

int main(int argc, char* argv[]) {
    AudioStream audio_stream = {0};
    size_t n;

    printf("Enter audio stream header (waveform file):\n");
    fgets(audio_stream.header, HEADER_SIZE, stdin);

    n = fread(audio_stream.data, 1, BUFFER_SIZE, stdin);
    if (n != BUFFER_SIZE) {
        printf("Premature end of audio stream.\n");
        return 1;
    }

    decode_audio_stream(&audio_stream);

    return 0;
}
