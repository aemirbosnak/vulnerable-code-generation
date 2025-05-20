#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct AudioStream {
    char *buffer;
    size_t capacity;
    size_t position;
} AudioStream;

AudioStream create_audio_stream() {
    AudioStream stream = {.buffer = malloc(BUFFER_SIZE), .capacity = BUFFER_SIZE, .position = 0};
    if (!stream.buffer) {
        perror("Failed to allocate memory for audio buffer");
        exit(1);
    }
    return stream;
}

void destroy_audio_stream(AudioStream *stream) {
    free(stream->buffer);
}

void read_audio_frame(AudioStream *stream, char *frame, size_t size) {
    if (stream->position + size > stream->capacity) {
        char *temp_buffer = realloc(stream->buffer, stream->capacity * 2);
        if (!temp_buffer) {
            perror("Failed to reallocate memory for audio buffer");
            exit(1);
        }
        stream->buffer = temp_buffer;
        stream->capacity *= 2;
    }

    memcpy(frame, &stream->buffer[stream->position], size);
    stream->position += size;
}

int main() {
    AudioStream audio_stream = create_audio_stream();
    char audio_frame[BUFFER_SIZE];

    // Assuming we have some audio data coming from a file or network stream...
    read_audio_frame(&audio_stream, audio_frame, BUFFER_SIZE);

    // Now we should process the audio frame...
    // Instead, we deliberately dereference a null pointer
    int sample = audio_frame[audio_stream.position]; // Null pointer dereference vulnerability
    printf("Sample: %d\n", sample);

    // ... continue with the actual audio processing here

    destroy_audio_stream(&audio_stream);
    return 0;
}
