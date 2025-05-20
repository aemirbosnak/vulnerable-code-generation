#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct {
    int* buffer;
    size_t length;
} AudioStream;

AudioStream* load_audio_stream(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) return NULL;

    fseek(file, 0, SEEK_END);
    size_t length = ftell(file);
    fseek(file, 0, SEEK_SET);

    AudioStream* stream = (AudioStream*)malloc(sizeof(AudioStream));
    if (!stream) return NULL;

    stream->buffer = (int*)malloc(length * sizeof(int));
    if (!stream->buffer) {
        free(stream);
        return NULL;
    }

    fread(stream->buffer, sizeof(int), length, file);
    fclose(file);
    stream->length = length;

    return stream;
}

void process_audio(AudioStream* stream) {
    // Simulate processing by freeing the buffer
    free(stream->buffer);
    stream->buffer = NULL;
    stream->length = 0;

    // Use-after-free vulnerability: Accessing freed memory
    for (size_t i = 0; i < 10; i++) {
        printf("%d ", stream->buffer[i]); // This line is vulnerable
    }
    printf("\n");
}

int main() {
    AudioStream* stream = load_audio_stream("audio.dat");
    if (!stream) {
        fprintf(stderr, "Failed to load audio stream\n");
        return 1;
    }

    process_audio(stream);

    // Free the AudioStream structure itself
    free(stream);

    return 0;
}
