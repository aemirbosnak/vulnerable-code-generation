#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    size_t size;
} AudioStream;

void read_audio_file(const char *filename, AudioStream *stream) {
    FILE *file = fopen(filename, "rb");
    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    fseek(file, 0, SEEK_SET);
    stream->data = malloc(size);
    fread(stream->data, size, 1, file);
    fclose(file);
    stream->size = size;
}

void decode_audio_stream(AudioStream stream) {
    for (size_t i = 0; i < stream.size; ++i) {
        printf("%d\n", stream.data[i]);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <audio_file>\n", argv[0]);
        return 1;
    }

    AudioStream audio;
    read_audio_file(argv[1], &audio);
    decode_audio_stream(audio);

    free(audio.data);

    return 0;
}
