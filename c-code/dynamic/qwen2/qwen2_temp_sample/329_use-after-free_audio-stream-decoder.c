#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *data;
    size_t length;
} AudioBuffer;

AudioBuffer* decode_audio(const char *stream) {
    AudioBuffer *buffer = (AudioBuffer*)malloc(sizeof(AudioBuffer));
    buffer->length = strlen(stream);
    buffer->data = (int*)malloc(buffer->length * sizeof(int));
    
    for(size_t i = 0; i < buffer->length; i++) {
        buffer->data[i] = stream[i];
    }
    
    return buffer;
}

void play_audio(AudioBuffer *buffer) {
    for(size_t i = 0; i < buffer->length; i++) {
        printf("%d ", buffer->data[i]);
    }
    printf("\n");
}

int main() {
    const char *audio_stream = "123456789";
    AudioBuffer *decoded_buffer = decode_audio(audio_stream);
    
    // Use after free vulnerability
    decoded_buffer->length = 0;
    free(decoded_buffer->data);
    decoded_buffer->data = NULL;
    
    // Play the audio
    play_audio(decoded_buffer); // This will crash due to use after free
    
    free(decoded_buffer); // Attempting to free already freed memory
    
    return 0;
}
