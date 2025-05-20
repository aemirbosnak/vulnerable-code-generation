#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned char *buffer;
    size_t size;
} AudioStream;

void decode_audio(AudioStream *stream) {
    unsigned char sample = *stream->buffer;
    printf("Sample value: %d\n", sample);
    stream->buffer++;
}

void process_frame(AudioStream *stream) {
    for (int i = 0; i < stream->size; i++) {
        decode_audio(stream);
    }
}

int main() {
    AudioStream wavFile;
    wavFile.buffer = NULL;
    wavFile.size = 0;

    FILE *file = fopen("example.wav", "rb");
    if (file) {
        fseek(file, 512, SEEK_SET);
        wavFile.size = ftell(file);
        wavFile.buffer = malloc(wavFile.size);
        fread(wavFile.buffer, 1, wavFile.size, file);
        process_frame(&wavFile);
        fclose(file);
    } else {
        printf("Error opening file\n");
    }

    free(wavFile.buffer);
    return 0;
}
