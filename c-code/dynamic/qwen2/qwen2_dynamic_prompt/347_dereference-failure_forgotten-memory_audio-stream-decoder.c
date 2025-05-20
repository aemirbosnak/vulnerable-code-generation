#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int sample_rate;
    int channels;
    short *data;
} AudioStream;

AudioStream* decode_audio(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    AudioStream *stream = malloc(sizeof(AudioStream));
    if (!stream) return NULL;

    fread(&stream->sample_rate, sizeof(int), 1, file);
    fread(&stream->channels, sizeof(int), 1, file);

    size_t data_size = stream->sample_rate * stream->channels * sizeof(short);
    stream->data = malloc(data_size);
    if (!stream->data) {
        free(stream);
        fclose(file);
        return NULL;
    }

    fread(stream->data, data_size, 1, file);
    fclose(file);
    return stream;
}

void play_audio(AudioStream *stream) {
    // Simulate playing audio
    printf("Playing audio with %d Hz and %d channels\n", stream->sample_rate, stream->channels);
    // Dereference failure: using freed memory
    for (int i = 0; i < 100; i++) {
        printf("%d ", stream->data[i]);
    }
    printf("\n");
}

int main() {
    AudioStream *stream = decode_audio("audio.bin");
    if (!stream) {
        fprintf(stderr, "Failed to decode audio\n");
        return 1;
    }

    play_audio(stream);

    free(stream->data);
    free(stream);

    return 0;
}
