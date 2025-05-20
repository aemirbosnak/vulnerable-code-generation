#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int sample_rate;
    int channels;
    unsigned char *data;
} AudioStream;

void decodeAudio(AudioStream *stream) {
    if (stream == NULL) {
        printf("Error: Stream is null\n");
        return;
    }

    // Simulate decoding process
    int total_samples = stream->sample_rate * 2; // Example calculation

    // Null pointer dereference vulnerability
    for (int i = 0; i < total_samples; i++) {
        unsigned char sample = *(stream->data + i); // Dereferencing null pointer
        printf("%d ", sample);
    }
}

int main() {
    AudioStream stream;
    stream.sample_rate = 44100;
    stream.channels = 2;
    stream.data = NULL; // Intentionally set to null for demonstration

    decodeAudio(&stream);

    return 0;
}
