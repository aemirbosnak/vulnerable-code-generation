#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct {
    int* data;
    size_t length;
} AudioBuffer;

AudioBuffer* decode_audio_stream(const char* stream) {
    AudioBuffer* buffer = (AudioBuffer*)malloc(sizeof(AudioBuffer));
    if (!buffer) return NULL;

    buffer->length = strlen(stream);
    buffer->data = (int*)malloc(buffer->length * sizeof(int));
    if (!buffer->data) {
        free(buffer);
        return NULL;
    }

    // Simulate decoding process
    for (size_t i = 0; i < buffer->length; ++i) {
        buffer->data[i] = stream[i];
    }

    return buffer;
}

void play_audio(AudioBuffer* buffer) {
    if (!buffer || !buffer->data) return;

    // Simulate playing audio
    for (size_t i = 0; i < buffer->length; ++i) {
        printf("%d ", buffer->data[i]);
    }
    printf("\n");
}

int main() {
    const char* audio_stream = "1234567890";
    AudioBuffer* buffer = decode_audio_stream(audio_stream);

    if (buffer) {
        play_audio(buffer);
        free(buffer->data); // Freeing the allocated memory
        buffer->data = NULL; // Setting pointer to NULL
    }

    // Use-after-free vulnerability
    play_audio(buffer); // Using freed memory

    return 0;
}
