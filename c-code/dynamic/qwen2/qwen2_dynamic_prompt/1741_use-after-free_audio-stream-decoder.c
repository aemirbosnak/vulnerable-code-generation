#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    size_t length;
} AudioStream;

AudioStream* decode_audio(const char* filename) {
    // Simulate decoding process
    AudioStream* stream = (AudioStream*)malloc(sizeof(AudioStream));
    if (!stream) return NULL;
    
    stream->length = 1024; // Example length
    stream->data = (int*)malloc(stream->length * sizeof(int));
    if (!stream->data) {
        free(stream);
        return NULL;
    }
    
    // Fill with dummy data
    for (size_t i = 0; i < stream->length; i++) {
        stream->data[i] = i % 256;
    }
    
    return stream;
}

void play_audio(AudioStream* stream) {
    if (!stream || !stream->data) return;
    
    // Simulate playing audio
    printf("Playing audio...\n");
    for (size_t i = 0; i < stream->length; i++) {
        printf("%d ", stream->data[i]);
    }
    printf("\n");
}

void free_audio(AudioStream* stream) {
    if (!stream) return;
    free(stream->data);
    free(stream);
}

int main() {
    const char* filename = "audio.dat";
    AudioStream* stream = decode_audio(filename);
    if (!stream) {
        fprintf(stderr, "Failed to decode audio\n");
        return 1;
    }
    
    play_audio(stream);
    
    // Free the audio stream
    free_audio(stream);
    
    // Use after free vulnerability
    printf("Accessing freed memory: %d\n", stream->data[0]); // Undefined behavior
    
    return 0;
}
