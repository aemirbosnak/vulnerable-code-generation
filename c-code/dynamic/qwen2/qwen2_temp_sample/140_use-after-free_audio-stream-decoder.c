#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct {
    int* data;
    size_t size;
} AudioStream;

AudioStream* decode_audio(const char* input) {
    AudioStream* stream = (AudioStream*)malloc(sizeof(AudioStream));
    if (!stream) return NULL;

    stream->data = (int*)malloc(BUFFER_SIZE * sizeof(int));
    if (!stream->data) {
        free(stream);
        return NULL;
    }

    // Simulate decoding process
    for (size_t i = 0; i < BUFFER_SIZE; ++i) {
        stream->data[i] = i % 256;
    }
    stream->size = BUFFER_SIZE;

    return stream;
}

void play_audio(AudioStream* stream) {
    for (size_t i = 0; i < stream->size; ++i) {
        printf("%d ", stream->data[i]);
    }
    printf("\n");
}

int main() {
    const char* input = "audio_input";
    AudioStream* stream = decode_audio(input);

    if (stream) {
        play_audio(stream);
        free(stream->data); // Freeing the data pointer
    } else {
        fprintf(stderr, "Failed to decode audio\n");
        return 1;
    }

    // Use after free vulnerability
    printf("Data after free: %d\n", stream->data[0]); // Dereferencing freed memory

    return 0;
}
