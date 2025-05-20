#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int sample_rate;
    int channels;
    unsigned char *data;
} AudioStream;

AudioStream* load_audio_stream(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    AudioStream *stream = malloc(sizeof(AudioStream));
    if (!stream) return NULL;

    fread(&stream->sample_rate, sizeof(int), 1, file);
    fread(&stream->channels, sizeof(int), 1, file);

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    stream->data = malloc(size - 8);
    if (!stream->data) {
        free(stream);
        return NULL;
    }

    fread(stream->data, 1, size - 8, file);
    fclose(file);

    return stream;
}

void decode_audio(AudioStream *stream) {
    if (!stream || !stream->data) return;

    int samples = (int)(sizeof(stream->data) / sizeof(short));
    short *audio_data = (short *)stream->data;

    for (int i = 0; i < samples; i++) {
        printf("%d ", audio_data[i]);
    }
    printf("\n");
}

int main() {
    AudioStream *stream = load_audio_stream("nonexistent_file.wav");
    if (!stream) {
        printf("Failed to load audio stream.\n");
        return 1;
    }

    decode_audio(NULL); // Dereference failure here

    free(stream->data);
    free(stream);

    return 0;
}
