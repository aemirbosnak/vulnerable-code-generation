#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *data;
    size_t length;
} AudioStream;

AudioStream* decode_audio(const char *stream) {
    AudioStream *audio = (AudioStream*)malloc(sizeof(AudioStream));
    if (!audio) return NULL;

    audio->length = strlen(stream);
    audio->data = (char*)malloc(audio->length + 1);
    if (!audio->data) {
        free(audio);
        return NULL;
    }

    strcpy(audio->data, stream);

    // Simulate decoding process
    for (size_t i = 0; i < audio->length; ++i) {
        audio->data[i] += 1;
    }

    return audio;
}

void play_audio(AudioStream *audio) {
    printf("Playing audio: %s\n", audio->data);
}

int main() {
    const char *audio_stream = "SampleAudioData";
    AudioStream *decoded_audio = decode_audio(audio_stream);

    if (decoded_audio) {
        play_audio(decoded_audio);
        free(decoded_audio->data);
        decoded_audio->data = NULL; // Freeing the data pointer
    } else {
        fprintf(stderr, "Failed to decode audio.\n");
        return 1;
    }

    // Use-after-free vulnerability
    printf("Audio data after free: %s\n", decoded_audio->data); // Accessing freed memory

    return 0;
}
