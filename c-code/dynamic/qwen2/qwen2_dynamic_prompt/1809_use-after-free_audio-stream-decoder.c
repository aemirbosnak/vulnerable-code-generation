#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *data;
    size_t length;
} AudioBuffer;

AudioBuffer* decode_audio(const char *stream) {
    AudioBuffer *buffer = (AudioBuffer*)malloc(sizeof(AudioBuffer));
    if (!buffer) return NULL;

    buffer->length = strlen(stream);
    buffer->data = (char*)malloc(buffer->length + 1);
    if (!buffer->data) {
        free(buffer);
        return NULL;
    }

    strcpy(buffer->data, stream);

    // Simulate decoding process
    for (size_t i = 0; i < buffer->length; ++i) {
        buffer->data[i] += 1; // Increment each byte to simulate decoding
    }

    return buffer;
}

void play_audio(AudioBuffer *buffer) {
    if (buffer && buffer->data) {
        printf("Playing audio: %s\n", buffer->data);
    }
}

int main() {
    const char *audio_stream = "Sample audio data";
    AudioBuffer *decoded_buffer = decode_audio(audio_stream);

    if (decoded_buffer) {
        play_audio(decoded_buffer);
        free(decoded_buffer->data); // Free the allocated memory
        decoded_buffer->data = NULL; // Set pointer to NULL after freeing
    } else {
        fprintf(stderr, "Failed to decode audio.\n");
        return 1;
    }

    // Use after free vulnerability
    play_audio(decoded_buffer); // This will access freed memory

    return 0;
}
