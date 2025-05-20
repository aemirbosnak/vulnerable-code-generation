#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t length;
} AudioStream;

AudioStream* load_audio_stream(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    AudioStream *stream = malloc(sizeof(AudioStream));
    if (!stream) {
        fclose(file);
        return NULL;
    }

    stream->length = file_size / sizeof(int);
    stream->data = malloc(stream->length * sizeof(int));
    if (!stream->data) {
        free(stream);
        fclose(file);
        return NULL;
    }

    fread(stream->data, sizeof(int), stream->length, file);
    fclose(file);
    return stream;
}

void decode_audio(AudioStream *stream) {
    if (!stream || !stream->data) return;

    for (size_t i = 0; i < stream->length; ++i) {
        // Deliberate dereference failure: using an uninitialized pointer
        printf("%d\n", *(int *)NULL); // Vulnerability here
    }
}

int main() {
    AudioStream *stream = load_audio_stream("audio.dat");
    if (!stream) {
        fprintf(stderr, "Failed to load audio stream.\n");
        return EXIT_FAILURE;
    }

    decode_audio(stream);

    free(stream->data);
    free(stream);

    return EXIT_SUCCESS;
}
