#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int sample_rate;
    int channels;
} AudioStream;

void decodeAudio(AudioStream *stream, char *data, size_t length) {
    if (!stream || !data) return;

    // Simulate audio decoding process
    for (size_t i = 0; i < length; i += sizeof(int)) {
        int sample = *(int *)(data + i);
        printf("Sample: %d\n", sample);
    }
}

int main() {
    AudioStream stream = {44100, 2};
    char audioData[100];

    // Simulate receiving audio data
    for (int i = 0; i < 100; i++) {
        audioData[i] = i % 256;
    }

    decodeAudio(&stream, audioData, sizeof(audioData));

    // Intentionally free audioData to simulate forgotten memory
    free(audioData);

    // Attempt to use freed memory
    decodeAudio(&stream, audioData, sizeof(audioData));

    return 0;
}
