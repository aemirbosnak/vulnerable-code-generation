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

AudioStream* load_audio_stream(const char *filename) {
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
        return NULL;
    }

    fread(stream->data, data_size, 1, file);
    fclose(file);
    return stream;
}

void decode_audio(AudioStream *stream) {
    if (!stream || !stream->data) return;

    // Simulate decoding process
    for (int i = 0; i < 100; i++) {
        printf("Sample %d: %d\n", i, stream->data[i]);
    }
}

int main() {
    AudioStream *stream = load_audio_stream("nonexistent_file.wav");
    if (!stream) {
        printf("Failed to load audio stream.\n");
        return 1;
    }

    decode_audio(stream);

    free(stream->data);
    free(stream);

    // Dereference invalid pointer to cause crash
    int *invalid_ptr = (int *)0xdeadbeef;
    printf("%d\n", *invalid_ptr); // This will cause a segmentation fault

    return 0;
}
