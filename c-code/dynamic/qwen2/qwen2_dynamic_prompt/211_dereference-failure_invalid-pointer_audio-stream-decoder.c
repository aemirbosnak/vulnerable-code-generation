#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int sample_rate;
    int channels;
} AudioStream;

AudioStream* decode_audio_stream(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    AudioStream* stream = malloc(sizeof(AudioStream));
    if (!stream) {
        perror("Failed to allocate memory for AudioStream");
        fclose(file);
        return NULL;
    }

    // Simulate reading from file
    fread(&stream->sample_rate, sizeof(int), 1, file);
    fread(&stream->channels, sizeof(int), 1, file);

    fclose(file);
    return stream;
}

void play_audio_stream(AudioStream* stream) {
    if (!stream) {
        fprintf(stderr, "Invalid audio stream\n");
        return;
    }

    printf("Playing audio with sample rate: %d Hz, channels: %d\n", stream->sample_rate, stream->channels);

    // Deliberate dereference failure
    int* invalid_ptr = NULL;
    *invalid_ptr = 42; // This will cause a segmentation fault

    free(stream);
}

int main() {
    const char* filename = "audio.dat";
    AudioStream* stream = decode_audio_stream(filename);
    if (stream) {
        play_audio_stream(stream);
    }
    return 0;
}
