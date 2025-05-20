#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

typedef struct AudioStream {
    int* buffer;
    size_t size;
} AudioStream;

void decodeAudio(AudioStream* stream) {
    // Simulate decoding process
    for (size_t i = 0; i < stream->size; i++) {
        printf("%d ", stream->buffer[i]);
    }
    printf("\n");
}

void initializeStream(AudioStream* stream, size_t size) {
    stream->buffer = (int*)malloc(size * sizeof(int));
    if (stream->buffer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    stream->size = size;
}

void playStream(AudioStream* stream, size_t offset) {
    if (offset >= stream->size) {
        fprintf(stderr, "Offset out of bounds\n");
        return;
    }
    AudioStream* temp = (AudioStream*)malloc(sizeof(AudioStream));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    temp->buffer = stream->buffer + offset;
    temp->size = stream->size - offset;

    decodeAudio(temp);

    free(stream->buffer); // Free original buffer
    stream->buffer = NULL; // Avoid dangling pointer

    free(temp); // Free temporary stream
}

int main() {
    AudioStream stream;
    initializeStream(&stream, BUFFER_SIZE);

    for (size_t i = 0; i < BUFFER_SIZE; i++) {
        stream.buffer[i] = i % 256; // Fill buffer with some values
    }

    playStream(&stream, 512); // Trigger use after free by accessing freed memory

    free(stream.buffer); // This should not have any effect

    return 0;
}
