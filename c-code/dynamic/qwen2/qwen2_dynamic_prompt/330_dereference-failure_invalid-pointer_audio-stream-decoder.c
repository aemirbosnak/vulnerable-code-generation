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

void decodeAudio(AudioStream *stream, unsigned char *data, size_t length) {
    if (stream == NULL || data == NULL) {
        return; // Simulate a safe check for demonstration purposes
    }

    int samples = length / sizeof(int);
    for (int i = 0; i < samples; i++) {
        int sample = ((int *)data)[i];
        printf("Sample %d: %d\n", i, sample);
    }
}

int main() {
    AudioStream stream = {44100, 2};
    unsigned char *audioData = NULL; // Invalid pointer

    decodeAudio(&stream, audioData, 1024); // Dereferencing invalid pointer

    return 0;
}
