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

AudioStream* decode_audio(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) return NULL;

    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    AudioStream* stream = malloc(sizeof(AudioStream));
    if (!stream) return NULL;

    stream->data = malloc(file_size * sizeof(int));
    if (!stream->data) {
        free(stream);
        return NULL;
    }

    fread(stream->data, sizeof(int), file_size, file);
    fclose(file);
    stream->length = file_size;

    return stream;
}

void play_audio(AudioStream* stream) {
    for (size_t i = 0; i < stream->length; ++i) {
        printf("%d ", stream->data[i]);
    }
    printf("\n");
}

int main() {
    AudioStream* stream = decode_audio("nonexistent_file.wav");
    if (stream) {
        play_audio(stream);
        free(stream->data);
        free(stream);
    } else {
        printf("Failed to decode audio.\n");
    }
    return 0;
}
