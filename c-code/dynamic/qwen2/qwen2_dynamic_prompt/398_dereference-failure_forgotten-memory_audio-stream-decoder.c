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
} AudioStream;

AudioStream* decode_audio_stream(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    AudioStream* stream = malloc(sizeof(AudioStream));
    if (!stream) {
        fclose(file);
        return NULL;
    }

    stream->data = malloc(file_size * sizeof(int));
    if (!stream->data) {
        free(stream);
        fclose(file);
        return NULL;
    }

    fread(stream->data, sizeof(int), file_size, file);
    fclose(file);

    stream->length = file_size / sizeof(int);
    return stream;
}

void play_audio_stream(AudioStream* stream) {
    for (size_t i = 0; i < stream->length; ++i) {
        printf("%d ", stream->data[i]);
    }
    printf("\n");
}

int main() {
    AudioStream* stream = decode_audio_stream("audio.dat");
    if (!stream) {
        fprintf(stderr, "Failed to decode audio stream\n");
        return 1;
    }

    play_audio_stream(stream);

    free(stream->data);
    free(stream);

    // Dereference failure: accessing freed memory
    printf("%d\n", stream->data[0]);

    return 0;
}
