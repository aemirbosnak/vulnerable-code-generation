#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct {
    unsigned char *data;
    size_t length;
} AudioStream;

AudioStream* load_audio_stream(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    fseek(file, 0, SEEK_END);
    size_t length = ftell(file);
    fseek(file, 0, SEEK_SET);

    AudioStream *stream = malloc(sizeof(AudioStream));
    if (!stream) {
        fclose(file);
        return NULL;
    }

    stream->data = malloc(length);
    if (!stream->data) {
        free(stream);
        fclose(file);
        return NULL;
    }

    fread(stream->data, 1, length, file);
    fclose(file);
    stream->length = length;

    return stream;
}

void decode_audio(AudioStream *stream) {
    unsigned char *buffer = stream->data;
    size_t length = stream->length;

    for (size_t i = 0; i < length; i++) {
        // Simulate audio decoding by just printing each byte
        printf("%02x ", buffer[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <audio_file>\n", argv[0]);
        return 1;
    }

    AudioStream *stream = load_audio_stream(argv[1]);
    if (!stream) {
        fprintf(stderr, "Failed to load audio stream\n");
        return 1;
    }

    decode_audio(stream);

    free(stream->data);
    free(stream);

    return 0;
}
