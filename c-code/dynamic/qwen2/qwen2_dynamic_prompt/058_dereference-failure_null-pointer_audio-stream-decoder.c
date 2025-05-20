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

AudioStream* load_audio_stream(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) return NULL;

    fseek(file, 0, SEEK_END);
    size_t length = ftell(file);
    fseek(file, 0, SEEK_SET);

    AudioStream* stream = malloc(sizeof(AudioStream));
    if (!stream) return NULL;

    stream->data = malloc(length * sizeof(int));
    if (!stream->data) {
        free(stream);
        return NULL;
    }

    fread(stream->data, sizeof(int), length, file);
    fclose(file);
    stream->length = length;

    return stream;
}

void decode_audio(AudioStream* stream) {
    if (!stream || !stream->data || stream->length == 0) return;

    int* ptr = stream->data;
    for (size_t i = 0; i < stream->length; ++i) {
        printf("%d ", *(ptr + i)); // Dereference failure here
    }
    printf("\n");
}

int main() {
    AudioStream* stream = load_audio_stream("nonexistent_file.bin");
    if (!stream) {
        fprintf(stderr, "Failed to load audio stream\n");
        return EXIT_FAILURE;
    }

    decode_audio(NULL); // Null pointer dereference

    free(stream->data);
    free(stream);

    return EXIT_SUCCESS;
}
