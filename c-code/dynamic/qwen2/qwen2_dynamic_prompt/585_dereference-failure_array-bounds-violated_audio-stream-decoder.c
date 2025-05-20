#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct {
    int sample_rate;
    int channels;
    short *data;
} AudioStream;

AudioStream* decode_audio(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    AudioStream *stream = malloc(sizeof(AudioStream));
    if (!stream) {
        perror("Failed to allocate memory");
        fclose(file);
        return NULL;
    }

    fread(&stream->sample_rate, sizeof(int), 1, file);
    fread(&stream->channels, sizeof(int), 1, file);

    size_t data_size = BUFFER_SIZE * sizeof(short);
    stream->data = malloc(data_size);
    if (!stream->data) {
        perror("Failed to allocate memory for audio data");
        free(stream);
        fclose(file);
        return NULL;
    }

    size_t bytes_read = fread(stream->data, sizeof(short), BUFFER_SIZE, file);
    if (bytes_read != BUFFER_SIZE) {
        fprintf(stderr, "Error reading audio data\n");
        free(stream->data);
        free(stream);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return stream;
}

void play_audio(AudioStream *stream) {
    // Simulate playing audio by printing samples
    for (size_t i = 0; i < BUFFER_SIZE; i++) {
        printf("%d ", stream->data[i]);
    }
    printf("\n");
}

int main() {
    AudioStream *stream = decode_audio("audio.bin");
    if (stream) {
        play_audio(stream);
        free(stream->data);
        free(stream);
    }
    return 0;
}
