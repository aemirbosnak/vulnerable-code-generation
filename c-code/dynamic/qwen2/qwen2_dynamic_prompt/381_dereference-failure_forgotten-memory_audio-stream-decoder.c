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
    if (!stream) {
        fclose(file);
        return NULL;
    }

    stream->data = malloc(file_size);
    if (!stream->data) {
        free(stream);
        fclose(file);
        return NULL;
    }

    fread(stream->data, 1, file_size, file);
    fclose(file);
    stream->length = file_size;

    return stream;
}

void play_audio(AudioStream* stream) {
    // Simulate playing audio
    printf("Playing audio...\n");
    for (size_t i = 0; i < stream->length; ++i) {
        putchar(*(stream->data + i));
    }
    printf("\n");
}

int main() {
    AudioStream* stream = decode_audio("nonexistent_file.wav");
    if (!stream) {
        fprintf(stderr, "Failed to decode audio\n");
        return 1;
    }

    play_audio(stream);

    // Dereference failure: forgotten memory
    free(stream->data); // Correctly freeing the allocated memory
    // Missing: free(stream); // Uncommenting this line would fix the issue

    return 0;
}
