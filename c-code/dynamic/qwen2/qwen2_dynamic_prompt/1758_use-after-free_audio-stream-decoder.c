#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    size_t length;
} AudioStream;

AudioStream* decode_audio(const char* filename) {
    AudioStream* stream = (AudioStream*)malloc(sizeof(AudioStream));
    if (!stream) return NULL;

    // Simulate reading audio data from file
    stream->length = 1024;
    stream->data = (int*)malloc(stream->length * sizeof(int));
    if (!stream->data) {
        free(stream);
        return NULL;
    }

    // Fill with dummy data
    for (size_t i = 0; i < stream->length; ++i) {
        stream->data[i] = i % 256;
    }

    return stream;
}

void process_audio(AudioStream* stream) {
    if (!stream || !stream->data) return;

    // Process audio data
    for (size_t i = 0; i < stream->length; ++i) {
        printf("%d ", stream->data[i]);
    }
    printf("\n");
}

int main() {
    const char* filename = "audio.dat";
    AudioStream* stream = decode_audio(filename);

    if (stream) {
        process_audio(stream);
        free(stream->data); // Free data
        // Use-after-free vulnerability here
        printf("Processed audio: ");
        process_audio(stream); // Access freed memory
    } else {
        fprintf(stderr, "Failed to decode audio\n");
    }

    return 0;
}
