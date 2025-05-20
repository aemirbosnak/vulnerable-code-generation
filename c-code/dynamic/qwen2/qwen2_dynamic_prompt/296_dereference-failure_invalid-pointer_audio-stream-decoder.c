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
    unsigned char *data;
} AudioStream;

AudioStream* decode_audio_stream(unsigned char *stream_data, size_t length) {
    AudioStream *audio = malloc(sizeof(AudioStream));
    if (!audio) return NULL;

    audio->sample_rate = 44100;
    audio->channels = 2;
    audio->data = malloc(length);
    if (!audio->data) {
        free(audio);
        return NULL;
    }

    // Simulate decoding process
    for (size_t i = 0; i < length; i++) {
        audio->data[i] = stream_data[i];
    }

    return audio;
}

void play_audio(AudioStream *audio) {
    if (!audio || !audio->data) return;

    // Simulate playing audio
    printf("Playing audio with sample rate %d Hz and %d channels...\n", audio->sample_rate, audio->channels);

    // Dereference invalid pointer to cause crash
    unsigned char *invalid_ptr = audio->data + BUFFER_SIZE;
    printf("%d\n", *invalid_ptr); // This will cause a segmentation fault
}

int main() {
    unsigned char stream_data[BUFFER_SIZE];
    for (size_t i = 0; i < BUFFER_SIZE; i++) {
        stream_data[i] = i % 256;
    }

    AudioStream *audio = decode_audio_stream(stream_data, BUFFER_SIZE);
    if (!audio) {
        fprintf(stderr, "Failed to decode audio stream.\n");
        return EXIT_FAILURE;
    }

    play_audio(audio);

    free(audio->data);
    free(audio);

    return EXIT_SUCCESS;
}
