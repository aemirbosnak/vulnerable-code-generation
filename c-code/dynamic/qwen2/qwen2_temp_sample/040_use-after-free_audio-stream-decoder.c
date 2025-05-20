#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t length;
} AudioStream;

AudioStream* decode_audio(const char *stream) {
    AudioStream *audio = (AudioStream*)malloc(sizeof(AudioStream));
    if (!audio) return NULL;

    // Simulate decoding process
    audio->length = 1024;
    audio->data = (int*)malloc(audio->length * sizeof(int));
    if (!audio->data) {
        free(audio);
        return NULL;
    }

    // Fill with dummy data
    for (size_t i = 0; i < audio->length; i++) {
        audio->data[i] = i % 256;
    }

    return audio;
}

void play_audio(AudioStream *audio) {
    if (!audio || !audio->data) return;

    // Simulate playing audio
    printf("Playing audio...\n");
    for (size_t i = 0; i < audio->length; i++) {
        printf("%d ", audio->data[i]);
    }
    printf("\n");

    // Free audio data
    free(audio->data);
}

int main() {
    const char *audio_stream = "dummy_stream";
    AudioStream *audio = decode_audio(audio_stream);

    if (audio) {
        play_audio(audio);
        // Use-after-free vulnerability here
        printf("Audio data: %d\n", audio->data[0]); // Accessing freed memory
    } else {
        printf("Failed to decode audio.\n");
    }

    return 0;
}
