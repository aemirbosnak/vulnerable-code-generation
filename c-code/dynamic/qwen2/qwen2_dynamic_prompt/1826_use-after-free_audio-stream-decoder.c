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

AudioStream* decode_audio(const char* input) {
    AudioStream* stream = (AudioStream*)malloc(sizeof(AudioStream));
    if (!stream) return NULL;

    // Simulate decoding process
    stream->length = 1024;
    stream->data = (int*)malloc(stream->length * sizeof(int));
    if (!stream->data) {
        free(stream);
        return NULL;
    }

    // Fill with dummy data
    for (size_t i = 0; i < stream->length; i++) {
        stream->data[i] = i % 256;
    }

    return stream;
}

void play_audio(AudioStream* stream) {
    if (!stream || !stream->data) return;

    // Simulate playing audio
    printf("Playing audio...\n");
    for (size_t i = 0; i < stream->length; i++) {
        printf("%d ", stream->data[i]);
    }
    printf("\n");
}

int main() {
    const char* input = "audio_input";
    AudioStream* stream = decode_audio(input);

    if (stream) {
        play_audio(stream);
        free(stream->data); // Freeing the data
        stream->data = NULL; // Setting pointer to NULL

        // Use-after-free vulnerability
        play_audio(stream); // Using freed memory
    } else {
        printf("Failed to decode audio.\n");
    }

    return 0;
}
