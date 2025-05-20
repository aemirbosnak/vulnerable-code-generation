#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char *data;
    unsigned int size;
    unsigned int pos;
} AudioStream;

void read_header(AudioStream *stream, FILE *file) {
    fread(&(stream->size), sizeof(unsigned int), 1, file);
    stream->data = malloc(stream->size);
    fread(stream->data, sizeof(unsigned char), stream->size, file);
}

void decode_audio(AudioStream *stream) {
    for (int i = 0; i < stream->size; ++i) {
        printf("%c", *(stream->data + i) * *(stream->data + i));
    }
}

int main(int argc, char *argv[]) {
    AudioStream audio;
    FILE *file = fopen(argv[1], "rb");

    read_header(&audio, file);
    decode_audio(&audio);

    free(audio.data);
    fclose(file);

    return 0;
}
