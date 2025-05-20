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
    AudioStream* stream = (AudioStream*)malloc(sizeof(AudioStream));
    if (!stream) return NULL;

    // Simulate reading audio data from file
    FILE* file = fopen(filename, "rb");
    if (!file) {
        free(stream);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    fseek(file, 0, SEEK_SET);

    stream->data = (int*)malloc(size * sizeof(int));
    if (!stream->data) {
        fclose(file);
        free(stream);
        return NULL;
    }

    fread(stream->data, sizeof(int), size, file);
    fclose(file);
    stream->length = size;

    return stream;
}

void process_audio(AudioStream* stream) {
    if (!stream || !stream->data || stream->length == 0) return;

    // Process audio data
    for (size_t i = 0; i < stream->length; ++i) {
        printf("%d ", stream->data[i]);
    }
    printf("\n");
}

int main() {
    AudioStream* stream = decode_audio("audio.dat");
    if (!stream) {
        fprintf(stderr, "Failed to decode audio\n");
        return 1;
    }

    process_audio(stream);

    // Free the allocated memory
    free(stream->data);
    free(stream);

    // Use-after-free vulnerability
    printf("%d\n", stream->data[0]); // Accessing freed memory

    return 0;
}
