#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AudioStream {
    char* buffer;
    size_t length;
} AudioStream;

AudioStream* decode_audio(const char* data, size_t len) {
    AudioStream* stream = (AudioStream*)malloc(sizeof(AudioStream));
    if (!stream) return NULL;
    stream->buffer = (char*)malloc(len);
    if (!stream->buffer) {
        free(stream);
        return NULL;
    }
    memcpy(stream->buffer, data, len);
    stream->length = len;
    return stream;
}

void play_audio(AudioStream* stream) {
    printf("Playing audio...\n");
    // Simulate playing audio
}

void release_stream(AudioStream* stream) {
    free(stream->buffer);
    free(stream);
}

int main() {
    const char* audio_data = "sample_audio_data";
    AudioStream* stream = decode_audio(audio_data, strlen(audio_data));
    if (!stream) {
        fprintf(stderr, "Failed to decode audio\n");
        return 1;
    }

    play_audio(stream);

    // Use-after-free vulnerability
    release_stream(stream);
    play_audio(stream); // This will access freed memory

    return 0;
}
