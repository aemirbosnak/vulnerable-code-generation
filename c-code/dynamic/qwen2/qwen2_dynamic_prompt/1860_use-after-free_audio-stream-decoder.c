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
    stream->length = 1024; // Simulate audio length
    stream->data = (int*)malloc(stream->length * sizeof(int));
    if (!stream->data) {
        free(stream);
        return NULL;
    }
    // Simulate decoding process
    for (size_t i = 0; i < stream->length; ++i) {
        stream->data[i] = i % 256;
    }
    return stream;
}

void play_audio(AudioStream* stream) {
    if (!stream || !stream->data) return;
    for (size_t i = 0; i < stream->length; ++i) {
        printf("%d ", stream->data[i]);
    }
    printf("\n");
}

int main() {
    const char* input = "audio_input";
    AudioStream* stream = decode_audio(input);
    if (!stream) {
        fprintf(stderr, "Failed to decode audio\n");
        return 1;
    }

    play_audio(stream);

    // Use-after-free vulnerability
    free(stream->data);
    stream->data = NULL;

    // Attempt to access freed memory
    printf("Playing audio after free: ");
    play_audio(stream); // This will likely crash

    free(stream);
    return 0;
}
