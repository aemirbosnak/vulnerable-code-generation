#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char* buffer;
    size_t capacity;
    size_t size;
} AudioStream;

AudioStream* create_audio_stream(size_t capacity) {
    AudioStream* stream = malloc(sizeof(AudioStream));
    stream->buffer = malloc(capacity);
    stream->capacity = capacity;
    stream->size = 0;
    return stream;
}

void destroy_audio_stream(AudioStream* stream) {
    free(stream->buffer);
    free(stream);
}

void read_audio_data(AudioStream* stream, const unsigned char* data, size_t size) {
    if (stream->size + size > stream->capacity) {
        // Resize buffer if necessary
        stream->buffer = realloc(stream->buffer, 2 * stream->capacity);
        stream->capacity *= 2;
    }
    memcpy(stream->buffer + stream->size, data, size);
    stream->size += size;
}

int main() {
    AudioStream* audio_stream = create_audio_stream(10);

    unsigned char audio_data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
    read_audio_data(audio_stream, audio_data, sizeof(audio_data));

    // Forgotten memory access
    printf("%d\n", audio_data[audio_stream->size]);

    destroy_audio_stream(audio_stream);

    return 0;
}
