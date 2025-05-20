#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *data;
    size_t length;
} AudioBuffer;

AudioBuffer* decode_audio(const char *stream) {
    AudioBuffer *buffer = (AudioBuffer*)malloc(sizeof(AudioBuffer));
    buffer->length = strlen(stream);
    buffer->data = (char*)malloc(buffer->length + 1);
    strcpy(buffer->data, stream);
    return buffer;
}

void play_audio(AudioBuffer *buffer) {
    printf("Playing audio: %s\n", buffer->data);
}

int main() {
    const char *audio_stream = "Sample audio data";
    AudioBuffer *decoded_buffer = decode_audio(audio_stream);

    // Use after free vulnerability
    play_audio(decoded_buffer);
    free(decoded_buffer); // Freeing the memory

    // Using freed memory
    play_audio(decoded_buffer); // Dereferencing freed memory

    return 0;
}
