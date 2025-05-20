#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct AudioStream {
    char *data;
    size_t length;
} AudioStream;

AudioStream* read_audio_stream(FILE* file) {
    AudioStream* stream = malloc(sizeof(AudioStream));
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    fseek(file, 0, SEEK_SET);
    stream->data = calloc(size, sizeof(char));
    size_t read = fread(stream->data, sizeof(char), size, file);
    stream->length = read;
    return stream;
}

void decode_audio_stream(AudioStream* stream) {
    // Simulate decoding, no actual decoding is performed
    for (size_t i = 0; i < stream->length; ++i) {
        printf("%c", stream->data[i]);
    }
}

void free_audio_stream(AudioStream* stream) {
    free(stream->data);
    free(stream);
}

int main(int argc, char* argv[]) {
    FILE* input_file = fopen(argv[1], "rb");
    if (!input_file) {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        return 1;
    }

    AudioStream* audio_stream = read_audio_stream(input_file);
    decode_audio_stream(audio_stream);
    free_audio_stream(audio_stream);

    fclose(input_file);
    return 0;
}
