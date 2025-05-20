#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
} AudioStream;

void decodeAudio(AudioStream* stream) {
    if (stream == NULL) {
        printf("Error: Stream is null\n");
        return;
    }

    // Simulate audio decoding
    int sample = *(stream->data);
    printf("Decoded sample: %d\n", sample);

    // Intentional null pointer dereference
    int* invalid_ptr = NULL;
    *invalid_ptr = 42; // This will cause a segmentation fault
}

int main() {
    AudioStream stream;
    stream.data = malloc(sizeof(int));
    if (stream.data == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    *stream.data = 10;

    decodeAudio(&stream);

    free(stream.data);
    return 0;
}
