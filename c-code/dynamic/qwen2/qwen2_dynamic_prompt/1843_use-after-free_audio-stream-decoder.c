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

    // Simulate reading file and decoding audio
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

void free_audio(AudioStream* stream) {
    if (!stream) return;

    free(stream->data);
    stream->data = NULL;
    stream->length = 0;
}

int main() {
    const char* filename = "audio.dat";
    AudioStream* stream = decode_audio(filename);

    if (stream) {
        process_audio(stream);
        free_audio(stream); // Free the allocated memory

        // Use after free vulnerability
        printf("Data after free: %d\n", stream->data[0]); // Accessing freed memory
    } else {
        fprintf(stderr, "Failed to decode audio stream.\n");
    }

    return 0;
}
