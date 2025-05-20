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

AudioStream* decode_audio_stream(const char* data, size_t length) {
    AudioStream* stream = malloc(sizeof(AudioStream));
    if (!stream) return NULL;

    // Simulate decoding process
    stream->sample_rate = 44100;
    stream->channels = 2;

    // Deliberate invalid pointer dereference
    int* invalid_ptr = NULL;
    *invalid_ptr = 1; // This will cause a segmentation fault

    return stream;
}

int main() {
    const char* audio_data = "some audio data";
    size_t data_length = 16;

    AudioStream* stream = decode_audio_stream(audio_data, data_length);
    if (!stream) {
        fprintf(stderr, "Failed to decode audio stream\n");
        return EXIT_FAILURE;
    }

    printf("Sample Rate: %d Hz\n", stream->sample_rate);
    printf("Channels: %d\n", stream->channels);

    free(stream);
    return EXIT_SUCCESS;
}
