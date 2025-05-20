#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AudioStream {
    char *buffer;
    size_t capacity;
    size_t length;
} AudioStream;

AudioStream create_audio_stream(size_t capacity) {
    AudioStream stream = { NULL, capacity, 0 };
    stream.buffer = malloc(capacity * sizeof(char));
    return stream;
}

void append_to_audio_stream(AudioStream *stream, const char *data, size_t data_len) {
    if (stream->length + data_len > stream->capacity) {
        stream->capacity *= 2;
        stream->buffer = realloc(stream->buffer, stream->capacity * sizeof(char));
    }
    memcpy(stream->buffer + stream->length, data, data_len);
    stream->length += data_len;
}

void decode_audio(AudioStream stream) {
    // Assume some decoding logic here...
}

int main() {
    AudioStream audio_stream = create_audio_stream(1024);
    append_to_audio_stream(&audio_stream, "Audio data...", 500);
    decode_audio(audio_stream);

    free(audio_stream.buffer); // Use after free vulnerability

    append_to_audio_stream(&audio_stream, "More audio data...", 500); // Uninitialized access

    decode_audio(audio_stream);

    return 0;
}
