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

    // Simulate decoding process
    int* decodedData = stream->data;
    if (decodedData == NULL) {
        printf("Error: Decoded data is null\n");
        return;
    }

    // Dereference null pointer to cause crash
    int value = *decodedData; // This will cause a segmentation fault
}

int main() {
    AudioStream stream;
    stream.data = NULL;

    decodeAudio(&stream);

    return 0;
}
